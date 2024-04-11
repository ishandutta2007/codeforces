#include<bits/stdc++.h>
using namespace std;
pair<int,int> query(const vector<int> &vec)
{
	assert(!vec.empty());
	cout<<"? "<<vec.size();
	for(auto x:vec)cout<<' '<<x;
	cout<<endl;
	int a,b;
	cin>>a>>b;
	return make_pair(a,b);
}
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		vector<vector<int>> G(n+5);
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		vector<int> tmp;
		for(int i=1;i<=n;i++)
		{
			tmp.push_back(i);
		}
		auto [root,dis]=query(tmp);
		vector<int> dep(n+5),h(n+5);
		function<void(int)> dfs1=[&](int u)
		{
			for(auto v:G[u])
			{
				if(not dep[v])
				{
					dep[v]=dep[u]+1;
					dfs1(v);
					h[u]=max(h[u],h[v]+1);
				}
			}
			h[u]=max(h[u],1);
		};
		dep[root]=1;
		dfs1(root);
		int sp=0;
		int l=1,r=1;
		for(auto v:G[root])
		{
			if(h[v]>n/2)sp=v;
			else r=max(r,h[v]+1);
		}
		function<void(int)> dfs2=[&](int u)
		{
			for(auto v:G[u])
			{
				if(v==root)continue;
				if(dep[v])
				{
					dep[v]=0;
					dfs2(v);
				}
			}
		};
		dfs2(sp);
		int core=root;
		while(l<r)
		{
//			cerr<<"binary search "<<l<<' '<<r<<endl;
			int mid=(l+r+1)/2;
			tmp.clear();
			for(int i=1;i<=n;i++)
				if(dep[i]==mid)
					tmp.push_back(i);
			auto [u,d]=query(tmp);
			if(d!=dis)r=mid-1;
			else l=mid,core=u;
		}
		dep.clear();dep.resize(n+5);
		dep[core]=1;
		dfs1(core);
		tmp.clear();
		for(int i=1;i<=n;i++)
		{
			if(dep[i]==dis+1)
				tmp.push_back(i);
		}
		auto [u,d]=query(tmp);
		cout<<"! "<<core<<' '<<u<<endl;
		string res;
		cin>>res;
	}
	
	return 0;
}