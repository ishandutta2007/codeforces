#include <string> 
#include <iostream>
using namespace std;
int main ()
{string a,b; 
cin>>a>>b;
for (int i=0; i<a.length(); i++)
{if (a[i]>91) a[i]=a[i]-32;
if (b[i]>91) b[i]=b[i]-32;
if (a[i]>b[i]) {cout<<1<<endl; return 0;}
if (a[i]<b[i]) {cout<<-1<<endl; return 0;}
}
cout<<0<<endl;
return 0;
}