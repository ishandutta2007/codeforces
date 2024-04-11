/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-06 23:41:28
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
ll n,k;
vector<P> v;
int main()
{
    scanf("%lld",&n);
    ll sum=0;
    for(ll i=1;i<=n;i++) 
    {
        ll x;
        scanf("%lld",&x);
        v.push_back(P(x,0));
    }
    for(ll i=1;i<=n;i++)
    {
        ll x;
        scanf("%lld",&x);
        v.push_back(P(x,1));
    }
    sort(v.rbegin(),v.rend()); 
    for(ll i=0;i<(int)v.size();i++)
    {
        if((!(i&1))&&(v[i].S==0)) sum+=v[i].F;
        if((i&1)&&(v[i].S==1)) sum-=v[i].F;
    }
    printf("%lld\n",sum);
    return 0;
}