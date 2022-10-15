/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-04 15:18:39
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,m,x,a[MAXN],b[MAXN],suma[MAXN],sumb[MAXN];
ll maxa[MAXN],maxb[MAXN];
int main()
{
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(ll i=1;i<=m;i++) scanf("%lld",&b[i]);
    scanf("%lld",&x);
    for(ll i=1;i<=n;i++) suma[i]=suma[i-1]+a[i];
    for(ll i=1;i<=m;i++) sumb[i]=sumb[i-1]+b[i];
    for(ll i=1;i<=n;i++) maxa[i]=INF;
    for(ll i=1;i<=m;i++) maxb[i]=INF;
    for(ll i=1;i<=n;i++)
        for(ll l=1;l+i-1<=n;l++)
            maxa[i]=min(maxa[i],suma[l+i-1]-suma[l-1]);
    for(ll i=1;i<=m;i++)
        for(ll l=1;l+i-1<=m;l++)
            maxb[i]=min(maxb[i],sumb[l+i-1]-sumb[l-1]);
    ll ans=0;
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=m;j++)
            if(maxa[i]*maxb[j]<=x) ans=max(ans,i*j);
    printf("%lld\n",ans);
    return 0;
}