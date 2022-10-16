#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define Maxn 500000
#define ll long long
ll f[Maxn+5];
int sz[Maxn+5];
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
void init_dfs(int u,int fa){
	sz[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		init_dfs(v,u);
		sz[u]+=sz[v];
	}
}
void work_dfs(int u,int fa){
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		f[v]=f[u]+1ll*(sz[u]-sz[v])*sz[v];
		work_dfs(v,u);
	}
}
int main(){
	int n;
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	init_dfs(1,0);
	f[1]=0;
	work_dfs(1,0);
	u=0;
	for(int i=1;i<=n;i++){
		if(f[i]>f[u]){
			u=i;
		}
	}
	init_dfs(u,0);
	f[u]=0;
	work_dfs(u,0);
	v=0;
	for(int i=1;i<=n;i++){
		if(f[i]>f[v]){
			v=i;
		}
	}
	cout<<f[v]+1ll*n*(n-1)/2<<endl;
	return 0;
}