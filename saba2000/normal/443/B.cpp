#include<iostream>
#include<string>
using namespace std;
int main (){
string s;int k=0,m,d=0,l;
cin>>s>>k; l=s.length();
for (int i=l; i<l+k; i++)
{ s=s+'.';}
for (int i=s.length()/2; i>=1; i--)
for (int j=0; j<s.length()-i; j++)
{m=0; for (int t=j; t<j+i; t++)
if (s[t]==s[t+i] || s[t+i]=='.') m++;
if (m==i) {cout<<i*2<<endl;
return 0;}}
}