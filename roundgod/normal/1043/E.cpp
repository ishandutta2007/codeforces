/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-29 00:31:46
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,m;
ll x[MAXN],y[MAXN];
P a[MAXN];
ll ans[MAXN];
ll fin[MAXN];
ll pre[MAXN],suf[MAXN];
int main()
{
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld%lld",&x[i],&y[i]);
        a[i]=P(x[i]-y[i],i);
    }
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++) pre[i]=pre[i-1]+x[a[i].S];
    for(ll i=n;i>=1;i--) suf[i]=suf[i+1]+y[a[i].S];
    for(ll i=1;i<=n;i++)
    {
        ans[i]=pre[i-1]+suf[i+1]+(i-1)*y[a[i].S]+(n-i)*x[a[i].S];
    }
    for(ll i=1;i<=n;i++) fin[a[i].S]=ans[i];
    for(ll i=1;i<=m;i++)
    {
        ll u,v;
        scanf("%lld%lld",&u,&v);
        if(x[u]-y[u]<=x[v]-y[v]) 
        {
            fin[u]-=x[u]+y[v];
            fin[v]-=x[u]+y[v];
        }
        else
        {
            fin[u]-=x[v]+y[u];
            fin[v]-=x[v]+y[u];
        }
    }
    for(ll i=1;i<=n;i++) printf("%lld ",fin[i]);
    return 0;
}