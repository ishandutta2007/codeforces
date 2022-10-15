#include<bits/stdc++.h>
#define MAXN 3005
#define F ifrst
#define S second
#define MOD 1000000007
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],dp[MAXN][4];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	memset(dp,-1,sizeof(dp));
	dp[0][0]=dp[0][1]=dp[0][2]=dp[0][3]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<4;j++)
		{
			dp[i][0]=a[i]==1?dp[i-1][0]+1:dp[i-1][0];
			dp[i][1]=a[i]==2?max(dp[i-1][0]+1,dp[i-1][1]+1):dp[i-1][1];
			dp[i][2]=a[i]==1?max(dp[i-1][1]+1,dp[i-1][2]+1):dp[i-1][2];
			dp[i][3]=a[i]==2?max(dp[i-1][2]+1,dp[i-1][3]+1):dp[i-1][3];
		}
	}
	printf("%d\n",max(max(dp[n][3],dp[n][2]),max(dp[n][2],dp[n][1])));
	return 0;
}