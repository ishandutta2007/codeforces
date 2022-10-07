#include <iostream>
#include <string>
using namespace std;
int main ()
{string s; int k,an=0,m;
cin>>s>>k; m=s.length()/k;
if (s.length()%k!=0) cout<<"NO"<<endl; else
{for (int i=0;i<s.length(); i++)
if (s[i]!=s[i+m-i%m-i%m-1]) an=1;
if (an==0) cout<<"YES"<<endl; else cout<<"NO"<<endl;}
return 0;
}