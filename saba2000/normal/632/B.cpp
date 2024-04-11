#include<iostream>
using namespace std;
main()
{long long n,p[543210],B,A,ans,a,b;
string s;
cin>>n;
for (int i=0; i<n; i++)
cin>>p[i];
cin>>s;
for (int i=0; i<n; i++)
if (s[i]=='B') B+=p[i];
else A+=p[i];
ans=B;
a=A; b=B;
for (int i=0; i<n; i++)
{if (s[i]=='A') {A-=p[i]; B+=p[i]; ans=max(ans,B);}
else{B-=p[i]; A+=p[i];}}
B=b; A=a;
for (int i=n-1; i>=0; i--)
{if (s[i]=='A') {A-=p[i]; B+=p[i]; ans=max(ans,B);}
else{B-=p[i]; A+=p[i];}}
cout<<ans<<endl;
}