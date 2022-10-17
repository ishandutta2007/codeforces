#include<bits/stdc++.h>
#define MAXN 200005
#define LL long long
#define LD long double
#define INF int(1e9+7)
#define mkp make_pair
#define fir first
#define sec second
#define base int(1e9)
#define W int(9)
using namespace std;
int N;
vector<int> adj[MAXN];
int vis[MAXN],sz[MAXN],fa[MAXN];
LL d[MAXN],g[MAXN];
void dfs1(int u) {
	vis[u]=1;
	sz[u]=1;
	int v;
	for(int k=0;k<adj[u].size();k++){
		v=adj[u][k];
		if(vis[v]){
			continue;
		}
		fa[v]=u;
		dfs1(v);
		sz[u]+=sz[v];
		d[u]+=d[v];
	}
	d[u]+=sz[u];
}
void dfs2(int u) {
	vis[u] = 1;
	int v;
	for(int k=0; k<adj[u].size(); k++) {
		v = adj[u][k];
		if(vis[v]) continue;
		g[v]=(N-sz[v]) + g[u] + d[u] - sz[u] - d[v];
		dfs2(v);
	}
}
int main() {
	cin>>N;
	int u,v;
	for(int i=1; i<N; i++) {
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs1(1);
	memset(vis,0,sizeof(vis));
	dfs2(1);
	LL ans = 0;
	for(int i=1; i<=N; i++) {
		ans = max(ans, d[i] + g[i] + (N-sz[i]));
	}
	cout<<ans<<endl;
	return 0;
}