#include <bits/stdc++.h>
using namespace std;
const int N = 500000 + 10;
int t, n, m, vis[N], dep[N], par[N], mxdep, who;
vector<int> g[N], vec[N];
void dfs(int u){
	if(dep[u]>=mxdep){
		mxdep=dep[u]; who=u;
	}
	vec[dep[u]].push_back(u);
	vis[u]=1;
	for(auto v:g[u]){
		if(vis[v])continue;
		dep[v]=dep[u]+1;
		par[v]=u;
		dfs(v);
	}
}
int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d",&n,&m);
		mxdep=-1;
		for(int i=0;i<=n;i++){
			g[i].clear(); vis[i]=0; vec[i].clear(); dep[i]=0; par[i]=0;
		}
		for(int i=1;i<=m;i++){
			int u,v; scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1);
		vector< pair<int,int> > ans;
		for(int i=0;i<=n;i++){
			for(int j=0;j+1<vec[i].size();j+=2){
				ans.push_back(make_pair(vec[i][j],vec[i][j+1]));
			}
		}
		if(ans.size()*2>=(n+1)/2){
			printf("PAIRING\n");
			printf("%d\n", ans.size());
			for(auto p:ans){
				printf("%d %d\n", p.first,p.second);
			}
		}else{
			int now=who;
			vector<int> path;
			while(now){
				path.push_back(now);
				now=par[now];
			}
			printf("PATH\n");
			printf("%d\n", path.size());
			for(auto x:path)printf("%d ", x);
			printf("\n");
		}
	}
}