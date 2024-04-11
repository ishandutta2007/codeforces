#include<iostream>
using namespace std;
string s,p,q;
int n,m;
main()
{cin>>s;
p=s;
q=s;
for (int i=1; i<s.length(); i++)
if (s[i]==s[i-1]) 
{if(s[i-1]!='a' && s[i+1]!='a') s[i]='a'; else
if(s[i-1]!='b' && s[i+1]!='b') s[i]='b'; else
s[i]='c';
}
cout<<s<<endl;
}