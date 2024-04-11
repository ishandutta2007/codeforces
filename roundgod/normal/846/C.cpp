#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN],sum[MAXN],dp[MAXN][4],pre[MAXN][4];
int main()
{
	scanf("%I64d",&n);
	sum[0]=0;
	for(ll i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	memset(dp,0,sizeof(dp));
	memset(pre,0,sizeof(pre));
	for(ll i=1;i<=n;i++)
	{
		dp[i][0]=sum[i];
		for(ll j=0;j<=i;j++)
		{
			if(dp[j][0]-sum[i]+sum[j]>dp[i][1])
			{
				dp[i][1]=dp[j][0]-sum[i]+sum[j];
				pre[i][1]=j;
			}
			if(dp[j][1]+sum[i]-sum[j]>dp[i][2])
			{
				dp[i][2]=dp[j][1]+sum[i]-sum[j];
				pre[i][2]=j;
			}
			if(dp[j][2]-sum[i]+sum[j]>dp[i][3])
			{
				dp[i][3]=dp[j][2]-sum[i]+sum[j];
				pre[i][3]=j;
			}
		}
	}
	printf("%I64d %I64d %I64d\n",pre[pre[pre[n][3]][2]][1],pre[pre[n][3]][2],pre[n][3]);
	return 0;
}