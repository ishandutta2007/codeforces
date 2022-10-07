#include<iostream>
#include<cmath>
using namespace std;
int n,k,g,t;
main()
{
string s;

cin>>n>>k;
cin>>s;
for (int i=0 ;i<s.length(); i++)
if (s[i]=='G') g=i; else if (s[i]=='T') t=i;

if (abs(t-g)%k!=0) {cout<<"NO"<<endl; return 0;}
for (int i=g; i<=t; i+=k)
if (s[i]=='#') {cout<<"NO"<<endl; return 0;}
for (int i=g; i>=t; i-=k)
if (s[i]=='#') {cout<<"NO"<<endl; return 0;}
cout<<"YES"<<endl;
//system("pause");
}