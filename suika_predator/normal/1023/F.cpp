#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int n,m,k;
	cin>>n>>k>>m;
	vector<int> pa(n+5);
	function<int(int)> find=[&](int x){return pa[x]?pa[x]=find(pa[x]):x;};
	vector<vector<pair<int,int>>> G(n+5);
	for(int i=1;i<=k;i++)
	{
		int u,v;
		cin>>u>>v;
		int pu=find(u),pv=find(v);
		if(pu!=pv)pa[pv]=pu;
		G[u].emplace_back(v,0);
		G[v].emplace_back(u,0);
	}
	vector<tuple<int,int,int>> eg;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		int pu=find(u),pv=find(v);
		if(pu!=pv)
		{
			G[u].emplace_back(v,w);
			G[v].emplace_back(u,w);
			pa[pv]=pu;
			continue;
		}
		eg.emplace_back(w,u,v);
	}
	pa.clear();
	pa.resize(n+5);
	vector<int> up(n+5);
	vector<int> pe(n+5);
	vector<int> dep(n+5);
	function<void(int)> dfs=[&](int u)
	{
		for(auto [v,w]:G[u])
		{
			if(dep[v]==0)
			{
				pe[v]=-1;
				dep[v]=dep[u]+1;
				up[v]=u;
				if(w)pa[v]=u,pe[v]=0;
				dfs(v);
			}
		}
	};
	dep[1]=1;
	dfs(1);
	for(auto [w,u,v]:eg)
	{
		u=find(u);
		v=find(v);
		while(u!=v)
		{
			if(dep[u]>dep[v])
			{
				pe[u]=w;
				assert(up[u]);
				pa[u]=up[u];
				u=find(u);
			}
			else
			{
				pe[v]=w;
				assert(up[v]);
				pa[v]=up[v];
				v=find(v);
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		if(pe[i]==-1)
		{
			cout<<-1<<endl;
			return 0;
		}
		ans+=pe[i];
	}
	cout<<ans<<endl;
	return 0;
}