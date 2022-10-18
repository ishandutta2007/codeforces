#include<bits/stdc++.h>
using namespace std;
int a[1234567];
int dp[2][7][7];
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int ans = 0;
	for(int i = 0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		a[x]++;
		if(a[x]>=9)
		{
			a[x]-=3;
			ans++;
		}
	}
	//for(int i = 1;i<=m;i++) printf("%d\n",a[i]);
	for(int j = 0;j<7;j++)for(int k = 0;k<7;k++) dp[0][j][k] = -10000000;
	dp[0][0][0] = 0;
	for(int i = 1;i<=m;i++)
	{
		for(int j = 0;j<7;j++)for(int k = 0;k<7;k++) dp[1][j][k] = -10000000;
		if(!a[i])
		{
			for(int j = 0;j<7;j++)for(int k = 0;k<7;k++)
			{
				dp[1][k][0] = max(dp[1][k][0],dp[0][j][k]);
			}
		}
		if(a[i]==1)
		{
			for(int j = 0;j<7;j++)for(int k = 0;k<7;k++)
			{
				dp[1][k][1] = max(dp[1][k][1],dp[0][j][k]);
			}
			for(int j = 1;j<7;j++)for(int k = 1;k<7;k++)
			{
				dp[1][k-1][0] = max(dp[1][k-1][0],dp[0][j][k] + 1);
			}			
		}
		if(a[i]==2)
		{
			for(int j = 0;j<7;j++)for(int k = 0;k<7;k++)
			{
				dp[1][k][2] = max(dp[1][k][2],dp[0][j][k]);
			}
			for(int j = 1;j<7;j++)for(int k = 1;k<7;k++)
			{
				dp[1][k-1][1] = max(dp[1][k-1][1],dp[0][j][k] + 1);
			}
			for(int j = 2;j<7;j++)for(int k = 2;k<7;k++)
			{
				dp[1][k-2][0] = max(dp[1][k-2][0],dp[0][j][k] + 2);
			}					
		}
		if(a[i]==3)
		{
			for(int j = 0;j<7;j++)for(int k = 0;k<7;k++)
			{
				dp[1][k][3] = max(dp[1][k][3],dp[0][j][k]);
			}
			for(int j = 0;j<7;j++)for(int k = 0;k<7;k++)
			{
				dp[1][k][0] = max(dp[1][k][0],dp[0][j][k] + 1);
			}
			for(int j = 1;j<7;j++)for(int k = 1;k<7;k++)
			{
				dp[1][k-1][2] = max(dp[1][k-1][2],dp[0][j][k] + 1);
			}
			for(int j = 2;j<7;j++)for(int k = 2;k<7;k++)
			{
				dp[1][k-2][1] = max(dp[1][k-2][1],dp[0][j][k] + 2);
			}					
		}
		if(a[i]==4)
		{
			for(int j = 0;j<7;j++)for(int k = 0;k<7;k++) if(dp[0][j][k]>=0)
			{
				dp[1][k][4] = max(dp[1][k][4],dp[0][j][k]);
				dp[1][k][1] = max(dp[1][k][1],dp[0][j][k] + 1);
				if(j>=1&&k>=1)
				{
					dp[1][k-1][3] = max(dp[1][k-1][3],dp[0][j][k] + 1);
					dp[1][k-1][0] = max(dp[1][k-1][0],dp[0][j][k] + 2);					
				}
				if(j>=2&&k>=2) dp[1][k-2][2] = max(dp[1][k-2][2],dp[0][j][k] + 2); 
			}
		}
		if(a[i]==5)
		{
			for(int j = 0;j<7;j++)for(int k = 0;k<7;k++) if(dp[0][j][k]>=0)
			{
				dp[1][k][5] = max(dp[1][k][5],dp[0][j][k]);
				dp[1][k][2] = max(dp[1][k][2],dp[0][j][k] + 1);
				if(j>=1&&k>=1)
				{
					dp[1][k-1][4] = max(dp[1][k-1][4],dp[0][j][k] + 1);
					dp[1][k-1][1] = max(dp[1][k-1][1],dp[0][j][k] + 2);
				}
				if(j>=2&&k>=2)
				{
					dp[1][k-2][3] = max(dp[1][k-2][3],dp[0][j][k] + 2);
					dp[1][k-2][0] = max(dp[1][k-2][0],dp[0][j][k] + 3);
				}
			}					
		}
		if(a[i]==6)
		{
			for(int j = 0;j<7;j++)for(int k = 0;k<7;k++) if(dp[0][j][k]>=0) 
			{
				dp[1][k][6] = max(dp[1][k][6],dp[0][j][k]);
				dp[1][k][3] = max(dp[1][k][3],dp[0][j][k] + 1);
				dp[1][k][0] = max(dp[1][k][0],dp[0][j][k] + 2);
				if(j>=1&&k>=1)
				{
					dp[1][k-1][5] = max(dp[1][k-1][5],dp[0][j][k] + 1);
					dp[1][k-1][2] = max(dp[1][k-1][2],dp[0][j][k] + 2);
				}
				if(j>=2&&k>=2)
				{
					dp[1][k-2][4] = max(dp[1][k-2][4],dp[0][j][k] + 2);	
					dp[1][k-2][1] = max(dp[1][k-2][1],dp[0][j][k] + 3);
				}
			}
		}
		if(a[i]==7)
		{
			for(int j = 0;j<7;j++)for(int k = 0;k<7;k++) if(dp[0][j][k]>=0) 
			{
				dp[1][k][6] = max(dp[1][k][6],dp[0][j][k]);
				dp[1][k][4] = max(dp[1][k][4],dp[0][j][k] + 1);
				dp[1][k][1] = max(dp[1][k][1],dp[0][j][k] + 2);
				if(j>=1&&k>=1)
				{
					dp[1][k-1][6] = max(dp[1][k-1][6],dp[0][j][k] + 1);
					dp[1][k-1][3] = max(dp[1][k-1][3],dp[0][j][k] + 2);
					dp[1][k-1][0] = max(dp[1][k-1][0],dp[0][j][k] + 3);
				}
				if(j>=2&&k>=2)
				{
					dp[1][k-2][5] = max(dp[1][k-2][5],dp[0][j][k] + 2);	
					dp[1][k-2][2] = max(dp[1][k-2][2],dp[0][j][k] + 3);
				}
			}
		}
		if(a[i]==8)
		{
			for(int j = 0;j<7;j++)for(int k = 0;k<7;k++) if(dp[0][j][k]>=0) 
			{
				dp[1][k][6] = max(dp[1][k][6],dp[0][j][k]);
				dp[1][k][5] = max(dp[1][k][5],dp[0][j][k] + 1);
				dp[1][k][2] = max(dp[1][k][2],dp[0][j][k] + 2);
				if(j>=1&&k>=1)
				{
					dp[1][k-1][6] = max(dp[1][k-1][6],dp[0][j][k] + 1);
					dp[1][k-1][4] = max(dp[1][k-1][4],dp[0][j][k] + 2);
					dp[1][k-1][1] = max(dp[1][k-1][1],dp[0][j][k] + 3);
				}
				if(j>=2&&k>=2)
				{
					dp[1][k-2][6] = max(dp[1][k-2][6],dp[0][j][k] + 2);	
					dp[1][k-2][3] = max(dp[1][k-2][3],dp[0][j][k] + 3);
					dp[1][k-2][0] = max(dp[1][k-2][0],dp[0][j][k] + 4);
				}
			}
		}
		for(int j = 0;j<7;j++) for(int k = 0;k<7;k++) dp[0][j][k] = dp[1][j][k];
		//for(int j = 0;j<7;j++) for(int k = 0;k<7;k++) printf("dp[%d][%d][%d] = %d\n",i,j,k,dp[0][j][k]);
	}
	int xx = 0;
	for(int i = 0;i<7;i++) for(int j = 0;j<7;j++) xx = max(xx,dp[0][i][j]);
	printf("%d\n",ans + xx);
	return 0;
}