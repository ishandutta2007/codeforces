#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-8)
const int N=5e5+10,inf=2e9;
int n,m;
int a[N];
int dp[N][32];
int tmp[32];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int qwq;
	cin>>qwq;
	while(qwq--)
	{
		cin>>n>>m;
		int ans=-inf*inf;
		for(int i=1;i<=n;++i)
		{
			cin>>a[i];
			
		}
		for(int i=0;i<=n;++i)
		{
			for(int k=0;k<=31;++k) dp[i][k]=-inf*inf;
		}
		dp[0][0]=0;
		for(int i=1;i<=n;++i)
		{
			for(int k=31;k>=0;--k)
			{
				dp[i][k]=dp[i-1][k]+(a[i]>>k)-m;
				if(k>0) dp[i][k]=max(dp[i][k],dp[i-1][k-1]+(a[i]>>k));
				if(k==31) dp[i][k]=max(dp[i][k],dp[i-1][k]);
				//cout<<i<<' '<<k<<' '<<dp[i][k]<<"!!"<<endl;
				if(i==n) ans=max(ans,dp[i][k]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
1
3 12
10 10 29

*/