/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-19 10:20:02
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
ll l,r,x,y;
ll prime[MAXN];
bool is_prime[MAXN];
ll sieve(ll n)
{
    ll p=0;
    memset(is_prime,true,sizeof(is_prime));
    is_prime[0]=is_prime[1]=false;
    for(ll i=2;i<=n;i++)
    {
        if(is_prime[i]) {prime[p++]=i;}
        for(ll j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
int main()
{
    ll p=sieve(100000);
    scanf("%lld%lld%lld%lld",&l,&r,&x,&y);
    if(y%x!=0)
    {
        puts("0");
        return 0;
    }
    ll s=y/x;
    l=(l-1)/x+1,r=r/x;
    vector<ll> v;
    ll t=s;
    for(ll i=0;i<p;i++)
    {
        if(t%prime[i]==0)
        {
            ll res=1;
            while(t%prime[i]==0)
            {
                res*=prime[i];
                t/=prime[i];
            }
            v.push_back(res);
        }
    }
    if(t!=1) v.push_back(t);
    ll sz=v.size();
    ll ans=0;
    for(ll i=0;i<(1<<sz);i++)
    {
        ll res=1;
        for(ll j=0;j<sz;j++)
            if((i>>j)&1) res*=v[j];
        if(res>=l&&res<=r&&s/res>=l&&s/res<=r) ans++;
    }
    printf("%lld\n",ans);
    return 0;
}