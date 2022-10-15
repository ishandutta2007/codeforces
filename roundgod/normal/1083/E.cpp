/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-12-11 01:44:48
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,dp[MAXN];
struct rect
{
    ll x,y,a;
};
rect f[MAXN];
bool cmp(rect p,rect q)
{
    return p.y>q.y;
}
ll N,tot,t,now;
P st[MAXN];
ll get(P u,P v) {return (v.S-u.S)/(u.F-v.F);}
void add(ll u,ll v)
{
    P p=P(u,v);
    while(t-now>1&&get(st[t-1],p)>=get(st[t-1],st[t-2])) t--;
    st[t++]=p;
}
bool cmp2(P x,P y)
{
    if(x.S!=y.S) return x.S<y.S;
    return x.F<y.F;
}
ll query(ll x)
{
    ll l=-1,r=t-1;
    while(r-l>1)
    {
        ll mid=(l+r)/2;
        if(st[mid].F*x+st[mid].S<=st[mid+1].F*x+st[mid+1].S) l=mid;
        else r=mid;
    }
    //printf("%lld %lld\n",st[r].F,st[r].S);
    return st[r].F*x+st[r].S;
}
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++) scanf("%lld%lld%lld",&f[i].x,&f[i].y,&f[i].a);
    sort(f+1,f+n+1,cmp);
    add(0,0);dp[0]=0;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        dp[i]=query(f[i].y)+f[i].x*f[i].y-f[i].a;
        //printf("%lld %lld\n",t,dp[i]);
        ans=max(ans,dp[i]);
        add(-f[i].x,dp[i]);
    }
    printf("%lld\n",ans);
    return 0;
}