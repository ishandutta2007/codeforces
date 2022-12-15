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
	int n;
	cin>>n;
	vector<int> a(n+1);
	int ans=n;
	set<int> q;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		q.insert(a[i]);
	}
	for(int i=4;i<=n;++i)
	{
		if(a[i]==a[i-2]&&a[i-1]==a[i-3]) --ans,++i;
	}
	if(q.size()>=3) ans=n;
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