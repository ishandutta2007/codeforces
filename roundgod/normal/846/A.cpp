#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],dp[MAXN][2];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dp[0][0]=dp[0][1]=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0) dp[i][0]=dp[i-1][0]+1; else dp[i][0]=dp[i-1][0];
		if(a[i]==1) dp[i][1]=max(dp[i-1][1]+1,dp[i-1][0]+1); else dp[i][1]=dp[i-1][1];
	}
	printf("%d\n",max(dp[n][0],dp[n][1]));
	return 0;
}