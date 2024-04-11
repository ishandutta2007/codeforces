#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1073741824
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int prime[MAXN],phi[MAXN],mu[MAXN],res[MAXN],a,b,c;
bool is_prime[MAXN];
ll ans;
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    phi[1]=mu[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) {prime[p++]=i; phi[i]=i-1; mu[i]=-1;}
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            phi[prime[j]*i]=(i%prime[j]?phi[i]*prime[j]:phi[i]*(prime[j]-1));
            mu[prime[j]*i]=(i%prime[j]?-mu[i]:0);
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
ll solve(int x,int a)
{
    ll res=0;
    for(int j=1;j<=x;j++) if(__gcd(a,j)==1) res+=x/j;
    return res;
}
int main()
{
    sieve(2000);
    scanf("%d%d%d",&a,&b,&c);
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=min(b,c);j++)
        {
            if(__gcd(i,j)!=1) continue;
            ans+=1LL*mu[j]*(a/i)*solve(b/j,i)*solve(c/j,i);
        }
    }
    printf("%lld\n",ans%MOD);
    return 0;
}