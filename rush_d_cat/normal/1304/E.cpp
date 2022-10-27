#include <bits/stdc++.h>
using namespace std;
const int N=100000+10;
int n;
vector<int> g[N];
int dep[N],par[N][20];
void dfs(int u,int p){
	par[u][0]=p; dep[u]=dep[p]+1;
	for(auto v:g[u]){
		if(v==p)continue;
		dfs(v,u);
	}
}
int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	int d=dep[u]-dep[v];
	for(int i=19;i>=0;i--)if(d>>i&1)u=par[u][i];
	if(u==v)return u;
	for(int i=19;i>=0;i--)if(par[u][i]!=par[v][i])u=par[u][i],v=par[v][i];
	return par[u][0];
}
int dis(int u,int v){
	//printf("u=%d,v=%d,lca=%d\n", u,v,lca(u,v));
	return dep[u]+dep[v]-2*dep[lca(u,v)];
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v; scanf("%d%d",&u,&v);
		g[u].push_back(v); g[v].push_back(u);
	}
	dfs(1,1);
	for(int i=1;i<20;i++)for(int j=1;j<=n;j++)par[j][i]=par[par[j][i-1]][i-1];
	int q; scanf("%d",&q);
	while(q--){
		int x,y,a,b,k;scanf("%d%d%d%d%d",&a,&b,&x,&y,&k);//1 4 1 3 2
		//printf("# %d\n", dis(x,y));
		if(dis(x,y)<=k && dis(x,y)%2==k%2){
			printf("YES\n");continue;
		} 
		int tmp=dis(x,a)+1+dis(b,y);
		//printf("dis(%d,%d)=%d, dis(%d,%d)=%d, tmp=%d\n", x,a,dis(x,a),b,y,dis(b,y),tmp);
		if(tmp<=k && tmp%2==k%2){
			printf("YES\n");continue;
		}
		tmp=dis(x,b)+1+dis(a,y);
		if(tmp<=k && tmp%2==k%2){
			printf("YES\n");continue;
		}
		printf("NO\n");
	}
}