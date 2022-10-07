#include <iostream>
#include <string>
using namespace std;
int main ()
{long long  a=0,b=0,w=0;
string s;
cin>>s; 
while (s[w]!='^') w++;
for (int i=0; i<w; i++)
if (s[i]!='=') a+=(s[i]-48)*(w-i);
for (int i=w+1; i<s.length(); i++)
if (s[i]!='=') b+=(s[i]-48)*(i-w);
if (a==b) cout<<"balance"<<endl; else
if (a>b) cout<<"left"<<endl; else
cout<<"right"<<endl;
return 0;
}