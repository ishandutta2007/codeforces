#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k;
int fact[MAXN],invf[MAXN];
int dp[MAXN],tmp[MAXN];
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
    if(n>5000)
    {
        int res=1,cur=n;
        for(int i=0;i<k;i++) 
        {
            res=1LL*res*cur%MOD; 
            cur--;
        }
        res=1LL*res*invf[k]%MOD;
        return res;
    }
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=100000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[100000]=pow_mod(fact[100000],MOD-2);
    for(int i=99999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d%d%d",&n,&m,&k);
    dp[1]=1;
    for(int i=2;i<=k;i++)
    {
        dp[i]=pow_mod(i,k);
        for(int j=1;j<i;j++)
        {
            if((i-j)&1) dec(dp[i],1LL*comb(i,j)*pow_mod(j,k)%MOD); else add(dp[i],1LL*comb(i,j)*pow_mod(j,k)%MOD);
        }
    }
    int prob=pow_mod(m,MOD-2);
    int ans=0;
    for(int i=1;i<=k;i++)
    {
        int pos=comb(n,i);
        add(ans,1LL*pos*pow_mod(prob,i)%MOD*dp[i]%MOD);
    }
    printf("%d\n",ans);
    return 0;
}