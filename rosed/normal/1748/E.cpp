// LUOGU_RID: 96095232
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-8)
const int mod=1e9+7;
const int inf=1e18;
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1);
	vector f(n+1,vector<int>(21,inf));
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		f[i][0]=a[i];
	}
	for(int k=1;k<=20;++k)
	{
		for(int i=1;i+(1<<k)-1<=n;++i)
		{
			f[i][k]=max(f[i][k-1],f[i+(1<<(k-1))][k-1]);
		}
	}
	auto getmax=[&](int l,int r) -> int
	{
		int k=__lg(r-l+1);
		return max(f[l][k],f[r-(1<<k)+1][k]);
	};
	vector dp(n+1,vector<int>(m+1));
	for(int i=0;i<=m;++i) dp[0][i]=1;
	function<int(int,int)> solve=[&](int l,int r) -> int
	{
		if(l>r) return 0;
		int val=getmax(l,r),tmp=l;
		for(int k=20;~k;--k)
		{
			if(f[tmp][k]<val) tmp+=(1<<k);
		}
		if(a[tmp]!=val) ++tmp;
		int t1=solve(l,tmp-1),t2=solve(tmp+1,r);
		for(int i=1;i<=m;++i)
		{
			dp[tmp][i]=(dp[tmp][i-1]+dp[t1][i-1]*dp[t2][i])%mod;
		}
		return tmp;
	};
	cout<<dp[solve(1,n)][m]<<'\n';
}
signed main()
{ 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1; cin>>T;
	while(T--) solve();
	return 0;
}