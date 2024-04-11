/*************************************************************************
    > File Name: H.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-29 10:25:50
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXA 5050005
#define MAXN 200005
#define MAXQ 1200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,q,a[MAXN];
ll fact[MAXA],prime[MAXA],nm[MAXA],num[MAXA],ans[MAXQ];
bool is_prime[MAXA];
ll dp[10][MAXA],res[20];
ll sieve(ll n)
{
    ll p=0;
    for(ll i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    fact[1]=1;nm[1]=1;num[1]=0;
    for(ll i=2;i<=n;i++)
    {
        if(is_prime[i]) {prime[p++]=i; fact[i]=i; nm[i]=i; num[i]=1;}
        for(ll j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            fact[prime[j]*i]=prime[j];
            if(i%prime[j]==0) 
            {
                nm[prime[j]*i]=nm[i/prime[j]];
                num[prime[j]*i]=num[i];
                break;
            }
            else {nm[prime[j]*i]=nm[i]*prime[j]; num[prime[j]*i]=num[i]+1;}
        }
    }
    return p;
}
vector<ll> divisors;
void divi(ll x)
{
    divisors={1};
    while(x>1)
    {
        ll p=fact[x];
        ll sz=(int)divisors.size();
        for(ll i=0;i<sz;i++) divisors.push_back(divisors[i]*p);
        x=x/p;
    }
}
vector<P> query[MAXN];
int main()
{
    ll p=sieve(5050000);
    scanf("%lld%lld",&n,&q);
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        a[i]=nm[a[i]];
    }
    for(ll i=0;i<MAXA;i++)
        for(ll j=0;j<=7;j++)
            dp[j][i]=-1;
    memset(res,-1,sizeof(res));
    for(ll i=0;i<q;i++)
    {
        ll l,r;
        scanf("%lld%lld",&l,&r);
        query[r].push_back(P(l,i));
    }
    for(ll i=1;i<=n;i++)
    {
        divi(a[i]);
        for(auto d:divisors)
        {
            ll add=num[a[i]]-num[d];
            for(ll j=0;j<=7;j++)
            {
                ll cur_left=dp[j][d];
                ll cur_ans=add+j;
                if(cur_ans<=14)  res[cur_ans]=max(res[cur_ans],cur_left);
            }
        }
        for(auto d:divisors)
        {
            ll add=num[a[i]]-num[d];
            dp[add][d]=max(dp[add][d],i);
        }
        for(auto q:query[i])
        {
            ans[q.S]=15;
            for(ll j=0;j<=14;j++)
            {
                if(res[j]>=q.F) 
                {
                    ans[q.S]=j;
                    break;
                }
            }
        }
    }
    for(ll i=0;i<q;i++) printf("%lld\n",ans[i]);
    return 0;
}