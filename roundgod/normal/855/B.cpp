#include<bits/stdc++.h>
#define MAXN 100020
#define INF 4000000000000000000
using namespace std;
typedef long long ll;
ll n,p,q,r;
ll a[MAXN];
ll lmax[MAXN],rmax[MAXN],lmin[MAXN],rmin[MAXN];
int main()
{
    scanf("%I64d %I64d %I64d %I64d",&n,&p,&q,&r);
    for(int i=0;i<n;i++)
        scanf("%I64d",&a[i]);
    for(int i=0;i<n;i++)
    {
        if(i==0) lmax[i]=lmin[i]=a[i];
        else lmax[i]=max(a[i],lmax[i-1]),lmin[i]=min(a[i],lmin[i-1]);
    }
    for(int i=n-1;i>=0;i--)
    {
        if(i==n-1) rmax[i]=rmin[i]=a[i];
        else rmax[i]=max(a[i],rmax[i+1]),rmin[i]=min(a[i],rmin[i+1]);
    }
    ll ans=-INF;
    for(int i=0;i<n;i++)
    {
        ll res=0;
        res+=q*a[i];
        if(p>0) res+=p*lmax[i]; else res+=p*lmin[i];
        if(r>0) res+=r*rmax[i]; else res+=r*rmin[i];
        ans=max(ans,res);
    }
    printf("%I64d\n",ans);
    return 0;
}