#include<bits/stdc++.h>
using namespace std;
long long F(long long x, long long y, long long z, long long t, long long q)
{
if (z>y || t<x) return 0;
long long w=0;
if (z==t) return 1;
if (q%2==1 && (z+t)/2<=y && (z+t)/2>=x) w=1;
return F(x,y,z,(z+t)/2-1,q/2)+F(x,y,(z+t)/2+1,t,q/2)+w;
}
long long n,a,b,l,r;
int main()
{cin>>n>>l>>r;
if (n==0){ cout<<0<<endl; return 0;}
else if (n==1){ cout<<1<<endl; return 0;}
long long k=2;
while(k<=n)
k*=2;
cout<<F(l,r,1,k-1,n)<<endl;
}