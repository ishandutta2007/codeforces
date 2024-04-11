#include<iostream>
#include<stack>
using namespace std;
string s;
stack<char> c;
char a;
int q,ans;
main()
{
cin>>s;
for (int i=0; i<s.length(); i++){
if (s[i]=='(' || s[i]=='<' || s[i]=='[' || s[i]=='{') {c.push(s[i]); q=1;} else{
if (q==0) {cout<<"Impossible"<<endl; return 0;} 
a=c.top(); c.pop(); if(c.size()==0) q=0;  else if (c.top()=='(' || c.top()=='<' || c.top()=='[' || c.top()=='{') q=1; else q=0;
if (a=='(' && s[i]!=')') ans++;
if (a=='[' && s[i]!=']') ans++;
if (a=='{' && s[i]!='}') ans++;
if (a=='<' && s[i]!='>') ans++;
}
}
if (c.size()==0)
cout<<ans<<endl; else cout<<"Impossible"<<endl;
}