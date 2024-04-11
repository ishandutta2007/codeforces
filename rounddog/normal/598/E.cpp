#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define inf 1073741823

using namespace std;  
int dp[35][35][1000],n,m,t,query;
  
int main()  
{  
    for (int i=1;i<=30;i++)
        for (int j=1;j<=30;j++)
		    for (int k=1;k<=50;k++)
			    dp[i][j][k]=inf; 
    for (int i=1;i<=30;i++)
        for (int j=1;j<=30;j++)
        {
        	dp[i][j][0]=0;
        	dp[i][j][i*j]=0;
        }
    for (int i=1;i<=30;i++)
        for (int j=1;j<=30;j++)
            for (int k=1;k<=min(i*j,50);k++)
            	for (int l=0;l<=k;l++)
            	{
            	    for (int u=1;u<i;u++) 
            	        dp[i][j][k]=min(dp[i][j][k],dp[u][j][l]+dp[i-u][j][k-l]+j*j);
            	    for (int u=1;u<j;u++) 
            	        dp[i][j][k]=min(dp[i][j][k],dp[i][u][l]+dp[i][j-u][k-l]+i*i);
        	    }
    scanf("%d",&query);
    while (query--)
    {
    	scanf("%d%d%d",&n,&m,&t);
    	printf("%d\n",dp[n][m][t]);
    }
    return 0;
}