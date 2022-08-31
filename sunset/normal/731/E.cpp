#include<bits/stdc++.h>

using namespace std;

const int maxn=200020;

int dp[maxn];

int n;

int f[maxn];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		f[i]=f[i-1]+x;
	}
	dp[n]=f[n];
	int maxx=dp[n];
	for(int i=n-1;i>=2;i--)
	{
		dp[i]=f[i]-maxx;
		maxx=max(maxx,dp[i]);
	}
	int maxq=-1e9;
	for(int i=2;i<=n;i++)
	{
		maxq=max(maxq,dp[i]);
	}
	cout<<maxq;
}