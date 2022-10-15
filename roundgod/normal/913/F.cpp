#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a,b,p;
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
int dp[MAXN][MAXN];
int f[MAXN];//f: ans
int g[MAXN];//g: prob of strongly connected
int px[MAXN],py[MAXN];
int main()
{
    scanf("%d%d%d",&n,&a,&b);
    p=1LL*a*pow_mod(b,MOD-2)%MOD;
    px[0]=py[0]=1;
    for(int i=1;i<=n;i++) px[i]=1LL*px[i-1]*p%MOD;
    for(int i=1;i<=n;i++) py[i]=1LL*py[i-1]*(MOD+1-p)%MOD; 
    dp[0][0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            add(dp[i+1][j],1LL*dp[i][j]*px[j]%MOD);
            add(dp[i+1][j+1],1LL*dp[i][j]*py[i-j]%MOD);
        }
    }
    f[1]=0; g[1]=1;
    for(int i=2;i<=n;i++)
    {
        //calc g[i]
        g[i]=1;
        for(int j=1;j<i;j++) dec(g[i],1LL*g[j]*dp[i][j]%MOD);
        int tmp=0;
        for(int j=1;j<i;j++) add(tmp,1LL*g[j]*dp[i][j]%MOD*(1LL*j*(i-j)+1LL*j*(j-1)/2+f[j]+f[i-j])%MOD);
        add(tmp,1LL*i*(i-1)/2*g[i]%MOD);
        f[i]=1LL*tmp*pow_mod(MOD+1-g[i],MOD-2)%MOD;
    }
    printf("%d\n",f[n]);
    return 0;
}