#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[1<<22],num[1<<22],dp[1<<22];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		num[a[i]]++;
	}
	dp[0]=INF;
	for(int mask=1;mask<(1<<22);mask++)
	{
		dp[mask]=(num[mask]==0)?INF:mask;
		if(mask&1) dp[mask]=min(dp[mask],dp[mask^1]);
		for(int i=1;i<=22;i++)
			if(mask&(1<<i)) dp[mask]=min(dp[mask],dp[mask^(1<<i)]);
		//printf("%d %d\n",mask,dp[mask][22]);
	}
	for(int i=0;i<n;i++)
	{
		int t=(1<<22)-1-a[i];
		printf("%d ",dp[t]==INF?-1:dp[t]);
	}
	return 0;
}