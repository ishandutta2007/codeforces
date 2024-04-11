#include<bits/stdc++.h>
#define MAXN 1000005
#define MAXK 20000005
#define MAXP 665005
#define MOD 1000000007
#define INF 1000000000
using namespace std;
typedef long long ll;
ll prime[MAXK],lp[MAXK],cnt[MAXK];
bool is_prime[MAXK];
ll a[MAXN],n,p;
ll sieve(ll n)
{
    ll p=0;
    for(ll i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    memset(lp,0,sizeof(lp));
    lp[1]=1;
    for(ll i=2;i<=n;i++)
    {
        if(is_prime[i]) {prime[p++]=i; lp[i]=i;}
        for(ll j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            lp[prime[j]*i]=prime[j];
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
bool C(ll x)
{
    for(ll i=0;i<p;i++)
    {
        ll c=0,t=x;
        while(t)
        {
            t=t/prime[i];
            c+=t;
        }
        if(c<cnt[prime[i]]) return false;
    }
    return true;
}
int main()
{
    scanf("%I64d",&n);
    memset(cnt,0,sizeof(cnt));
    ll sum=0;
    for(ll i=0;i<n;i++)
    {
        scanf("%I64d",&a[i]);
        sum+=a[i];
        cnt[a[i]]++;
    }
    p=sieve(10000000);
    for(ll i=10000000;i>=2;i--)
        cnt[i]+=cnt[i+1];
    for(ll i=10000000;i>=2;i--)
    {
        if(cnt[i]&&i!=lp[i])
        {
            cnt[lp[i]]+=cnt[i];
            cnt[i/lp[i]]+=cnt[i];
        }
    }
    ll lb=0,rb=sum;
    while(rb-lb>1)
    {
        ll mid=(lb+rb)/2;
        if(C(mid)) rb=mid; else lb=mid;
    }
    printf("%I64d\n",rb);
    return 0;
}