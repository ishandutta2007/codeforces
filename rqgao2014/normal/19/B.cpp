#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
using namespace std;

const long long INF=1000000000000000;
long long dp[2005][4005];
int t[2005],n,c[2005];

int main()
{
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
		scanf("%d%d",&t[i],&c[i]);
		for(int j=0;j<=n;j++)
	for(int i=0;i<=n+n;i++)
		dp[j][i]=INF;
	dp[0][n]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=n+n;j++)
		{
			dp[i][j]=INF;
			if(j+1<=n+n) dp[i][j]=dp[i-1][j+1];
				 //if(j>=t[i]) 
				 dp[i][j]=min(dp[i][j],dp[i-1][max(0,j-t[i])]+c[i]);
		}
	long long ans=1000000000000000;
	for(int i=n;i<=n+n;i++)
		ans=min(ans,dp[n][i]);
	printf("%I64d\n",ans);
	return 0;
}