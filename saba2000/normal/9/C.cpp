#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int main ()
{string k;
int m=0,n=1,s=0,p=0;
cin>>k; m=pow(2,(double)k.length()-1)-1;
if (k[0]>'1') s=1;
for (int i=1; i<k.length(); i++)
{if (k[i]>'1') s=1; 
if (s==1 ) n*=2;
if (k[i]=='1' && s==0) m+=pow(2,(double)k.length()-1-i);
}
cout<<m+n;
return 0;
}