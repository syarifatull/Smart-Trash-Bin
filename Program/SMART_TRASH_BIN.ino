//menamai objek servo sebagai pengontrol servo
#include<Servo.h> 
//variabel penyimpan posisi servo 
Servo myservo;
//mendefinisikan pin sensor ultrasonik 1 & 2
int pinTrig2 = 7; 
int pinEcho2 = 6; 
int pinTrig = 5; 
int pinEcho = 4; 
//mendefinisikan pin buzzer
int buzzer = 2;  

void openclose() 
{
  long duration, inches, cm; // durasi perjalanan sinyal ultrasonik dalam inci, sentimeter
  digitalWrite(pinTrig, LOW); // mengaktifkan pin trigger sensor ultrasonik 1 dengan memberikan sinyal LOW ke HC-SR04 
  
  delayMicroseconds(2); //dengan delay 2 microsecond
  digitalWrite(pinTrig, HIGH); // mengaktifkan pin trigger sensor ultrasonik 1 dengan memberikan sinyal HIGH
  
  delayMicroseconds(10); //dengan delay 10 microsecond

  digitalWrite(pinTrig, LOW); // membaca waktu yang diperlukan sinyal ultrasonic dari sensor ultrasonik 1
  // kembali ke receiver pada sensor ultrasonik 1 dalam microsecond 
 
 duration = pulseIn(pinEcho,HIGH); // menghitung jarak berdasarkan waktu perjalanan sinyal ultrasonik 1
 cm = duration / 29 / 2;  // ubah ke cm  
 // cm = jarak
 if(cm <  30 )   // jika jarak terdeteksi sensor ultrasonik 1 kurang dari 30 cm
 { 
  myservo.write(90);  //servo bergerak 90 derajat dengan arah berlawanan jarum jam
  delay(2000);  //dengan delay 2000 ms
  } 
  else  // jika tidak terdeteksi lagi maka servo akan kembali ke posisi semula
  { 
    myservo.write(0); 
    delay(500); //dengan delay 500 ms
    } 
    }
    void ligthing() 
    { 
      digitalWrite(buzzer,HIGH); // memberikan sinyal high pada buzzer 
      digitalWrite(8,HIGH);  // memberikan sinyal high pada port/pin 8 
      digitalWrite(9,HIGH);  // memberikan sinyal high pada port/pin 9 
      delay(300);    // dengan delay 300 ms
      digitalWrite(8,LOW);  // memberikan sinyal low pada port/pin 8 
      digitalWrite(9,LOW);  // memberikan sinyal low pada port/pin 9  
      delay(300);    //  dengan delay 300 
      } void setup () 
      { 
        Serial.begin(9600);  // membuka serial port, kecepatan data diatur ke 9600 bps  
        pinMode(pinTrig2,OUTPUT); // menjadikan pin trigger pada sensor ultrasonik 2 menjadi output 
        pinMode(pinEcho2,INPUT); // menjadikan pin echo pada sensor ultrasonik 2 menjadi input 
        pinMode(8,OUTPUT);  // menjadikan pin 8 menjadi output 
        pinMode(9,OUTPUT);  // menjadikan pin 9 menjadi output  
        pinMode(buzzer,OUTPUT);  // menjadikan buzzer menjadi output 
        pinMode(pinTrig,OUTPUT); // menjadikan pin trigger menjadi output 
        pinMode(pinEcho,INPUT); // menjadikan pin echo menjadi input 
        myservo.attach(3);  // servo diletakkan pada pin digital 3 arduino
        }   
void loop() { long duration2,distance2; // durasi perjalanan sinyal ultrasonik ke 2 dan jarak ke 2 
 
digitalWrite(pinTrig2,LOW); // memberikan sinyal low pada pin trigger sensor ultrasonik 2
 
delayMicroseconds(2);  // dengan delay 2 microsecond
digitalWrite(pinTrig2,HIGH); // memberikan sinyal high pada pin trigger sensor ultrasonik 2
delayMicroseconds(10);  // dengan delay 10 microseconds
digitalWrite(pinTrig2,LOW); // memberikan sinyal low pada pin trigger sensor ultrasonik 2
digitalWrite(buzzer,LOW); // memberikan sinyal low pada buzzer 
duration2 = pulseIn(pinEcho2,HIGH); // menghitung jarak 2 berdasarkan  waktu perjalanan sinyal ultrasonik 2
distance2 = duration2 /29 /2; // jarak ke 2 sama dengan durasi  ke 2, ubah ke cm     
if (distance2 > 3)  // jika jarak yang dideteksi sensor ultrasonik 2 lebih besar dari 3  cm
{ 
openclose();   //maka akan membuka
} 
else     // jika tidak 
{ 
myservo.write(0);   // maka servo tidak bergerak
ligthing();     
digitalWrite(buzzer,LOW);  // memberikan sinyal low pada buzzer 
} 
}
