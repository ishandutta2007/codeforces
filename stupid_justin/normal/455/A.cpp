#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int c[N],dp[N];
int n;
void init()
{
	memset(dp,0,sizeof(dp));
	memset(c,0,sizeof(c));
}
signed main()
{
	cin>>n;
	init();
	int maxx=0;
	for (int i=1;i<=n;i++)
	{
		int jyz;
		cin>>jyz;
		if(jyz>maxx)
			maxx=jyz;
		c[jyz]++;
	}
	dp[0]=0,dp[1]=c[1];
	for (int i=2;i<=maxx;i++)
		dp[i]=max(dp[i-1],dp[i-2]+c[i]*i);
	cout<<dp[maxx]<<endl;
}