#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
int fact[MAXN],invf[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
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
    fact[0]=invf[0]=1;
    for(int i=1;i<=200000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[200000]=pow_mod(fact[200000],MOD-2);
    for(int i=199999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d%d",&n,&k);
    if(k>=n)
    {
        puts("0");
        return 0;
    }
    if(k==0)
    {
        printf("%d\n",fact[n]);
        return 0;
    }
    int ans=0;
    for(int i=k;i<=n;i++)
    {
        if((i-k)&1) dec(ans,1LL*comb(n-k,i-k)*pow_mod(n-i,n)%MOD);
        else add(ans,1LL*comb(n-k,i-k)*pow_mod(n-i,n)%MOD);
    }
    ans=2LL*ans*comb(n,k)%MOD;
    printf("%d\n",ans);
}