#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
#define lowbit(i) ((i)&(-i))
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;++i) cin>>a[i];
	auto check=[&]() -> int
	{
		int sum=0;
		int sum1=0,sum0=0;
		// for(int i=1;i<=n;++i) cout<<a[i]<<' ';
			// cout<<'\n';
		for(int i=1;i<=n;++i)
		{
			if(a[i]==0) sum+=sum1,++sum0;
			else ++sum1;
		}
		return sum;
	};
	int ans=check();
	for(int i=1;i<=n;++i)
	{
		if(a[i]==0)
		{
			a[i]=1;
			ans=max(check(),ans);
			a[i]=0;
			break;
		}
	}
	for(int i=n;i>=1;--i)
	{
		if(a[i]==1)
		{
			a[i]=0;
			ans=max(check(),ans);
			a[i]=1;
			break;
		}
	}
	cout<<ans<<'\n';
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1; cin>>T;
	while(T--) solve();
	return 0;
}