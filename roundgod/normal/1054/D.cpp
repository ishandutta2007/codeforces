/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-19 00:58:51
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
ll n,k,a[MAXN];
map<ll,ll> mp;
int main()
{
    scanf("%lld%lld",&n,&k);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(ll i=1;i<=n;i++) a[i]=a[i]^a[i-1];
    for(ll i=0;i<=n;i++) mp[a[i]]++;
    ll ans=0;
    for(auto it:mp) 
    {
        if(!it.S) continue;
        ll sum=it.S+mp[(1<<k)-1-it.F];
        ll mid=sum/2;
        if(mp[(1<<k)-1-it.F]!=0) ans+=1LL*mid*(mid-1)/2+1LL*(sum-mid)*(sum-mid-1)/2;
        else ans+=1LL*mid*(mid-1)+1LL*(sum-mid)*(sum-mid-1);
    }
    printf("%lld\n",1LL*n*(n+1)/2-ans/2);
    return 0;
}