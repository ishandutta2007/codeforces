/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-11 22:53:16
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,h[MAXN],sum[MAXN],cnt[MAXN];
int main()
{
    scanf("%lld%lld",&n,&k);
    ll minx=INF,mx=0;
    for(ll i=1;i<=n;i++) {scanf("%lld",&h[i]); minx=min(minx,h[i]); mx=max(mx,h[i]); cnt[h[i]]++;}
    ll now=0;
    for(ll i=200000;i>=1;i--)
    {
        now+=cnt[i];
        sum[i]=sum[i+1]+now;
    }
    ll cur=mx,ans=0;
    while(cur>minx)
    {
        ll l=1,r=cur;
        while(r-l>1)
        {
            ll mid=(l+r)/2;
            if(sum[cur-mid+1]-sum[cur+1]<=k) l=mid; else r=mid;
        }
        cur-=l;ans++;
    }
    printf("%lld\n",ans);
    return 0;
}