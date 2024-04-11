#include <cstdio>
void swap(int &a,int &b){
	int t=a;
	a=b;
	b=t;
}
int max(int a,int b){
	return a>b?a:b;
}
const int Maxn=500000;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],val[Maxn<<1|5],id[Maxn<<1|5],tot;
void add_edge(int from,int to,int w,int _id){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	val[tot]=w;
	id[tot]=_id;
	head[from]=tot;
}
int n,m;
struct Tree{
	int root;
	int dfn[Maxn+5],sz[Maxn+5],rnk[Maxn+5],dfn_tot;
	int fa_val[Maxn+5];
	int id_node[Maxn+5];
	int dep[Maxn+5];
	void init_dfs(int u,int fa){
		dep[u]=dep[fa]+1;
		sz[u]=1;
		dfn[u]=++dfn_tot;
		rnk[dfn_tot]=u;
		for(int i=head[u];i;i=nxt[i]){
			int v=arrive[i];
			if(v==fa){
				continue;
			}
			id_node[id[i]]=v;
			fa_val[v]=val[i];
			init_dfs(v,u);
			sz[u]+=sz[v];
		}
	}
	struct Segment_Node{
		int max_0,max_1;
		bool lazy;
	}seg[Maxn<<2|5];
	void build(int root=1,int left=1,int right=n){
		seg[root].lazy=0;
		if(left==right){
			seg[root].max_0=dep[rnk[left]];
			seg[root].max_1=0;
			return;
		}
		int mid=(left+right)>>1;
		build(root<<1,left,mid);
		build(root<<1|1,mid+1,right);
		seg[root].max_0=max(seg[root<<1].max_0,seg[root<<1|1].max_0);
		seg[root].max_1=max(seg[root<<1].max_1,seg[root<<1|1].max_1);
	}
	void update_tag(int root){
		seg[root].lazy^=1;
		swap(seg[root].max_0,seg[root].max_1);
	}
	void push_down(int root){
		if(seg[root].lazy){
			update_tag(root<<1);
			update_tag(root<<1|1);
			seg[root].lazy=0;
		}
	}
	void update(int l,int r,int root=1,int left=1,int right=n){
		if(l>right||r<left){
			return;
		}
		if(l<=left&&r>=right){
			update_tag(root);
			return;
		}
		push_down(root);
		int mid=(left+right)>>1;
		update(l,r,root<<1,left,mid);
		update(l,r,root<<1|1,mid+1,right);
		seg[root].max_0=max(seg[root<<1].max_0,seg[root<<1|1].max_0);
		seg[root].max_1=max(seg[root<<1].max_1,seg[root<<1|1].max_1);
	}
	void _update(int u){
		update(dfn[u],dfn[u]+sz[u]-1);
	}
	void update(int u){
		u=id_node[u];
		update(dfn[u],dfn[u]+sz[u]-1);
	}
	int query(){
		return seg[1].max_0;
	}
	void init(int u){
		root=u;
		dfn_tot=0;
		init_dfs(root,0);
		build();
		for(int i=1;i<=n;i++){
			if(fa_val[i]){
				_update(i);
			}
		}
	}
}tree_1,tree_2;
int root_1,root_2;
int dep[Maxn+5];
void init_dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		init_dfs(v,u);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add_edge(u,v,w,i);
		add_edge(v,u,w,i);
	}
	init_dfs(1,0);
	for(int i=1;i<=n;i++){
		if(dep[i]>dep[root_1]){
			root_1=i;
		}
	}
	init_dfs(root_1,0);
	for(int i=1;i<=n;i++){
		if(dep[i]>dep[root_2]){
			root_2=i;
		}
	}
	tree_1.init(root_1);
	tree_2.init(root_2);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int id;
		scanf("%d",&id);
		tree_1.update(id);
		tree_2.update(id);
		printf("%d\n",max(tree_1.query(),tree_2.query())-1);
	}
	return 0;
}