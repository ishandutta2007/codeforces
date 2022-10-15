/*************************************************************************
    > File Name: F.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-01 00:46:22
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 205
#define MAXK 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN],dp[MAXN][MAXN][MAXK];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            for(int k=0;k<=m;k++)
            {
                if(!dp[i][j][k]) continue;
                int val=k+j*(a[i+1]-a[i]);
                if(val>m) continue;
                (dp[i+1][j+1][val]+=dp[i][j][k])%=MOD;
                dp[i+1][j-1][val]=(dp[i+1][j-1][val]+1LL*j*dp[i][j][k])%MOD;
                dp[i+1][j][val]=(dp[i+1][j][val]+1LL*(j+1)*dp[i][j][k])%MOD;
            }
        }
    }
    int ans=0;
    for(int i=0;i<=m;i++) ans=(ans+dp[n][0][i])%MOD;
    printf("%d\n",ans);
    return 0;
}