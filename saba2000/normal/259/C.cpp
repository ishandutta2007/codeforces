#include <iostream>
#include <string>
using namespace std;
int main ()
{string s; int k=0;
cin>>s;
for (int i=0; i<s.length(); i++)
if (s[i]=='0') {s[i]='2'; k=1; break;} 
if (k==0) s[0]='2';
for (int i=0; i<s.length(); i++)
if (s[i]!='2') cout<<s[i];
return 0;
}