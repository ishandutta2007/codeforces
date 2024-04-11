#include<bits/stdc++.h>
using namespace std;
int n,m,k,dp[101][101],lef[101][101],rig[101][101];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		while(k--)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			for(int j=l;j<=r;j++)
			{
				lef[i][j]=l;
				rig[i][j]=r;
			}	
		}	
	}	
	for(int i=m;i>=1;i--)
		for(int l=i;l<=m;l++)
			for(int k=i;k<=l;k++)
			{
				int a=0;
				for(int j=1;j<=n;j++)
					if(lef[j][k]>=i&&rig[j][k]<=l)
						a++;
				dp[i][l]=max(dp[i][l],dp[i][k-1]+a*a+dp[k+1][l]);
			}
	cout<<dp[1][m];
	return 0;
}