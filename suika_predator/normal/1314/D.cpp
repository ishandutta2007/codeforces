#include<bits/stdc++.h>
using namespace std;
int n,k;
int dis[111][111];
int a[23],col[23],dp[23][111];
int main()
{
	ios_base::sync_with_stdio(false);
	srand(time(0));
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>dis[i][j];
		}
	}
	int ans=0x3f3f3f3f;
	while(1.0*clock()/CLOCKS_PER_SEC<2.9)
	{
		for(int i=1;i<=n;i++)col[i]=rand()%2;
		memset(dp,0x3f,sizeof(dp));
		dp[0][1]=0;
		for(int t=1;t<=k;t++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(col[i]!=col[j])
						dp[t][j]=min(dp[t][j],dp[t-1][i]+dis[i][j]);
				}
			}
		}
		ans=min(ans,dp[k][1]);
	}
	cout<<ans<<endl;
	return 0;
}