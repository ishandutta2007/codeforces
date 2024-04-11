#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int prime[MAXN];
bool is_prime[MAXN];
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
ll n,b;
ll test(ll n,ll x)
{
    ll ans=0;
    while(n>=x)
    {
        ans+=n/x;
        n/=x;
    }
    return ans;
}
int main()
{
    int p=sieve(1000000);
    scanf("%lld%lld",&n,&b);
    ll ans=INF;
    for(int i=0;i<p;i++)
    {
        int cnt=0;
        while(b%prime[i]==0)
        {
            b/=prime[i];
            cnt++;
        }
        if(cnt) ans=min(ans,test(n,prime[i])/cnt);
    }
    if(b>1) ans=min(ans,test(n,b));
    printf("%lld\n",ans);
    return 0;
}