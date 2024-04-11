#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
char str[MAXN];
int dp[MAXN][26],sum[MAXN],fact[MAXN],invf[MAXN];
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
    for(int i=1;i<=5000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[5000]=pow_mod(fact[5000],MOD-2);
    for(int i=4999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d",&n);
    scanf("%s",str+1);
    for(int i=1;i<=n;i++)
    {
        int num=str[i]-'a';
        for(int j=i;j>=1;j--)
        {
            dec(sum[j],dp[j][num]);
            if(j==1) dp[j][num]=1; else dp[j][num]=0;
            add(dp[j][num],sum[j-1]); dec(dp[j][num],dp[j-1][num]);
            add(sum[j],dp[j][num]);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++) add(ans,1LL*sum[i]*comb(n-1,i-1)%MOD);
    printf("%d\n",ans);
    return 0;
}