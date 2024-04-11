#include <iostream>
#include <string>
using namespace std;
int main ()
{
string s; int noU=0,noL=0,tc1,tc2,tg;
cin>>s;
for (int i=0; i<s.length(); i++)
{if (s[i]<97) noU++; else noL++;}
if (noL>=noU) {tc1=64; tc2=97; tg=32;}
else {tc1=96; tc2=130; tg=-32;}
for (int i=0; i<s.length(); i++)
if (s[i]>tc1 && s[i]<tc2) s[i]+=tg;
cout<<s<<endl; 
//system ("pause");
return 0;
}