#include <iostream>
#include <string>
using namespace std;
int main ()
{string s;cin>>s; int k=0;
for (int i=1; i<s.length();i++)
if (s[i]>=97) k=1;
if (k==1) cout<<s<<endl;
else for (int i=0; i<s.length(); i++)
if (s[i]>=97) cout<<(char)(s[i]-32); else cout<<(char)(s[i]+32);cout<<endl;
return 0;
}