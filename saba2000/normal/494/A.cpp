#include<string>
#include<iostream>
using namespace std;
int k[123456],a,b,c,p,t,q,r;
main()
{string s;
cin>>s;
for (int i=0; i<s.length(); i++)
{if(s[i]=='#') p++; 
if (s[i]=='(') t++;}
q=s.length()-p-t;
for (int i=0; i<s.length(); i++)
{if (s[i]=='#') {c++; if (c==p) k[c]=t-q-r; else k[c]=1; b+=k[c]; r+=k[c];} else
if (s[i]=='(') a++; else
b++;
if (k[c]<=0 && c>0 || b>a) {cout<<-1<<endl; return 0;}
}
for (int i=1; i<=p; i++)
cout<<k[i]<<endl;
}