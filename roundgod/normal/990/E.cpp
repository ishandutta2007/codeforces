/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-10 18:53:27
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2000005
#define INF 1000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,m,k;
ll a[MAXN],pre[MAXN],nxt[MAXN];
bool block[MAXN];
int main()
{
    scanf("%lld%lld%lld",&n,&m,&k);
    memset(block,false,sizeof(block));
    for(ll i=1;i<=m;i++)
    {
        ll x;
        scanf("%lld",&x);
        block[x]=true;
    }
    for(ll i=1;i<=k;i++)
        scanf("%lld",&a[i]);
    if(block[0])
    {
        puts("-1");
        return 0;
    }
    for(ll i=1;i<=2*n;i++)
        pre[i]=block[i-1]?pre[i-1]:i-1;
    ll maxi=1;
    for(ll i=1;i<=n;i++)
        maxi=max(maxi,i-pre[i]);
    ll ans=INF;
    for(ll i=maxi;i<=k;i++)
    {
        ll now=0,cnt=0;
        bool f=true;
        while(now<n)
        {
            now+=i;
            cnt+=a[i];
            if(block[now]) now=pre[now];
        }
        ans=min(ans,cnt);
    }
    if(ans==INF) puts("-1"); else printf("%lld\n",ans);
    return 0;
}