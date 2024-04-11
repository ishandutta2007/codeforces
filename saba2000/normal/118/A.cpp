#include <iostream>
#include <string>
using namespace std;
int main()
{
string s; int a=0,m;
cin>>s;
while (a<=s.length()-1)
{m=(int)s[a];
if (m<93) s[a]=(char)m+32;
a++;}
a=0;
while (a<=s.length()-1)
{if (s[a]!='a' && s[a]!='e' && s[a]!='i' && s[a]!='o' && s[a]!='u' && s[a]!='y' && s[a]!='A' && s[a]!='E' && s[a]!='I' && s[a]!='O' && s[a]!='U' && s[a]!='Y')
cout<<"."<<s[a]; a++;}
return 0;
}