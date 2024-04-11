#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-8)
void solve()
{
	int n,h;
	cin>>n>>h;
	vector<int> a(n+1);
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	sort(a.begin()+1,a.end());
	vector dp(n+1,vector<int>(8));
	dp[0][0]=h;
	vector<int> tmp(3);
	tmp[0]=tmp[1]=2;
	tmp[2]=3;
	auto update=[&](int i) -> void
	{
		for(int s=1;s<8;++s)
		{
			for(int k=0;k<3;++k) if((s>>k)&1)
			{
				dp[i][s]=max(dp[i][s],dp[i][s^(1<<k)]*tmp[k]);
			}
		}
	};
	update(0);
	int maxn=0;
	for(int i=1;i<=n;++i)
	{
		for(int s=0;s<8;++s)
		{
			if(dp[i-1][s]>a[i])
			{
				dp[i][s]=max(dp[i][s],dp[i-1][s]+a[i]/2);
				maxn=i;
			}
		}
		update(i);
	}
	// cout<<dp[1][0]<<endl;
	cout<<maxn<<'\n';
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1; cin>>T;
	while(T--) solve();
	return 0;
}