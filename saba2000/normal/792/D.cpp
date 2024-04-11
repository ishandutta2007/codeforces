#include<bits/stdc++.h>
using namespace std;
long long n,q,h,m,u,z[10000],t;
string s;
void fp(long long l)
{long long k=1;
for (long long i=1; (1<<i)<=n+1; i++)
{if (l%(k*2)==(k)){h=i; //cout<<i<<" i"; 
m=(l-(k))/(2*k); return;} k=k*2;}
}
void go(long long p)
{if (p==s.size()) return;
//cout<<p<<" "<<h<<" "<<m<<endl;
if (h==1 && s[p]!='U') {go(p+1); return;}
if (h==t && s[p]=='U') {go(p+1); return;}
if (s[p]=='L') {h--; m=2*m;}
if (s[p]=='R') {h--; m=2*m+1;}
if (s[p]=='U') {h++; m=m/2;}
go(p+1);}
main()
{
cin>>n>>q; t=0; long long k=1;
while(k<n+1) {z[t+1]=2*k; k=2*k; t++;}
//for (long long i=1; i<=t; i++)
//out<<z[i]<<" "; cout<<endl;
for (long long i=0; i<q; i++)
{cin>>u>>s;
fp(u);
go(0); //cout<<h<<" "<<m<<endl;
cout<<z[h]*m+z[h]/2<<endl;
}
}