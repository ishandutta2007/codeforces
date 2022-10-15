#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 400005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
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
int fact[MAXN],invf[MAXN];
int comb(int n,int k)
{
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=400000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[400000]=pow_mod(fact[400000],MOD-2);
    for(int i=399999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d",&n);
    for(int i=0;i<=n;i++) scanf("%d",&a[i]);
    int ans=0;
    for(int i=0;i<=n;i++) add(ans,comb(i+a[i],a[i]-1));
    printf("%d\n",ans);
    return 0;
}