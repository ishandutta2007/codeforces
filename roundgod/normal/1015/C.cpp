/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-31 22:44:00
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
typedef pair<ll,ll> P;
ll n,m;
P a[MAXN];
int main()
{
    scanf("%lld%lld",&n,&m);
    ll sum=0;
    for(ll i=0;i<n;i++) 
    {
        scanf("%lld%lld",&a[i].S,&a[i].F);
        a[i].F=a[i].S-a[i].F;
        sum+=a[i].S;
    }
    ll cnt=0;sum=sum-m;
    sort(a,a+n);
    for(ll i=n-1;i>=0;i--)
    {
        if(sum<=0) break;
        sum-=a[i].F;
        cnt++;
    }
    if(sum>0) puts("-1"); else printf("%lld\n",cnt);
    return 0;
}