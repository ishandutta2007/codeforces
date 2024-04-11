/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-25 00:40:45
 ************************************************************************/

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
int n,k,a[MAXN];
int dp[MAXN][205][2];
void add(int &a,int b)
{
    a+=b;if(a>=MOD) a-=MOD;if(a<0) a+=MOD;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    memset(dp,0,sizeof(dp));
    if(a[1]!=-1) {dp[1][a[1]][0]=1; dp[1][a[1]+1][0]=MOD-1;}
    else
    {
        dp[1][1][0]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=200;j++) add(dp[i][j][0],dp[i][j-1][0]);
        for(int j=1;j<=200;j++) add(dp[i][j][1],dp[i][j-1][1]);
        for(int j=1;j<=200;j++)
        {
            if(dp[i][j][0])
            {
                //if(i==2)printf("0%d %d %d\n",i,j,dp[i][j][0]);
                if(a[i+1]==-1)
                {
                    add(dp[i+1][j+1][0],dp[i][j][0]);
                    add(dp[i+1][j][1],dp[i][j][0]);
                    add(dp[i+1][j+1][1],-dp[i][j][0]);
                }
                else
                {
                    if(a[i+1]>j) 
                    {
                        add(dp[i+1][a[i+1]][0],dp[i][j][0]);
                        add(dp[i+1][a[i+1]+1][0],-dp[i][j][0]);
                    }
                    else if(a[i+1]==j)
                    {
                        add(dp[i+1][a[i+1]][1],dp[i][j][0]);
                        add(dp[i+1][a[i+1]+1][1],-dp[i][j][0]);
                    }
                }
            }
            if(dp[i][j][1])
            {
                //if(i==2) printf("%d %d %d\n",i,j,dp[i][j][1]);
                if(a[i+1]==-1)
                {
                    add(dp[i+1][1][1],dp[i][j][1]);
                    add(dp[i+1][j+1][1],-dp[i][j][1]);
                    add(dp[i+1][j+1][0],dp[i][j][1]);
                }
                else
                {
                    if(a[i+1]>j) 
                    {
                        add(dp[i+1][a[i+1]][0],dp[i][j][1]);
                        add(dp[i+1][a[i+1]+1][0],-dp[i][j][1]);
                    }
                    else
                    {
                        add(dp[i+1][a[i+1]][1],dp[i][j][1]);
                        add(dp[i+1][a[i+1]+1][1],-dp[i][j][1]);
                    }
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=200;i++) add(ans,dp[n][i][1]);
    printf("%d\n",ans);
    return 0;
}