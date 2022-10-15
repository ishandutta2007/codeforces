#include<bits/stdc++.h>
#define MAXN 1000005
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll t,x,p,k,sz;
ll prime[MAXN];
bool is_prime[MAXN];
vector<ll>pr;
ll sieve(ll n)
{
    ll p=0;
    for(ll i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(ll i=2;i<=n;i++)
    {
        if(is_prime[i])
        {
            prime[p++]=i;
            for(ll j=2*i;j<=n;j+=i) is_prime[j]=false;
        }
    }
    return p;
}
ll solve(ll n)
{
    ll sum=0;
    for(ll i=1;i<(1<<pr.size());i++)
    {
        ll d=1,ct=0;
        for(ll j=0;j<pr.size();j++)
        {
            if(i&(1<<j))
            {
                ct++;
                d*=pr[j];
            }
        }
        if(ct%2) sum+=n/d;
        else sum-=n/d;
    }
    return n-sum;
}
int main() 
{
    scanf("%I64d",&t);
    sz=sieve(1000000);
    while(t--)
    {
        scanf("%I64d%I64d%I64d",&x,&p,&k);
        pr.clear();
        for(ll i=0;i<sz;i++)
        {
            if(p%prime[i]==0)
            {
                pr.push_back(prime[i]);
                while(p%prime[i]==0) p/=prime[i];
            }
            if(p==1) break;
        }
        if(p>1) pr.push_back(p);
        ll num=solve(x);
        ll lb=x,rb=10000000;
        while(rb-lb>1)
        {
            ll mid=(lb+rb)/2;
            if(solve(mid)-num<k) lb=mid; else rb=mid;
        }
        printf("%I64d\n",rb);
    }
    return 0;
}