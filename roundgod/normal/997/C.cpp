#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int fact[MAXN],invf[MAXN],p3[MAXN];
int comb(int n,int k)
{
    return (1LL*fact[n]*invf[k]%MOD)*invf[n-k]%MOD;
}
int main()
{
    scanf("%d",&n);
    fact[0]=invf[0]=p3[0]=1;
    for(int i=1;i<=n;i++)
        p3[i]=3LL*p3[i-1]%MOD;
    for(int i=1;i<=n;i++)
        fact[i]=1LL*fact[i-1]*i%MOD;
    invf[n]=pow_mod(fact[n],MOD-2);
    for(int i=n-1;i>=1;i--)
        invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    int ans=0,p=1;
    for(int i=1;i<=n;i++)
    {
        ans=(ans+(2LL*p*comb(n,i)*p3[i]%MOD)*pow_mod(3,1LL*(n-i)*n%(MOD-1)))%MOD;
        //printf("%d\n",ans);
        ans=(ans-3LL*p*comb(n,i)*pow_mod(3,1LL*(n-i)*n%(MOD-1)))%MOD;
        p*=-1;
    }
    p=1;
    for(int i=1;i<=n;i++)
    {
        ans=(ans+(3LL*p*comb(n,i)*pow_mod(p3[n-i]-1,n)))%MOD;
        p*=-1;
    }
    ans=(ans+MOD)%MOD;
    printf("%d\n",ans);
    return 0;
}