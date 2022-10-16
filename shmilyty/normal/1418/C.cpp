#include<bits/stdc++.h>
using namespace std;
int t,n,a[200001],dp[200001][2];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
//		memset(dp,0,sizeof(dp));
		dp[0][0]=1e9;
		dp[0][1]=0;
		for(int i=1;i<=n;i++)
		{
			dp[i][0]=dp[i-1][1]+a[i];
			if(i>=2)
				dp[i][0]=min(dp[i][0],dp[i-2][1]+a[i-1]+a[i]);
			dp[i][1]=dp[i-1][0];
			if(i>=2)
				dp[i][1]=min(dp[i][1],dp[i-2][0]);
		}
		cout<<min(dp[n][0],dp[n][1])<<endl;	
	}
}