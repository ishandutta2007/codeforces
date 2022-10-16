#include <cstdio>
#include <algorithm>
const int Maxn=300000;
int n,m;
int fa[20][Maxn+5];
int head[Maxn+5],nxt[Maxn+5];
void add_edge(int from,int to){
	nxt[to]=head[from];
	head[from]=to;
}
namespace BIT{
	int f[Maxn+5];
	void add(int x,int a){
		for(int i=x;i<=n;i+=(i&(-i))){
			f[i]+=a;
		}
	}
	int query(int x){
		int ans=0;
		for(int i=x;i>0;i-=(i&(-i))){
			ans+=f[i];
		}
		return ans;
	}
	int query(int l,int r){
		return query(r)-query(l-1);
	}
}
struct Node{
	int x,y,v;
}a[Maxn+5];
int dfn[Maxn+5],sz[Maxn+5],dep[Maxn+5];
int dfn_tot;
void init_dfs(int u){
	for(int i=1;fa[i-1][fa[i-1][u]];i++){
		fa[i][u]=fa[i-1][fa[i-1][u]];
	}
	sz[u]=1;
	dep[u]=dep[fa[0][u]]+1;
	dfn[u]=++dfn_tot;
	for(int v=head[u];v;v=nxt[v]){
		init_dfs(v);
		sz[u]+=sz[v];
	}
}
bool query(int u,int v,int d){
	if(d==1){
		int num=BIT::query(n)-BIT::query(dfn[u],dfn[u]+sz[u]-1)-BIT::query(dfn[v],dfn[v]+sz[v]-1);
		if(num==0){
			return 0;
		}
		return 1;
	}
	int num=BIT::query(dfn[u],dfn[u]+sz[u]-1)-BIT::query(dfn[v],dfn[v]+sz[v]-1);
	if(num==0){
		return 0;
	}
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++){
		scanf("%d",&fa[0][i]);
		add_edge(fa[0][i],i);
	}
	init_dfs(1);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		if(dep[a[i].x]>dep[a[i].y]){
			std::swap(a[i].x,a[i].y);
		}
		if(fa[0][a[i].y]==a[i].x){
			puts("-1");
			return 0;
		}
		if(dfn[a[i].x]<=dfn[a[i].y]&&dfn[a[i].x]+sz[a[i].x]>dfn[a[i].y]){
			a[i].v=dep[a[i].x]+1;
		}
		else{
			a[i].v=1;
		}
	}
	std::sort(a+1,a+1+m,[&](Node a,Node b){return a.v>b.v;});
	int ans=0;
	for(int i=1;i<=m;i++){
		int u=a[i].x;
		if(a[i].v!=1){
			u=a[i].y;
			for(int j=19;j>=0;j--){
				if(dep[u]-(1<<j)<=dep[a[i].x]){
					continue;
				}
				u=fa[j][u];
			}
		}
		if(query(u,a[i].y,a[i].v)){
			continue;
		}
		if(a[i].v==1){
			BIT::add(dfn[1],1);
		}
		else{
			BIT::add(dfn[u],1);
		}
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}