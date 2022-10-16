#include<bits/stdc++.h>
using namespace std;
vector<int> G[111111];
int pa[111111],deg[111111];
vector<int> son[111111];
inline void addedge(int u,int v)
{
	G[u].push_back(v);
	G[v].push_back(u);
	deg[u]++,deg[v]++;
}
void dfs(int u)
{
	for(auto x:G[u])
	{
		if(x!=pa[u])
		{
			son[u].push_back(x);
			pa[x]=u;
			dfs(x);
		}
	}
}
int maxd=0;
vector<pair<int,int> >ans;
void gao(int u,int cur)
{
	int t=cur,cnt=son[u].size();
	for(auto x:son[u])
	{
//		cerr<<u<<"->"<<x<<' '<<cur<<endl;
		ans.push_back(make_pair(u,cur));
		if(cur==maxd)
		{
			cur-=cnt+1;
			ans.push_back(make_pair(u,cur));
		}
		cur++;
		gao(x,cur);
	}
	ans.push_back(make_pair(u,cur));
	if(u!=1&&cur!=t-1)ans.push_back(make_pair(u,t-1));
}
int n,m,k;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	if(n==1)
	{
		cout<<1<<endl<<1<<' '<<0<<endl;
		return 0;
	}
	int x,y;
	for(int i=1;i<n;i++)
	{
		cin>>x>>y;
		addedge(x,y);
	}
	for(int i=1;i<=n;i++)maxd=max(maxd,deg[i]);
//	cerr<<maxd<<endl;
	dfs(1);
	gao(1,0);
	cout<<ans.size()<<endl;
	for(auto x:ans)
	{
		cout<<x.first<<' '<<x.second<<endl;
	}
	return 0;
}