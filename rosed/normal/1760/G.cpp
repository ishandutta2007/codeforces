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
	int n,a,b;
	cin>>n>>a>>b;
	typedef array<int,2> pr;
	vector<vector<pr> > eg(n+1);
	for(int i=1;i<n;++i)
	{
		int x,y,z;
		cin>>x>>y>>z;
		eg[x].emplace_back(pr{y,z});
		eg[y].emplace_back(pr{x,z});
	}
	vector<int> dis(n+1);
	map<int,int> q;
	function<void(int,int)> dfs=[&](int now,int fa) -> void
	{
		if(now!=b) q[dis[now]]=1;
		for(auto [t,v]:eg[now])
		{
			if(t==fa) continue;
			dis[t]=dis[now]^v;
			dfs(t,now);
		}
	};
	dfs(b,0);
	bool flag=0;
	function<void(int,int,int)> dfs2=[&](int now,int fa,int val) -> void
	{
		if(q[val]) flag=1;
		for(auto [t,v]:eg[now])
		{
			if(t==fa||t==b) continue;
			dfs2(t,now,val^v);
		}
	};
	dfs2(a,0,0);
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