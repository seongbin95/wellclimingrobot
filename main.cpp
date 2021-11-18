#include "mbed.h"
#include "Servo.h"
#include "PwmIn.h"
#include <string> 

Servo myservo(p21);
Servo myservo2(p25);
PwmOut PWMout(p22);
PwmIn PWMin(p23);
PwmIn motorin(p24);
PwmOut BLmotorout(p26);
int main()
{
    PWMout.period(0.02);
    BLmotorout.period(0.02);
    int pwm;
    float p;
    float mo;
    int reuo;
    int remo;
    float uo;
    float w;
    float BLtest;
    
    PWMout = 0.09;
    /*
    myservo = 0.0;
    myservo2 = 0.0;
    wait(0.5);
    myservo = 1.0;
    myservo2 = 1.0;
    wait(8);
    myservo = 0.0;
    myservo2 = 0.0;
    wait(8);
    */
        //myservo = 0.0; //Motor off
        
    while(1)
    {
        pwm = PWMin.dutycycle()*10000;  
        mo = motorin.dutycycle();
        
        p = ((pwm *0.0001 - 0.05) * 2.5 + 0.04);  
        w = p;
        if(p < 0 || p > 0.2)                     
        {
            PWMout = 0.09;
            myservo = 0.01;
            myservo2 = 0.01;
            wait(2);
        }
        /*else if(pwm == 758 || pwm == 759 || pwm == 760 || pwm == 761 || pwm == 762)
        {
            PWMout = 0.09;
            myservo = 0.01;
            myservo2 = 0.01;
            wait(0.5);
        }
        */
        else 
        {
            
            if(w > 0.073)
            {
            BLmotorout = 0.95;
            BLtest = 1;
            }
            else
            {
            BLmotorout = 0.05;
            BLtest = 0;
            }
            
            PWMout = p;
            reuo = ((mo -0.05) * 22)*100;
            uo = reuo * 0.01;
            
            
            if(uo < 0 )
            {
            myservo = 0.01;
            myservo2 = 0.01;
            }
            else
            {
            myservo = uo;
            myservo2 = uo;
            }
            
        }
        printf("duty = %f,PWM = %i, PWMout = %f, mo = %f, uo = %f b = %f\n", PWMin.dutycycle(),pwm,p,mo,uo,BLtest);
        wait(0.0294);
    }
}
  //
