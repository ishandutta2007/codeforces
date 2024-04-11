#include<bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define INF 1000000000000000000LL
using namespace std;
typedef long long ll;
int prime[MAXN];
ll suf[MAXN];
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
    suf[100001]=INF;
    for(int i=100000;i>=1;i--) if(is_prime[i]) suf[i]=i; else suf[i]=suf[i+1];
    return p;
}
int t,d;
int main()
{
    int p=sieve(100000);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&d);
        if(d==1) {puts("6"); continue;}
        ll ans=INF;
        for(int i=1;i<p;i++)
        {
            if(prime[i]<=d) continue;
            if(prime[i]+d<=100000&&suf[prime[i]+d]!=INF)
            {
                printf("%lld\n",1LL*prime[i]*(suf[prime[i]+d]));
                break;
            }
        }
    }
    return 0;
}