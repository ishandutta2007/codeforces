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
	typedef array<int,2> pr;
	vector<pr> a(n+1);
	for(int i=1;i<=n;++i)
	{
		cin>>a[i][0];
		a[i][1]=i;
	}
	sort(a.begin()+1,a.end());
	vector<int> ans(n+1);
	for(int i=1;i<n;++i)
	{
		ans[a[i][1]]=a[i][0]-a[n][0];
	}
	ans[a[n][1]]=a[n][0]-a[n-1][0];
	for(int i=1;i<=n;++i) cout<<ans[i]<<' ';
		cout<<'\n';
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1; cin>>T;
	while(T--) solve();
	return 0;
}