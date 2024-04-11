#include <cstdio>
#include <algorithm>
const int Maxn=200000;
int head[Maxn+5],arrive[Maxn+5],nxt[Maxn+5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int n,m,q;
int fa[20][Maxn+5];
int dfn[Maxn+5],sz[Maxn+5],dep[Maxn+5],dfn_tot;
void init_dfs_1(int u){
	dep[u]=dep[fa[0][u]]+1;
	sz[u]=1;
	dfn[u]=++dfn_tot;
	for(int i=1;fa[i-1][fa[i-1][u]];i++){
		fa[i][u]=fa[i-1][fa[i-1][u]];
	}
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa[0][u]){
			continue;
		}
		init_dfs_1(v);
		sz[u]+=sz[v];
	}
}
int find_lca(int u,int v){
	if(dep[u]<dep[v]){
		std::swap(u,v);
	}
	for(int i=19;i>=0;i--){
		if(dep[fa[i][u]]>=dep[v]){
			u=fa[i][u];
		}
	}
	if(u==v){
		return u;
	}
	for(int i=19;i>=0;i--){
		if(fa[i][u]!=fa[i][v]){
			u=fa[i][u],v=fa[i][v];
		}
	}
	return fa[0][u];
}
int g[20][Maxn+5];
void init_dfs_2(int u){
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa[0][u]){
			continue;
		}
		init_dfs_2(v);
		if(g[0][u]==0||(g[0][v]>0&&dep[g[0][v]]<dep[g[0][u]])){
			g[0][u]=g[0][v];
		}
	}
}
struct Operation{
	int l,r,id,op;
	Operation(int _l=0,int _r=0,int _id=0,int _op=0){
		l=_l,r=_r,id=_id,op=_op;
	}
}op[Maxn*5+5];
int op_tot;
int ans[Maxn+5],val[Maxn+5];
bool cmp(Operation a,Operation b){
	if(a.l==b.l){
		return a.id<b.id;
	}
	return a.l<b.l;
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
}
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		scanf("%d",&fa[0][i]);
		add_edge(fa[0][i],i);
	}
	init_dfs_1(1);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		int lca=find_lca(u,v);
		if(dfn[u]>dfn[v]){
			std::swap(u,v);
		}
		if(g[0][u]==0||dep[lca]<dep[g[0][u]]){
			g[0][u]=lca;
		}
		if(g[0][v]==0||dep[lca]<dep[g[0][v]]){
			g[0][v]=lca;
		}
		op[++op_tot]=Operation(dfn[u],dfn[v],0,1);
	}
	init_dfs_2(1);
	for(int i=1;i<=n;i++){
		if(g[0][i]==i){
			g[0][i]=0;
		}
	}
	for(int i=1;i<20;i++){
		for(int j=1;j<=n;j++){
			g[i][j]=g[i-1][g[i-1][j]];
		}
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		int lca=find_lca(u,v);
		if(dfn[u]>dfn[v]){
			std::swap(u,v);
		}
		for(int j=19;j>=0;j--){
			if(g[j][u]&&(dep[g[j][u]]>dep[lca])){
				u=g[j][u];
				ans[i]+=(1<<j);
			}
		}
		for(int j=19;j>=0;j--){
			if(g[j][v]&&(dep[g[j][v]]>dep[lca])){
				v=g[j][v];
				ans[i]+=(1<<j);
			}
		}
		if((g[0][u]==0&&u!=lca)||(g[0][v]==0&&v!=lca)){
			ans[i]=-1;
			continue;
		}
		if(u==lca||v==lca){
			ans[i]++;
		}
		else{
			ans[i]+=2;
			op[++op_tot]=Operation(dfn[u]+sz[u]-1,dfn[v]+sz[v]-1,i,1);
			op[++op_tot]=Operation(dfn[u]-1,dfn[v]+sz[v]-1,i,-1);
			op[++op_tot]=Operation(dfn[u]+sz[u]-1,dfn[v]-1,i,-1);
			op[++op_tot]=Operation(dfn[u]-1,dfn[v]-1,i,1);
		}
	}
	std::sort(op+1,op+1+op_tot,cmp);
	for(int i=1;i<=op_tot;i++){
		if(op[i].id==0){
			BIT::add(op[i].r,1);
		}
		else{
			val[op[i].id]+=op[i].op*BIT::query(op[i].r);
		}
	}
	for(int i=1;i<=q;i++){
		printf("%d\n",ans[i]-(val[i]>0));
	}
	return 0;
}