#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
const int N=2005;
int n,m,dp[N][N],ans;
signed main()
{
	cin>>n>>m;
	for (int i=1;i<=m;i++) dp[1][i]=1;
	for (int i=2;i<=n;i++)
	{
		int sum=0;
		dp[i][1]=1;
		for (int j=2;j<=m;j++)
		{
			(sum+=dp[i-1][j])%=mod;
			dp[i][j]=(dp[i][j-1]+sum)%mod;
		}
	}
	for (int i=1;i<=n;i++)
		for (int j=2;j<=m;j++)
			(ans+=1ll*(dp[i][j]-dp[i-1][j]+mod)*dp[n-i+1][j]%mod*(m-j+1)%mod)%=mod;
	cout<<ans<<endl;
}