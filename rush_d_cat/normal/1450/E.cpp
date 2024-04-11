#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200 + 10;
int n,m;
vector< pair<int,int> > g[N];

int vis[N],ok=1;
int d[N][N];
int f[N][N], ans[N];
void dfs(int u){
	for(auto e:g[u]){
		if(vis[e.first] == 0) {
			vis[e.first] = 3 - vis[u];
			dfs(e.first);
		}else{
			if(vis[e.first] == vis[u]) ok=0;
		}
	}
}
int uu[2002],vv[2002],xx[2002];
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v,x; scanf("%d%d%d",&u,&v,&x); 
		swap(u,v);
		uu[i]=u,vv[i]=v,xx[i]=x;
		if(x==0){
			g[u].push_back(make_pair(v,1));
			g[v].push_back(make_pair(u,1));
		}else{
			g[u].push_back(make_pair(v,1));
			g[v].push_back(make_pair(u,-1));
		}
	}	

	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1; dfs(i);
		}
	}

	if(!ok) return !printf("NO\n");
	/*
	for(int i=1;i<=n+1;i++)for(int j=1;j<=n;j++)f[i][j]=1e9;
	for(int u=1;u<=n;u++){
		for(auto e:g[u]){
			printf("%d -> %d %d\n", u, e.first, e.second);
		}
	}
	for(int i=1;i<=n+1;i++){
		for(int u=1;u<=n;u++){
			for(auto e:g[u]){
				int v=e.first;
				if(i==n+1 && f[i-1][u]+e.second < f[i][v]) ok=false;
				f[i][v]=min(f[i][v],f[i-1][u]+e.second);
			}
		}
		for(int u=1;u<=n;u++){
			printf("f[%d][%d]=%d\n", i,u,f[i][u]);
		}
	}
	*/
	//if(!ok) return !printf("NO\n");

	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
		d[i][j]=i==j?0:1e9;
	for(int i=1;i<=n;i++)for(auto e:g[i]){
		d[i][e.first]=e.second;
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	}
	int mx=-1e9,s,t;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(d[i][j] > mx){
				s=i,t=j;mx=d[i][j]; 
			}
		}
	}
	//printf("mx=%d\n",mx);
	for(int i=1;i<=n;i++) ans[i]=mx+1-d[s][i];
	for(int i=1;i<=n;i++){
		if(ans[i] < 0) ok = 0;
	}
	for(int i=1;i<=m;i++){
		if(xx[i]==0 && abs(ans[uu[i]] - ans[vv[i]]) != 1) ok=0;
		if(xx[i]==1 && ans[uu[i]] - ans[vv[i]] != 1) ok = 0;
	}
	if(!ok) return !printf("NO\n");
	printf("YES\n");
	printf("%d\n", mx);
	for(int i=1;i<=n;i++){
		printf("%d ", mx + 1 - d[s][i]);
	}
	printf("\n");
}