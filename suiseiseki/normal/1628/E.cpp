#include <cstdio>
#include <vector>
#include <algorithm>
const int Maxn=600000;
const int Inf=0x3f3f3f3f;
#define get_high_bit(x) (x==0?-1:31-__builtin_clz(x))
int n,m,q;
int dfn_tot,id_tot;
int dfn[Maxn+5],rnk[Maxn+5];
int val[Maxn+5],dep[Maxn+5],fa[Maxn+5][20];
int head[Maxn+5],nxt[Maxn+5];
void add_edge(int from,int to){
	nxt[to]=head[from];
	head[from]=to;
}
struct Edge{
	int u,v,w;
}edge[Maxn+5];
struct Segment_Tree{
	struct Segment_Node{
		int a[2],val[2];
		int lazy;
	}seg[Maxn<<2|5];
	void push_up(int root){
		seg[root].a[0]=std::max(seg[root<<1].a[0],seg[root<<1|1].a[0]);
		seg[root].a[1]=std::min(seg[root<<1].a[1],seg[root<<1|1].a[1]);
	}
	void build(int root=1,int left=1,int right=n){
		if(left==right){
			seg[root].a[0]=0,seg[root].a[1]=Inf;
			seg[root].val[0]=seg[root].val[1]=dfn[left];
			return;
		}
		int mid=(left+right)>>1;
		build(root<<1,left,mid);
		build(root<<1|1,mid+1,right);
		seg[root].val[0]=std::max(seg[root<<1].val[0],seg[root<<1|1].val[0]);
		seg[root].val[1]=std::min(seg[root<<1].val[1],seg[root<<1|1].val[1]);
		push_up(root);
	}
	void push_down(int root){
		if(seg[root].lazy==-1){
			return;
		}
		if(seg[root].lazy==0){
			seg[root<<1].a[0]=seg[root<<1|1].a[0]=0;
			seg[root<<1].a[1]=seg[root<<1|1].a[1]=Inf;
		}
		else{
			seg[root<<1].a[0]=seg[root<<1].val[0],seg[root<<1].a[1]=seg[root<<1].val[1];
			seg[root<<1|1].a[0]=seg[root<<1|1].val[0],seg[root<<1|1].a[1]=seg[root<<1|1].val[1];
		}
		seg[root<<1].lazy=seg[root<<1|1].lazy=seg[root].lazy;
		seg[root].lazy=-1;
	}
	void update(int l,int r,int v,int root=1,int left=1,int right=n){
		if(l>right||r<left){
			return;
		}
		if(l<=left&&r>=right){
			if(v==0){
				seg[root].a[0]=0,seg[root].a[1]=Inf;
			}
			else{
				seg[root].a[0]=std::max(seg[root].a[0],seg[root].val[0]);
				seg[root].a[1]=std::min(seg[root].a[1],seg[root].val[1]);
			}
			seg[root].lazy=v;
			return;
		}
		push_down(root);
		int mid=(left+right)>>1;
		update(l,r,v,root<<1,left,mid);
		update(l,r,v,root<<1|1,mid+1,right);
		push_up(root);
	}
}tree;
namespace DSU{
	int fa[Maxn+5];
	void init(){
		for(int i=1;i<=n*2;i++){
			fa[i]=i;
		}
	}
	int find(int x){
		if(x==fa[x]){
			return x;
		}
		return fa[x]=find(fa[x]);
	}
	void merge(int x,int y){
		int fa_x=find(x),fa_y=find(y);
		if(fa_x==fa_y){
			return;
		}
		fa[fa_y]=fa_x;
	}
}
void Kruskal(){
	DSU::init();
	id_tot=n;
	for(int i=1;i<n;i++){
		int u=edge[i].u,v=edge[i].v,w=edge[i].w;
		++id_tot;
		int cur_u=DSU::find(u),cur_v=DSU::find(v);
		DSU::merge(id_tot,u);
		DSU::merge(id_tot,v);
		val[id_tot]=w;
		add_edge(id_tot,cur_u),add_edge(id_tot,cur_v);
	}
}
void init_dfs(int u){
	dep[u]=dep[fa[u][0]]+1;
	dfn[u]=++dfn_tot;
	rnk[dfn[u]]=u;
	for(int i=1;i<20;i++){
		fa[u][i]=fa[fa[u][i-1]][i-1];
	}
	for(int v=head[u];v;v=nxt[v]){
		fa[v][0]=u;
		init_dfs(v);
	}
}
int find_lca(int u,int v){
	if(dep[u]<dep[v]){
		std::swap(u,v);
	}
	for(int i=get_high_bit(dep[u]-dep[v]);i>=0;i=get_high_bit(dep[u]-dep[v])){
		if(dep[fa[u][i]]>=dep[v]){
			u=fa[u][i];
		}
	}
	if(u==v){
		return u;
	}
	for(int i=get_high_bit(dep[u]);i>=0;i--){
		if(fa[u][i]!=fa[v][i]){
			u=fa[u][i],v=fa[v][i];
		}
	}
	return fa[u][0];
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		val[i]=-1;
	}
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
	}
	std::sort(edge+1,edge+n,[&](Edge p,Edge q){return p.w<q.w;});
	Kruskal();
	init_dfs(id_tot);
	tree.build();
	for(int t=1;t<=q;t++){
		int op;
		scanf("%d",&op);
		if(op==1){
			int l,r;
			scanf("%d%d",&l,&r);
			tree.update(l,r,1);
		}
		else if(op==2){
			int l,r;
			scanf("%d%d",&l,&r);
			tree.update(l,r,0);
		}
		else{
			int ans=-1,x;
			scanf("%d",&x);
			int v_1=tree.seg[1].a[0],v_2=tree.seg[1].a[1];
			if(v_1){
				ans=std::max(ans,val[find_lca(rnk[v_1],x)]);
			}
			if(v_2!=Inf){
				ans=std::max(ans,val[find_lca(rnk[v_2],x)]);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}