/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-14 22:42:13
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN],dp[MAXN],pow2[MAXN];
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    ll ans=0;
    pow2[0]=1;
    for(ll i=1;i<=n;i++) pow2[i]=2LL*pow2[i-1]%MOD;
    for(ll i=1;i<=n-1;i++) (ans+=1LL*a[i]*(n-i+2)%MOD*pow2[n-i-1])%=MOD;
    (ans+=a[n])%=MOD;
    printf("%lld\n",ans);
    return 0;
}