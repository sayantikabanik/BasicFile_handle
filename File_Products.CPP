#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
class shop
{
int sno;
char name[50];
int p;
public:
void getdata() //To get get from user
{
cout<<"Enter Serial number of the product\t\n";
cin>>sno;
cout<<"Enter Name of the product"<<endl;
gets(name);
cout<<"Enter the price of the product"<<endl;
cin>>p;
}
void putdata() //To show data
{
cout<<"Serial Number:"<<sno<<endl;
cout<<"Name:"<<name<<endl;
cout<<"Price:"<<p<<endl;
}
int getsno()//Accessor function
{
return sno;
}
}; //End of class
void main()   //Starting of main
{
clrscr();
cout<<"Enter the details :"<<endl;
shop t; //Object of class shop
fstream f;
char ch='y';
f.open("Shop.dat",ios::out|ios::binary);
while(ch=='y')
{
t.getdata();
f.write((char*)&t,sizeof(t));
cout<<"Do you want to enter more products ?(y/n)"<<endl;
cin>>ch;
}
f.close();
int k;
do
{
cout<<"************** Menu Driven Program ***********"<<endl;
cout<<"\t\t1>Add a product"<<endl;
cout<<"\t\t2>Search for a product"<<endl;
cout<<"\t\t3>Delete a product"<<endl;
cout<<"\t\t4>Modify a product"<<endl;
cout<<"\t\t5>Display all the products"<<endl;
cout<<"\t\t6>Exit"<<endl;
cout<<"Choose an option from the menu"<<endl;
cin>>k;
if(k==1)//Adds a product
{
f.open("Shop.dat",ios::app|ios::binary);
cout<<"Enter details to be added"<<endl;
char c='y';
while(c=='y')
{
t.getdata();
f.write((char*)&t,sizeof(t));
cout<<"Do you want to add more products ? (y/n)"<<endl;
cin>>c;
}
f.close();
}
else if (k==2)//searches for a product
{
int s;
cout<<"Enter serial number to be searched";
cin>>s;
int j;
f.open("Shop.dat",ios::in|ios::binary);
f.seekg(0,ios::beg);
while(!f.eof())
{
f.read((char*)&t,sizeof(t));
if(t.getsno()==s)
{
t.putdata();
j=-1;
}
}
if(j==0)
cout<<"Serial Number not found";
f.close();
}
else if(k==3) //Deletes a product
{
fstream f1;
f.open("Shop.dat",ios::in|ios::binary);
f1.open("temp.dat",ios::out|ios::binary);
f.seekg(0,ios::beg);
int n;
cout<<"Enter the serial number of the product which is to be Deleled"<<endl;
cin>>n;
while(!f.eof())
{
f.read((char*)&t,sizeof(t));
if(t.getsno()==n)
{
cout<<"Serial number found and deleted"<<endl;
}
else
f1.write((char*)&t,sizeof(t));
}
f.close();
f1.close();
remove("Shop.dat");
rename("temp.dat","Shop.dat");
}
else if(k==4)//Modifies a product
{
int no;
cout<<"Enter the serial number of the product which is to be modified ";
cin>>no;
f.open("Shop.dat",ios::in|ios::out|ios::binary);
f.seekg(0,ios::beg);
int pos;
while(!f.eof())
{
pos=f.tellg();
f.read((char*)&t,sizeof(t));
if(t.getsno()==no)
{
cout<<"Enter the new data for this product"<<endl;
t.getdata();
f.seekg(pos);
f.write((char*)&t,sizeof(t));
}
}
f.close();
}
else if(k==5)//Displays the details of all the product
{
f.open("Shop.dat",ios::in|ios::binary);
f.seekg(0,ios::beg);
while(!f.eof())
{
f.read((char*)&t,sizeof(t));
t.putdata();
}
f.close();
}
else if(k==6)
{
exit(0);
}
else

{
cout<<"!!!  Wrong Choice  !!! " ;
}
cout<<"Do you want to try again ?(y\n)";
cin>>ch;
}
while(ch=='y');
getch();
}