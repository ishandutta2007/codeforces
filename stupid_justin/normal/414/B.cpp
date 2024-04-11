#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
const int N=2005;
int n,m;
int ans;
int dp[N][N];
signed main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++) dp[1][i]=1;
	for (int i=2;i<=m;i++)
		for (int j=1;j<=n;j++)
			for (int k=1;k<=n/j;k++)
				dp[i][j]+=dp[i-1][k*j],dp[i][j]%=mod;
	for (int i=1;i<=n;i++) ans+=dp[m][i];
	cout<<ans%mod<<endl;
}