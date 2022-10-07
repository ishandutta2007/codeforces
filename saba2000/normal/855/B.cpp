#include<bits/stdc++.h>
using namespace std;
long long p,q,r;
long long a[100009];
long long T[1000009],T1[1000009];
void build(long long x, long long l, long long r)
{
    if(l==r)
    {
        T[x]=a[l];
        return;
    }
    long long d=(l+r)/2;
    build(2*x+1,l,d);
    build(2*x+2,d+1,r);
    T[x]=max(T[2*x+1],T[2*x+2]);
}
long long cnt(long long x, long long l, long long r, long long a, long long b)
{
   // cout<<x<<" "<<l<<" "<<r<<endl;
    if(l>=a && r<=b) return T[x];
    if(l>b || r<a) return -1000000000;
    long long d=(l+r)/2;
    return max(cnt(2*x+1,l,d,a,b),cnt(2*x+2,d+1,r,a,b));
}
void build1(long long x, long long l, long long r)
{
    if(l==r)
    {
        T1[x]=a[l];
        return;
    }
    long long d=(l+r)/2;
    build1(2*x+1,l,d);
    build1(2*x+2,d+1,r);
    T1[x]=min(T1[2*x+1],T1[2*x+2]);
}
long long cnt1(long long x, long long l, long long r, long long a, long long b)
{
   // cout<<x<<" "<<l<<" "<<r<<endl;
    if(l>=a && r<=b) return T1[x];
    if(l>b || r<a) return 1000000000;
    long long d=(l+r)/2;
    return min(cnt1(2*x+1,l,d,a,b),cnt1(2*x+2,d+1,r,a,b));
}
main()
{long long n;
cin>>n>>p>>q>>r;
for (long long i=0; i<n; i++)
    cin>>a[i];
build(0,0,n-1);
build1(0,0,n-1);
long long ans=a[0]*(p+q+r);
for (long long i=0; i<n; i++)
{
    long long A=cnt(0,0,n-1,0,i);
    long long b=cnt1(0,0,n-1,0,i);
    long long a1=cnt(0,0,n-1,i,n-1);
    long long b1=cnt1(0,0,n-1,i,n-1);
    long long e=max(A*p,b*p),f=max(a1*r,b1*r);
    ans=max(ans,e+f+q*a[i]);
}
cout<<ans<<endl;
}