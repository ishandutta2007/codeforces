# include<iostream>
#include<bits/stdc++.h>
#define EPS 1e-6
#include <stdio.h>
#define SQRTN 316
using namespace std;
int dp[201][40001][2];
int ar[201];
int n,a,b;
int sum[201];
int DP()
{
    cin>>n>>a>>b;
    for (int i=0;i<n;i++)
        cin>>ar[i];
    sum[0]=ar[0];
    for (int i=1;i<n;i++)
        sum[i]=ar[i]+sum[i-1];
    for (int i=0;i<=200;i++)
        for (int j=0;j<=40000;j++)
            dp[i][j][0]=dp[i][j][1]=INT_MAX;
    if (b>=ar[0])
        dp[0][a][1]=0;
    if (a>=ar[0])
        dp[0][a-ar[0]][0]=0;
    for (int i=0;i<n-1;i++)
    {
        for (int j=0;j<=40000;j++)
        {
            for (int k=0;k<2;k++)
            {
                if (dp[i][j][k]==INT_MAX)
                    continue;
                // 0
                if (j>=ar[i+1])
                    dp[i+1][j-ar[i+1]][0]=min(dp[i+1][j-ar[i+1]][0],dp[i][j][k]+((k!=0)?(min(ar[i],ar[i+1])):0));
                // 1
                int cur=b-sum[i]+(a-j);
                if (cur>=ar[i+1])
                    dp[i+1][j][1]=min(dp[i+1][j][1],dp[i][j][k]+((k==0)?(min(ar[i],ar[i+1])):0));
            }
        }
    }
    int ans=INT_MAX;
    for (int j=0;j<=40000;j++)
        ans=min(min(ans,dp[n-1][j][1]),dp[n-1][j][0]);
    if (ans==INT_MAX)
        return -1;
    return ans;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cout<<DP()<<endl;
}