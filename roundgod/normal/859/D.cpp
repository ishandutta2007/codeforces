#include<bits/stdc++.h>
#define MAXN 200
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
double p[MAXN][MAXN],dp[10][MAXN],dp2[10][MAXN];
int main()
{
	scanf("%d",&n);
	int m=1<<n;
	for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
		{
			scanf("%lf",&p[i][j]);
			p[i][j]/=100.0;
		}
	memset(dp,0,sizeof(dp));
	for(int i=0;i<m;i++)
		dp[0][i]=1.0;
	for(int j=1;j<=n;j++)
	{
		for(int i=0;i<m;i++)
		{
			for(int k=0;k<m;k++)
				if((k>>j)==(i>>j)&&(k>>j-1)!=(i>>j-1)) dp[j][i]+=dp[j-1][k]*p[i][k];
			dp[j][i]*=dp[j-1][i];
		}
	}
	memset(dp2,0,sizeof(dp2));
	for(int i=0;i<m;i++)
		dp2[0][i]=0.0;
	for(int j=1;j<=n;j++)
		for(int i=0;i<m;i++)
			for(int k=0;k<m;k++)
				if((k>>j)==(i>>j)&&(k>>j-1)!=(i>>j-1)) dp2[j][i]=max(dp2[j][i],dp2[j-1][i]+dp2[j-1][k]+dp[j][i]*(1<<(j-1)));
	double ans=0.0;
	for(int i=0;i<m;i++)
		ans=max(ans,dp2[n][i]);
	printf("%.10f\n",ans);
	return 0;
}