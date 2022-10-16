#include<bits/stdc++.h>
using namespace std;
int s[111111][40];
int n,k;
vector<int> G[111111];
int a[111111];
int ord[233333],ind;
inline void add(int u,int v)
{
	for(int i=0;i<k+k;i++)
	{
		s[u][(i+1)%(k+k)]^=s[v][i];
	}
}
int vis[111111];
void dfs(int u)
{
	vis[u]=1;
	ord[++ind]=u;
	s[u][0]=a[u];
	for(auto v:G[u])
	{
		if(!vis[v])
		{
			dfs(v);
			ord[++ind]=u;
			add(u,v);
		}
	}
}
int ans[111111];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	int u,v;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1);
//	for(int i=1;i<=n;i++)
//		for(int j=0;j<k+k;j++)
//			cerr<<i<<' '<<j<<' '<<s[i][j]<<endl;
	for(int i=2;i<=ind;i++)
	{
		add(ord[i-1],ord[i]);
		add(ord[i],ord[i-1]);
		int u=ord[i];
		ans[u]=0;
		for(int j=k;j<k+k;j++)
			ans[u]^=s[u][j];
	}
	for(int i=1;i<=n;i++)
	{
		cout<<(ans[i]!=0)<<' ';
	}
	cout<<endl;
	return 0;
}