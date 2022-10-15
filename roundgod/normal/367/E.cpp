/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-01 06:50:00
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,x;
int dp[2][MAXN][MAXN];
int main()
{
    scanf("%d%d%d",&n,&m,&x);
    if(n>m) {puts("0"); return 0;}
    dp[0][0][0]=1;
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++) for(int k=0;k<=j;k++) dp[(i+1)&1][j][k]=0;
        for(int j=0;j<=n;j++)
        {
            for(int k=0;k<=j;k++)
            {
                if(!dp[i&1][j][k]) continue;
                //printf("%d %d %d %d\n",i,j,k,dp[i&1][j][k]);
                if(i==x-1)
                {
                    (dp[(i+1)&1][j+1][k+1]+=dp[i&1][j][k])%=MOD;
                    (dp[(i+1)&1][j+1][k]+=dp[i&1][j][k])%=MOD;
                }
                else
                {
                    (dp[(i+1)&1][j][k]+=dp[i&1][j][k])%=MOD;
                    (dp[(i+1)&1][j+1][k]+=dp[i&1][j][k])%=MOD;
                    if(k>0) (dp[(i+1)&1][j][k-1]+=dp[i&1][j][k])%=MOD;
                    (dp[(i+1)&1][j+1][k+1]+=dp[i&1][j][k])%=MOD;
                }
            }
        }
    }
    int ans=dp[m&1][n][0];
    for(int i=1;i<=n;i++) ans=1LL*ans*i%MOD;
    printf("%d\n",ans);
    return 0;
}