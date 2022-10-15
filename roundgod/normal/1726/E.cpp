#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
int f[MAXN],fact[MAXN],invf[MAXN],ifact[MAXN],p2[MAXN];
int p[MAXN],q[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
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
int comb(int n,int k)
{
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int main()
{
    f[0]=f[1]=1;
    for(int i=2;i<=300000;i++) 
    {
        f[i]=f[i-1];
        add(f[i],1LL*f[i-2]*(i-1)%MOD);
    }
    p2[0]=1;
    for(int i=1;i<=300000;i++) p2[i]=2LL*p2[i-1]%MOD;
    fact[0]=invf[0]=1;
    ifact[1]=1;
    for(int i=3;i<=300000;i+=2) ifact[i]=1LL*i*ifact[i-2]%MOD;
    for(int i=1;i<=300000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[300000]=pow_mod(fact[300000],MOD-2);
    for(int i=299999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int ans=0;
        for(int i=0;i*4<=n;i++)
            add(ans,1LL*comb(n-2*i,2*i)*f[n-4*i]%MOD*(i==0?1:ifact[2*i-1])%MOD*p2[i]%MOD);
        printf("%d\n",ans);
    }
    return 0;
}