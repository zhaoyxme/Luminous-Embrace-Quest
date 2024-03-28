#include <Adafruit_PWMServoDriver.h>

#include <Servo.h> 
#include <Wire.h> 


char c = '0';

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);



#define SERVOMIN  123 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  492 // this is the 'maximum' pulse length count (out of 4096)
#define OPEN 492
#define CLOSE 123

int flag = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("16 airbags are ready");
  pwm.begin();
  pwm.setPWMFreq(50);
}

// a、b、c、d、e、f、g、h、i、j、k、l、m、n、o、p


void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    // read the incoming byte:
    c = Serial.read();

    //airbag open
    if(c>='a'&&c<='p'){
      Serial.print("airbag");
      Serial.print(c-'a'+1, DEC);
      Serial.println("open");
      flag = 1;
      //pwm.setPWM(c-'a', 0, SERVOMIN);
    }
  

    //airbag close
    if(c>='A'&&c<='P'){
      Serial.print("airbag");
      Serial.print(c-'A'+1, DEC);
      Serial.println("close");
      //pwm.setPWM(c-'a', 0, SERVOMAX);
      flag = 0;
      
    }

    


  }

  if(flag = 1)
    {
      pwm.setPWM(0, 0, SERVOMIN);
      pwm.setPWM(15, 0, SERVOMIN);
      delay(20);
    }
    else
    {
      pwm.setPWM(0, 0, SERVOMAX);
      pwm.setPWM(15, 0, SERVOMAX);
      delay(20);
    }

}
