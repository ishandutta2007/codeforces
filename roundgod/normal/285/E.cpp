#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,comb[MAXN][MAXN],fact[MAXN];
int dp[MAXN][MAXN][4];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
//dp[i][j][0/1][0/1]
//permutation of length i
//with j good positions
//whether p[i]=i-1
//whether p[i-1]=i
int main()
{
    comb[0][0]=1;
    for(int i=1;i<=1000;i++)
    {
        comb[i][0]=comb[i][i]=1;
        for(int j=1;j<i;j++)
        {
            comb[i][j]=comb[i-1][j-1];
            add(comb[i][j],comb[i-1][j]);
        }
    }
    fact[0]=1;
    for(int i=1;i<=1000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    scanf("%d%d",&n,&k);
    dp[1][0][0]=1;
    for(int i=1;i<n;i++)
        for(int j=0;j<=i;j++)
            for(int mask=0;mask<4;mask++)
            {
                if(!dp[i][j][mask]) continue;
                add(dp[i+1][j][0],dp[i][j][mask]);
                if(!mask) add(dp[i+1][j+2][3],dp[i][j][mask]);
                if(!(mask&1)) add(dp[i+1][j+1][2],dp[i][j][mask]);
                if(!(mask&2)) add(dp[i+1][j+1][1],dp[i][j][mask]);
            }
    for(int i=0;i<=n;i++)
    {
        for(int j=1;j<4;j++)
            add(dp[n][i][0],dp[n][i][j]);
        dp[n][i][0]=1LL*dp[n][i][0]*fact[n-i]%MOD;
    }
    for(int j=k+1;j<=n;j++)
    {
        if((j-k)&1) dec(dp[n][k][0],1LL*dp[n][j][0]*comb[j][k]%MOD);
        else add(dp[n][k][0],1LL*dp[n][j][0]*comb[j][k]%MOD);
    }
    printf("%d\n",dp[n][k][0]);
    return 0;
}