/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-15 11:30:55
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,tot,t,now;
ll a[MAXN],sum[MAXN];
ll dp[MAXN];
P st[MAXN];
ll get(P u,P v) {return (v.S-u.S)/(u.F-v.F);}
void add(ll u,ll v)
{
    P p=P(u,v);
    while(t-now>1&&get(st[t-1],p)<=get(st[t-1],st[t-2])) t--;
    st[t++]=p;
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
    return st[r].F*x+st[r].S;
}
int main()
{
    scanf("%lld",&n);
    ll ans=-INF,s=0;
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(ll i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for(ll i=1;i<=n;i++) s+=i*a[i];
    ans=max(ans,s);
    //printf("%lld\n",ans);
    for(ll i=2;i<=n;i++)
    {
        add(i-1,-sum[i-2]);
        while(t-now>1&&get(st[now],st[now+1])<a[i]) now++;
        dp[i]=query(a[i])+sum[i-1]-i*a[i];
        ans=max(ans,s+dp[i]);
    }
    //printf("%lld\n",ans);
    t=0;now=0;
    for(ll i=n-1;i>=1;i--)
    {
        add(-(i+1),-sum[i+1]);
        while(t-now>1&&get(st[now],st[now+1])<a[i]) now++;
        dp[i]=query(-a[i])-i*a[i]+sum[i];
        ans=max(ans,s+dp[i]);
    }
    printf("%lld\n",ans);
    return 0;
}