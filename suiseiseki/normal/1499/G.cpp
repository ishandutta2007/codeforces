#include <cstdio>
#include <cassert>
#include <algorithm>
const int Maxn=400000;
const int Mod=998244353;
namespace DSU{
	int sum[Maxn+5][2];
	int fa[Maxn+5],val[Maxn+5];
	void init(){
		sum[0][1]=1;
		for(int i=1;i<=Maxn;i++){
			fa[i]=i;
			sum[i][1]=(sum[i-1][1]<<1)%Mod;
		}
	}
	int find(int x){
		if(x==fa[x]){
			return x;
		}
		int y=fa[x],t=find(fa[x]);
		val[x]^=val[y];
		return fa[x]=t;
	}
	void merge(int x,int y,int a){
		int fa_x=find(x),fa_y=find(y);
		assert(fa_x!=fa_y);
		fa[fa_y]=fa_x;
		val[fa_y]=val[x]^val[y]^a;
		sum[fa_x][0]=(sum[fa_x][0]+sum[fa_y][val[fa_y]])%Mod;
		sum[fa_x][1]=(sum[fa_x][1]+sum[fa_y][val[fa_y]^1])%Mod;
	}
	int find_val(int x){
		return sum[find(x)][0];
	}
	int find_node(int x){
		find(x);
		return val[x];
	}
}
int deg[Maxn+5];
int to_node[Maxn+5],to_edge[Maxn+5];
int id_tot;
int ans;
void link(int u,int v){
	id_tot++;
	if(deg[u]<deg[v]){
		std::swap(u,v);
	}
	if(deg[u]==0){
		deg[u]^=1,deg[v]^=1;
		to_node[u]=v,to_node[v]=u;
		to_edge[u]=to_edge[v]=id_tot;
		ans=(ans+DSU::find_val(id_tot))%Mod;
		return;
	}
	if(deg[v]==0){
		deg[u]^=1,deg[v]^=1;
		int t=to_node[u],w=to_edge[u];
		to_node[t]=v,to_node[v]=t;
		to_edge[v]=id_tot;
		ans=(ans-DSU::find_val(w)+Mod)%Mod;
		DSU::merge(w,id_tot,1);
		ans=(ans+DSU::find_val(w))%Mod;
		return;
	}
	deg[u]^=1,deg[v]^=1;
	if(to_node[u]==v){
		int w=to_edge[u];
		ans=(ans-DSU::find_val(w)+Mod)%Mod;
		DSU::merge(w,id_tot,1);
		ans=(ans+DSU::find_val(w))%Mod;
		return;
	}
	int t_u=to_node[u],t_v=to_node[v];
	to_node[t_u]=t_v,to_node[t_v]=t_u;
	int w_1=to_edge[u],w_2=to_edge[v];
	ans=(ans-DSU::find_val(w_1)+Mod)%Mod;
	ans=(ans-DSU::find_val(w_2)+Mod)%Mod;
	DSU::merge(w_1,id_tot,1);
	DSU::merge(w_1,w_2,0);
	ans=(ans+DSU::find_val(w_1))%Mod;
}
int lis[Maxn+5],lis_len;
int main(){
	DSU::init();
	int n_1,n_2,m;
	scanf("%d%d%d",&n_1,&n_2,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		link(u,v+n_1);
	}
	int q;
	scanf("%d",&q);
	for(int t=1;t<=q;t++){
		int op;
		scanf("%d",&op);
		if(op==1){
			int u,v;
			scanf("%d%d",&u,&v);
			link(u,v+n_1);
			printf("%d\n",ans);
		}
		else{
			lis_len=0;
			for(int i=1;i<=id_tot;i++){
				if(DSU::find_node(i)==1){
					lis[++lis_len]=i;
				}
			}
			printf("%d ",lis_len);
			for(int i=1;i<=lis_len;i++){
				printf("%d ",lis[i]);
			}
			puts("");
		}
		fflush(stdout);
	}
	return 0;
}