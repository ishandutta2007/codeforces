#include "bits/stdc++.h"
using namespace std;
const int N=2e5+2;
int b[N],f[N];
vector<int> e[N];
void dfs(int u) {for (int v:e[u]) if (v!=f[u]) f[v]=u,dfs(v);}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j,x,y;
		cin>>n>>m>>x>>y;
		fill_n(b+1,n,0);fill_n(f+1,n,0);
		for (i=1;i<=n;i++) e[i].clear();
		vector<int> a(m);
		for (int &u:a) cin>>u;
		for (i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(x);
		for (int u:a) while (u!=x&&!b[u]) b[u]=2,u=f[u];
		while (y!=x) b[y]=1,y=f[y];
		cout<<accumulate(b+1,b+n+1,0)<<'\n';
	}
}