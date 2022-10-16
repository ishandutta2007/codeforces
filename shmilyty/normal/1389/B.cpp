#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans,t,a[1000002],dp[100002][6];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		ans=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dp[j][i]=dp[j-1][i]+a[j];
				if(i&&j!=n)
					dp[j][i]=max(dp[j][i],dp[j+1][i-1]+a[j]);
				if(j-1+i*2==m)
					ans=max(ans,dp[j][i]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}