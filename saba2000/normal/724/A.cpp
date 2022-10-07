#include<iostream>
using namespace std;
string x[7]={"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
int y[3]={0,2,3};
string a,b;
int a1,b1;
main()
{cin>>a>>b;
for (int i=0; i<7; i++)
{if (a==x[i]) a1=i;
if (b==x[i]) b1=i;}
for (int i=0; i<3; i++)
if ((a1+y[i])%7==b1) {cout<<"YES"<<endl; return 0;}
cout<<"NO"<<endl;

}