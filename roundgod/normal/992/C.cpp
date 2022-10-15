/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-19 10:42:28
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define INV 500000004
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll x,k;
ll pow_mod(ll a,ll i)
{
    ll s=1;
    if(i==0) return 1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int main()
{
    scanf("%lld%lld",&x,&k);
    if(x==0)
    {
        puts("0");
        return 0;
    }
    x%=MOD;k%=(MOD-1);
    ll res=pow_mod(2,k);
    ll ans=((1LL*x*res-1LL*(res-1)*INV)%MOD+MOD)%MOD;
    ans=ans*2%MOD;
    printf("%lld\n",ans);
    return 0;
}