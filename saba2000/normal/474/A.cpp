#include <iostream>
#include <string>
using namespace std;
int main ()
{
string k="qwertyuiopasdfghjkl;zxcvbnm,./";
string s;
char r;
cin>>r;
cin>>s;
int i=0,l=0,z=0;
while (i<s.length())
{while (l<k.length())
{if (s[i]==k[l] && r=='R') cout<<k[l-1];
if (s[i]==k[l] && r=='L') cout<<k[l+1];
l++;
}
i++;
l=0;
}
cout<<endl;
return 0;
}