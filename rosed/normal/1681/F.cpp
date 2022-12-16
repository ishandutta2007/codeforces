#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
	const int N=5e5+10,inf=2e9;
	int n,m,ans;
	typedef pair<int,int> pr;
	vector<pr> eg[N];
	vector<int> g[N];
	int str[N],f[N*2];
	inline void dfs1(int now,int fa)
	{
		str[now]=1;
		for(auto [t,c]:eg[now])
		{
			if(t==fa) continue;
			g[c].emplace_back(t);
			dfs1(t,now);
			str[now]+=str[t];
			g[c].pop_back();
			f[g[c].back()]-=str[t];
		}
		f[now]+=str[now];
	}
	inline void dfs2(int now,int fa)
	{
		for(auto [t,c]:eg[now])
		{
			if(t==fa) continue;
			ans+=f[t]*f[g[c].back()];
			g[c].emplace_back(t);
			dfs2(t,now);
			g[c].pop_back();
		}
	}
	inline void main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		cin>>n;
		for(int i=1;i<n;++i)
		{
			int x,y,z;
			cin>>x>>y>>z;
			eg[x].emplace_back(pr(y,z));
			eg[y].emplace_back(pr(x,z));
		}
		for(int i=1;i<=n;++i)
		{
			g[i].emplace_back(i+n);
		}
		for(int i=1;i<=n;++i) f[i+n]=n;
		dfs1(1,0);
		dfs2(1,0);
		cout<<ans<<'\n';
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
212
*/