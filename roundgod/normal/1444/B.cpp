#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000 
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
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
int fact[MAXN],invf[MAXN];
int comb(int n,int k)
{
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++) scanf("%d",&a[i]);
    sort(a+1,a+2*n+1);
    fact[0]=invf[0]=1;
    for(int i=1;i<=300000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[300000]=pow_mod(fact[300000],MOD-2);
    for(int i=299999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    int ans=0;
    for(int i=1;i<=n;i++) dec(ans,1LL*comb(2*n,n)*a[i]%MOD);
    for(int i=n+1;i<=2*n;i++) add(ans,1LL*comb(2*n,n)*a[i]%MOD);
    printf("%d\n",ans);
    return 0;
}