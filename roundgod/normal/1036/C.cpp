/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-07 22:42:33
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll q,n,k,a[20];
ll dp[20][5][2];
ll solve(ll now,ll cnt,ll equal)
{
    if(cnt>3) return 0;
    if(now==0) return 1;
    if(dp[now][cnt][equal]!=-1) return dp[now][cnt][equal];
    ll lim=equal?a[now]:9;
    ll ans=0;
    for(ll i=0;i<=lim;i++)
        ans+=solve(now-1,cnt+(i!=0),equal&&(a[now]==i));
    return dp[now][cnt][equal]=ans;
}
ll calc(ll n)
{
    ll t=0;
    memset(dp,-1,sizeof(dp));
    while(n) {t++; a[t]=n%10; n/=10;}
    return solve(t,0,1);
}
int main()
{
    scanf("%lld",&q);
    while(q--)
    {
        ll l,r;
        scanf("%lld%lld",&l,&r);
        printf("%lld\n",calc(r)-calc(l-1));
    }
    return 0;
}