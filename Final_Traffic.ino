// Signal Lights
int r[4] = {8,4,7,10};  //red

int g[4] = {3,6,9,12};  //green

int sPin=A0;
float val;
char p;
int data;
float mapval;

void setup() {
pinMode (1, OUTPUT);
pinMode (2, OUTPUT);
pinMode (3, OUTPUT);

pinMode (4, OUTPUT);
pinMode (5, OUTPUT);
pinMode (6, OUTPUT);

pinMode (7, OUTPUT);
pinMode (8, OUTPUT);
pinMode (9, OUTPUT);

pinMode (10, OUTPUT);
pinMode (11, OUTPUT);
pinMode (12, OUTPUT);
//Preset
digitalWrite(1,HIGH);
digitalWrite(2,LOW);
digitalWrite(3,LOW);
digitalWrite(4,HIGH);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
digitalWrite(10,HIGH);
digitalWrite(11,LOW);
digitalWrite(12,LOW);
pinMode(sPin,INPUT);
Serial.begin(9600);

}

//After input is detected
void interrupt(int a, int b)        //'b' is the current active signal 'a' is signal from where the interrupt occurs
{
  digitalWrite(g[b],LOW);           //Turning off signal b 
  digitalWrite(r[b],HIGH);          
  digitalWrite(g[a],HIGH);           //Turning on signal a
  digitalWrite(r[a],LOW);
  delay(5000);
  digitalWrite(1,HIGH);
digitalWrite(2,LOW);
digitalWrite(3,LOW);
digitalWrite(4,HIGH);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
digitalWrite(10,HIGH);
digitalWrite(11,LOW);
digitalWrite(12,LOW);
  //Serial.println("HI"); 
  loop(); 
}

void loop() { 

   
    for(int i=0; i<4; i++)
    {
      digitalWrite(g[i],HIGH);
      digitalWrite(r[i],LOW);
      p=Serial.read();
      if(p=='1') 
      { data=1;}
      else {data=0;}
      //Audio input
      val= analogRead(sPin);
      mapval= map(val,0,255,0,1000); //Mapped value
      int x= 2;
      //Serial.println(x);
      //Serial.println(mapval);
    
      for(int j=0; j<=500; j++)
      {
       
        if((data==1)&&(mapval>200))                          // 'x' is randomly generated signal number for demonstration of which signal is interrupted
        {
          interrupt(x,i);                                            
        }
        delay(10);                        //Output from IP is checked every two seconds
      }
     
      digitalWrite(g[i],LOW);
      digitalWrite(r[i],HIGH);
  
    }
  
 }
