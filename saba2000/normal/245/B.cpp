#include <iostream>
#include <string>
using namespace std;
int main ()
{string a; int i;
cin>>a;
if (a[0]=='f') {cout<<"ftp://"; i=4;} else {cout<<"http://"; i=5;} cout<<a[i-1];
while(a[i]!='r' || a[i+1]!='u') {cout<<a[i];i++;}
cout<<".ru"; i+=2; 
if (i!=a.length()) {cout<<"/"; for (i;i<a.length();i++)cout<<a[i];}
cout<<endl;
return 0;
}