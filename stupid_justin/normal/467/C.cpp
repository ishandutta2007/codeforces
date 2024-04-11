#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
int a[N],sum[N];
int dp[N][N];
int n,m,k;
int x,cnt;
signed main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]+a[i];
	x=m-1;
	for(int i=m;i<=n;i++)
	{
		cnt=sum[i]-sum[i-x-1];
		for(int j=1;j<=k;j++)
			dp[i][j]=max(dp[i-1][j],dp[i-m][j-1]+cnt);
	}
	cout<<dp[n][k]<<endl;
}