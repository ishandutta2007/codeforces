#include <set>
#include <cstdio>
#include <algorithm>
const int Maxn=200000;
int n,q;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
std::set<std::pair<int,int> > st;
int fa[Maxn+5][20],dep[Maxn+5];
int dfn[Maxn+5],sz[Maxn+5],dfn_tot;
struct Segment_Node{
	int max_val,max_num;
	int lazy;
}seg[Maxn<<2|5];
void update_tag(int root,int a){
	seg[root].max_val+=a;
	seg[root].lazy+=a;
}
void push_down(int root){
	if(seg[root].lazy){
		update_tag(root<<1,seg[root].lazy);
		update_tag(root<<1|1,seg[root].lazy);
		seg[root].lazy=0;
	}
}
void push_up(int root){
	seg[root].max_val=std::max(seg[root<<1].max_val,seg[root<<1|1].max_val);
	seg[root].max_num=0;
	if(seg[root<<1].max_val==seg[root].max_val){
		seg[root].max_num+=seg[root<<1].max_num;
	}
	if(seg[root<<1|1].max_val==seg[root].max_val){
		seg[root].max_num+=seg[root<<1|1].max_num;
	}
}
void build(int root=1,int left=1,int right=n){
	seg[root].lazy=seg[root].max_val=0;
	if(left==right){
		seg[root].max_num=1;
		return;
	}
	int mid=(left+right)>>1;
	build(root<<1,left,mid);
	build(root<<1|1,mid+1,right);
	push_up(root);
}
void update(int l,int r,int a,int root=1,int left=1,int right=n){
	if(l>right||r<left){
		return;
	}
	if(l<=left&&r>=right){
		update_tag(root,a);
		return;
	}
	push_down(root);
	int mid=(left+right)>>1;
	update(l,r,a,root<<1,left,mid);
	update(l,r,a,root<<1|1,mid+1,right);
	push_up(root);
}
void init_dfs(int u){
	dep[u]=dep[fa[u][0]]+1;
	for(int i=1;fa[fa[u][i-1]][i-1];i++){
		fa[u][i]=fa[fa[u][i-1]][i-1];
	}
	dfn[u]=++dfn_tot;
	sz[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa[u][0]){
			continue;
		}
		fa[v][0]=u;
		init_dfs(v);
		sz[u]+=sz[v];
	}
}
int find_son(int u,int v){
	for(int i=19;i>=0;i--){
		if(dep[fa[u][i]]>dep[v]){
			u=fa[u][i];
		}
	}
	return u;
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v),add_edge(v,u);
	}
	init_dfs(1);
	build();
	for(int i=1;i<=q;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		if(u>v){
			std::swap(u,v);
		}
		if(st.count(std::make_pair(u,v))>0){
			st.erase(std::make_pair(u,v));
			if(dfn[u]<=dfn[v]&&dfn[u]+sz[u]-1>=dfn[v]){
				int son_u=find_son(v,u);
				update(1,dfn[son_u]-1,-1);
				update(dfn[son_u]+sz[son_u],n,-1);
			}
			else{
				update(dfn[u],dfn[u]+sz[u]-1,-1);
			}
			if(dfn[v]<=dfn[u]&&dfn[v]+sz[v]-1>=dfn[u]){
				int son_v=find_son(u,v);
				update(1,dfn[son_v]-1,-1);
				update(dfn[son_v]+sz[son_v],n,-1);
			}
			else{
				update(dfn[v],dfn[v]+sz[v]-1,-1);
			}
		}
		else{
			st.insert(std::make_pair(u,v));
			if(dfn[u]<=dfn[v]&&dfn[u]+sz[u]-1>=dfn[v]){
				int son_u=find_son(v,u);
				update(1,dfn[son_u]-1,1);
				update(dfn[son_u]+sz[son_u],n,1);
			}
			else{
				update(dfn[u],dfn[u]+sz[u]-1,1);
			}
			if(dfn[v]<=dfn[u]&&dfn[v]+sz[v]-1>=dfn[u]){
				int son_v=find_son(u,v);
				update(1,dfn[son_v]-1,1);
				update(dfn[son_v]+sz[son_v],n,1);
			}
			else{
				update(dfn[v],dfn[v]+sz[v]-1,1);
			}
		}
		if(seg[1].max_val!=(int)st.size()){
			puts("0");
		}
		else{
			printf("%d\n",seg[1].max_num);
		}
	}
	return 0;
}