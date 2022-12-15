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
	vector<int> a(n+1),pre(n+1),suf(n+1);
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		if(a[i]!=a[i-1]) pre[i]=i-1;
		else pre[i]=pre[i-1];
	}
	for(int i=n;i>=1;--i)
	{
		if(i==n||a[i]!=a[i+1]) suf[i]=i+1;
		else suf[i]=suf[i+1];
	}
	bool flag=1;
	for(int i=2;i<n;++i)
	{
		if(pre[i]!=0&&suf[i]<=n&&a[i]>a[pre[i]]&&a[i]>a[suf[i]]) flag=0;
	}
	if(flag) cout<<"YES\n";
	else cout<<"NO\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1; cin>>T;
	while(T--) solve();
	return 0;
}