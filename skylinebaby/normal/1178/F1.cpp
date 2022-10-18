#include<bits/stdc++.h>
using namespace std;
int a[511];
int rea[511];
long long dp1[511][511];
long long dp2[511][511];
int mn[511][511];
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 1;i<=m;i++) 
	{
		scanf("%d",&a[i]);
		rea[a[i]] = i;
	}
	for(int i = 1;i<=n;i++) for(int j = i;j<=n;j++) mn[i][j] = n;
	for(int i = 1;i<=n;i++) for(int j = i;j<=n;j++) for(int k = i;k<=j;k++) mn[i][j] = min(mn[i][j],a[k]);
	for(int i = 1;i<=n;i++) dp1[i][rea[i]] = dp2[i][rea[i]] = 1;
	for(int t = n;t>=1;t--)
	{
		int p = rea[t];
		for(int i = p;i>=1 && mn[i][p]==t;i--) for(int j = p;j>=i;j--)
		{
			if(i!=p&&j==p) dp1[t][i] = (dp1[t][i] + dp1[mn[i][p-1]][i]*dp2[mn[i][p-1]][p-1]) % 998244353;
			if(i!=p&&j!=p) if(i!=j)
			{
				long long plu = (dp1[mn[i][j-1]][i]*dp2[mn[i][j-1]][j-1])%998244353;
				plu = (plu*dp1[mn[j][p-1]][j])%998244353;
				plu = (plu*dp2[mn[j][p-1]][p-1])%998244353;
				dp1[t][i] = (dp1[t][i] + plu) % 998244353;
			}
			if(i!=p&&j!=p) if(i==j) dp1[t][i] = (dp1[t][i] + dp1[mn[i][p-1]][i]*dp2[mn[i][p-1]][p-1]) % 998244353;
		}
		for(int i = p;i<=n && mn[p][i]==t;i++) for(int j = p;j<=i;j++)
		{
			//printf("before dp2 %d %d %lld\n",t,i,dp2[t][i]);
			if(i!=p&&j==p) dp2[t][i] = (dp2[t][i] + dp1[mn[p+1][i]][p+1]*dp2[mn[p+1][i]][i]) % 998244353;
			//printf("after dp2 %d %d %lld\n",t,i,dp2[t][i]);
			if(i!=p&&j!=p) if(i!=j)
			{
				long long plu = (dp1[mn[j+1][i]][j+1]*dp2[mn[j+1][i]][i])%998244353;
				plu = (plu*dp1[mn[p+1][j]][p+1])%998244353;
				plu = (plu*dp2[mn[p+1][j]][j])%998244353;
				dp2[t][i] = (dp2[t][i] + plu) % 998244353;
			}
			if(i!=p&&j!=p) if(i==j) dp2[t][i] = (dp2[t][i] + dp1[mn[p+1][i]][p+1]*dp2[mn[p+1][i]][i]) % 998244353;	
		}
	}
	//for(int i = 1;i<=n;i++) for(int j = 1;j<=n;j++) printf("dp1[%d][%d] = %lld, dp2[%d][%d] = %lld\n",i,j,dp1[i][j],i,j,dp2[i][j]);
	
	printf("%lld\n",(dp1[1][1]*dp2[1][n])%998244353);
}