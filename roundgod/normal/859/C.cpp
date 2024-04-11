#include<bits/stdc++.h>
#define MAXN 55
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],sum[MAXN],dp[MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	memset(dp,0,sizeof(dp));
	dp[n]=a[n];
	for(int i=n-1;i>=1;i--)
		dp[i]=max(dp[i+1],a[i]+sum[n]-sum[i]-dp[i+1]);
	printf("%d %d\n",sum[n]-dp[1],dp[1]);
	return 0;
}