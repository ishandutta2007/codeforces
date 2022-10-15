#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#define MAXN 15
#define MAXM 100
using namespace std;
char str[MAXM];
int graph[MAXN][MAXM],dp[MAXN+1][2];
int n,m;
int main()
{
    int cnt1=0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%s",str);
        for(int j=0;j<strlen(str)-2;j++)
        {
          graph[i][j]=(int)str[j+1]-48;
          if(graph[i][j]) cnt1++;
        }
    }
    dp[n][0]=0;
    dp[n][1]=0;
    int f2=n;
    for(int i=n-1;i>=0;i--)
    {
        int cnt=0;
        int left=m,right=-1;
        for(int j=0;j<m;j++)
        {
            if(graph[i][j]==1)
            {
                left=min(j,left);
                right=max(j,right);
                cnt++;
            }
        }
        if(cnt1==cnt)
        {
            if(i==n-1)
            {
                printf("%d\n",dp[i+1][0]+right+1);
                return 0;
            }
             dp[i][0]=dp[i+1][0]+right+1;
            dp[i][1]=dp[i+1][1]+(m-left);
            printf("%d\n",min(dp[i][0],dp[i][1]));
            return 0;
        }
        cnt1-=cnt;
        if(i==n-1)
        {
            dp[i][0]=dp[i+1][0]+2*(right+1)+1;
            dp[i][1]=dp[i+1][0]+m+2;
        }
        else
        {
        dp[i][0]=min(dp[i+1][0]+2*(right+1),dp[i+1][1]+m+1)+1;
        dp[i][1]=min(dp[i+1][1]+2*(m-left),dp[i+1][0]+m+1)+1;
        }
    }
    return 0;
}