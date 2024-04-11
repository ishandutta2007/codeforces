#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
const ll inv2=(MOD+1)/2;
ll a[MAXN],d,b[MAXN],s[MAXN],t[MAXN],c[MAXN],ans;
int n,tt;
ll pow_(ll x,ll y)
{
    ll res=1;
    while (y)
    {
        if (y&1) res=res*x%MOD;
        x=x*x%MOD;
        y>>=1;
    }
    return res;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++) s[i]=1,t[i]=1; 
    d=n;
    for(int i=n;i;i--)
    {
        if(a[i]!=-1)
        {
            tt=a[i]-1; while(tt) ans+=b[tt],tt-=tt&(-tt);
            tt=a[i]; while(tt<MAXN) b[tt]++,tt+=tt&(-tt);
            s[i]=0; d--; t[a[i]]=0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        s[i]+=s[i-1];
        t[i]+=t[i-1];
    }
    (ans+=d*(d-1)/2%MOD*inv2)%=MOD;
    ll inv=pow_(d,MOD-2);
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=-1)
        {
            (ans+=(s[i]*(d-t[a[i]])+(d-s[i])*t[a[i]])%MOD*inv)%=MOD;
        }
    }
    printf("%lld\n",ans);
    return 0;
}