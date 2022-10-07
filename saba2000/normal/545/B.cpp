#include <iostream>
#include <string>
using namespace std;
int main ()
{string s,t; int n=0;
cin>>s>>t;
for (int i=0; i<s.length(); i++)
if (s[i]!=t[i]) n++;
if (n%2==1) cout<<"impossible"<<endl; else
for (int i=0; i<s.length(); i++)
{if (n%2==0) cout<<s[i]; else cout<<t[i];
if (s[i]!=t[i]) n--;
}
cout<<endl;
return 0;
}