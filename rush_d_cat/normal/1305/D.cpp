#include <bits/stdc++.h>
using namespace std;
const int N=1000+10;
int n,vis[N],dep[N],par[N],M[N][N],X;
vector<int> g[N];
void dfs(int u,int p){
	par[u]=p; dep[u]=dep[p]+1;
	for(auto v: g[u]) {
		if(v==p)continue;
		dfs(v,u);
	}
}
void tagPath(int u,int v) {
	printf("? %d %d\n", u,v); fflush(stdout);
	int x; scanf("%d",&x); X=x;
	if (M[u][v]) {
		printf("! %d\n", x); 
		fflush(stdout);
		exit(0);
	}
	while(u!=v) {
		if(dep[u]==dep[v]){
			if(u!=x) vis[u]=1; 
			u=par[u]; 
			if(v!=x) vis[v]=1;
			v=par[v]; 
			continue;
		}

		if(dep[u]>dep[v]){
			if(u!=x) vis[u]=1;
			u=par[u]; 
		} else if(dep[v]>dep[u]){
			if(v!=x) vis[v]=1;
			v=par[v]; 
		}
		//printf("u=%d, v=%d\n", u,v);
	}
	if(v!=x) vis[v]=1;
	v=par[v]; 
}
pair<int,int> Dia(int u) {
	int A,B;

	{
		queue<int> q;
		int dis[N];
		memset(dis,-1,sizeof(dis));
		dis[u]=0; q.push(u);
		while(q.size()) {
			int now=q.front(); q.pop();
			for(auto v:g[now]){
				if(dis[v]==-1&&vis[v]==0){
					dis[v]=dis[now]+1; q.push(v);
				}
			}
		}
		int mx=-1,pos=u;
		for(int i=1;i<=n;i++){
			if(dis[i]>=mx){
				mx=dis[i]; pos=i;
			}
		}
		A=pos;
	}

	u=A;
	//printf("A=%d\n", A);

	{
		queue<int> q;
		int dis[N];
		memset(dis,-1,sizeof(dis));
		dis[u]=0; q.push(u);
		while(q.size()) {
			int now=q.front(); q.pop();
			for(auto v:g[now]){
				if(dis[v]==-1&&vis[v]==0){
					dis[v]=dis[now]+1; q.push(v);
				}
			}
		}
		int mx=-1,pos=u;
		for(int i=1;i<=n;i++){
			//printf("dis[%d] = %d\n", i,dis[i]);
			if(dis[i]>=mx){
				mx=dis[i]; pos=i;
			}
		}
		B=pos;
	}
	return make_pair(A,B);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v; scanf("%d%d",&u,&v);
		g[u].push_back(v); g[v].push_back(u);
		M[u][v]=M[v][u]=1;
	}
	dfs(1,1);
	X=1;
	while(1) {
		pair<int,int> path = Dia(X);
		if(path.first == path.second) {
			printf("! %d\n", path.first); 
			fflush(stdout); return 0;
		}
		tagPath(path.first, path.second);
	}
}