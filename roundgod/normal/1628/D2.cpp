#include<bits/stdc++.h>
#define MAXN 2000005
#define INF 1000000000
#define MOD 1000000007
#define INV 500000004
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int fact[MAXN],invf[MAXN],p[MAXN];
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
int t,n,m,k;
int main()
{
    fact[0]=invf[0]=p[0]=1;
    for(int i=1;i<=2000000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[2000000]=pow_mod(fact[2000000],MOD-2);
    for(int i=1999999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    for(int i=1;i<=2000000;i++) p[i]=1LL*INV*p[i-1]%MOD;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&k);
        if(n==m) {printf("%d\n",1LL*n*k%MOD); continue;}
        int ans=0;
        for(int i=1;i<=m;i++)
            add(ans,1LL*i*k%MOD*p[n-i]%MOD*comb(n-i-1,m-i)%MOD);
        printf("%d\n",ans);
    }
    return 0;
}