#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<int> w(n+5),pa(n+5);
	vector<vector<pair<int,int>>> G(n+5);
	vector<long long> up(n+5);
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<n;i++)
	{
		int u,v,c;
		cin>>u>>v>>c;
		G[u].emplace_back(v,c);
		G[v].emplace_back(u,c);
	}
	long long ans=*max_element(up.begin(),up.end());
	function<void(int)> dfs1=[&](int u)
	{
		vector<long long> tmp;
		for(auto [v,c]:G[u])
		{
			if(v!=pa[u])
			{
				pa[v]=u;
				dfs1(v);
				tmp.emplace_back(up[v]-c);
			}
		}
		for(int i=1;i<=2;i++)tmp.push_back(0);
		sort(tmp.begin(),tmp.end(),greater<long long>());
		up[u]=tmp[0]+w[u];
		ans=max(ans,tmp[0]+tmp[1]+w[u]);
	};
	dfs1(1);
	cout<<ans<<endl;
	return 0;
}