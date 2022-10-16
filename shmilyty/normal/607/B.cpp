#include<bits/stdc++.h>
using namespace std;
int n,a[501],dp[501][501]; 
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int l=1;l<=n;l++)
			dp[i][l]=1e9;
	for(int i=1;i<n;i++)
	{
		dp[i][i]=1;
		if(a[i]==a[i+1])
			dp[i][i+1]=1;
		else
			dp[i][i+1]=2;
	}
	dp[n][n]=1;
	for(int l=2;l<=n;l++)
		for(int i=1;i+l<=n;i++)		
		{
			int j=i+l;
			if(a[i]==a[j])
				dp[i][j]=dp[i+1][j-1];
			for(int k=i;k<j;k++)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]); 
		}
	cout<<dp[1][n];
	return 0;
}