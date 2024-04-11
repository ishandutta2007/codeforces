#include<bits/stdc++.h>
using namespace std;
long long a[100009],b[100009];
long long f[100009],n;
void upd(long long z, long long d)
{
    while(z<=n)
    {
        f[z]+=d;
        z+=(z&-z);
    }
}
long long re(long long a, long long b)
{
    long long s1=0,s2=0;
    a--;
    while(a>0)
    {
        s1+=f[a];
        a-=(a&-a);
    }
    while(b>0)
    {
        s2+=f[b];
        b-=(b&-b);
    }
    return s2-s1;
}
vector<long long> v[100009];
vector<long long> z[100009];
main()
{cin>>n;
for (long long i=1; i<=n; i++){
    cin>>a[i];
    b[i]=a[i];
    v[a[i]].push_back(n+1-i);}

    sort(b+1,b+n+1);// x+1..n-1  0..x
    long long x=n; long long s=0;
    long long ans=0;
    for (long long i=1; i<=n; i++)
        upd(i,1);
for (long long i=1; i<=n; i++)
{
    //cout<<x<<" "<<ans<<endl;
    if(x==0) x=n;
    if(b[i]==b[i-1]) continue;
    long long y=b[i];
    reverse(v[y].begin(),v[y].end());
    long long R;
    if(v[y][v[y].size()-1]<=x) R=v[y][0];
    else
    {
        long long l=0,r=v[y].size()-1;
        while(l<r)
        {
            long long mid=(l+r)/2;
            if(v[y][mid]<=x) l=mid+1;
            else r=mid;
        }
        R=v[y][l];
    }
    //cout<<R<<endl;
    if(R<=x) { ans+=re(R,x); x=R-1;}
    else {ans+=re(1,x)+re(R,n); x=R-1;}
    for (long long i=0; i<v[y].size(); i++)
        upd(v[y][i],-1);
}
cout<<ans<<endl;
}