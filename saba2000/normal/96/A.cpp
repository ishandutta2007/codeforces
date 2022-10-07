#include <iostream>
#include <string>
using namespace std;
int main ()
{
string s;
cin>>s;
int a0=0,a1=0,a=0;
for (int i=0; i<s.length (); i++)
{
if (s[i]=='0') {a0++; a1=0;}
if (s[i]=='1') {a1++; a0=0;}
if (a1==7) a=1;
if (a0==7) a=1;
}
if (a==1) cout<<"YES";
else cout<<"NO";
return 0;
}