#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int fact[MAXN],invf[MAXN],p2[MAXN];
ll sum[MAXN];
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
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int comb(int n,int k)
{
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int calc(int x,int y)
{
    int res=0;
    for(int i=0;i<=min(x,y);i++) add(res,1LL*comb(x,i)*comb(y,i)%MOD);
    return res;
}
int main()
{
    fact[0]=invf[0]=p2[0]=1;
    for(int i=1;i<=100000;i++) p2[i]=2LL*p2[i-1]%MOD;
    for(int i=1;i<=100000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[100000]=pow_mod(fact[100000],MOD-2);
    for(int i=99999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d",&t);
    while(t--)
    {
        map<ll,int> cnt; 
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
        for(int i=1;i<=n-1;i++) cnt[sum[i]]++;
        if(sum[n]==0) {printf("%d\n",p2[n-1]); continue;}
        int ans=1;
        for(auto p:cnt)
        {
            if(p.F*2>sum[n]) continue;
            if(p.F*2==sum[n]) ans=1LL*ans*p2[p.S]%MOD;
            else ans=1LL*ans*calc(p.S,cnt[sum[n]-p.F])%MOD;
        }
        printf("%d\n",ans);
    }
    return 0;
}