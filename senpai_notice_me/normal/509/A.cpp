#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n,dp[11][11];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	    dp[i][1]=dp[1][i]=1;
	for(int i=2;i<=n;i++)
	    for(int j=2;j<=n;j++)
	        dp[i][j]=dp[i-1][j]+dp[i][j-1];
	printf("%d",dp[n][n]);
	return 0;
}