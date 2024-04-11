#include <iostream>
#include <string>
using namespace std;
int main ()
{string s; int a=3;
cin>>s;
for (int i=0; i<1000; i+=8)
{if (i/100==0) {a--;
if (i/10%10==0) a--;}
for (int j=0; j<s.length(); j++)
if (a==3 && s[j]-48==i/100) a--; else
if (a==2 && s[j]-48==i/10%10) a--; else
if (a==1 && s[j]-48==i%10) a--;
if (a==0) {cout<<"YES"<<endl<<i<<endl; return 0;}
a=3;
}
cout<<"NO"<<endl;
return 0;
}