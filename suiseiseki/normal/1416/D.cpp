#include <cstdio>
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
const int Maxn=400000;
const int Maxm=300000;
const int Maxq=500000;
int n,m,q;
struct Edge{
	int u,v;
}edge[Maxm+5];
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int fa[Maxn+5];
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
int id_tot;
void merge(int x,int y){
	int fa_x=find(x),fa_y=find(y);
	if(fa_x==fa_y){
		return;
	}
	id_tot++;
	fa[id_tot]=id_tot;
	fa[fa_y]=id_tot;
	fa[fa_x]=id_tot;
	add_edge(id_tot,fa_x);
	add_edge(id_tot,fa_y);
}
int p[Maxn+5];
struct Question{
	int op,x,root;
}qu[Maxq+5];
bool del[Maxq+5];
int val[Maxn+5];
int dfn[Maxn+5],sz[Maxn+5],dfn_tot,rnk[Maxn+5];
struct Segment_Node{
	int maxn,id;
	Segment_Node(int _maxn=0,int _id=0){
		maxn=_maxn;
		id=_id;
	}
}seg[Maxn<<2|5];
void push_up(int root){
	if(seg[root<<1].maxn>=seg[root<<1|1].maxn){
		seg[root].maxn=seg[root<<1].maxn;
		seg[root].id=seg[root<<1].id;
	}
	else{
		seg[root].maxn=seg[root<<1|1].maxn;
		seg[root].id=seg[root<<1|1].id;
	}
}
Segment_Node push_up(Segment_Node ls,Segment_Node rs){
	if(ls.maxn>=rs.maxn){
		return ls;
	}
	return rs;
}
void build(int root=1,int left=1,int right=dfn_tot){
	if(left==right){
		seg[root].maxn=val[left];
		seg[root].id=left;
		return;
	}
	int mid=(left+right)>>1;
	build(root<<1,left,mid);
	build(root<<1|1,mid+1,right);
	push_up(root);
}
void update(int x,int root=1,int left=1,int right=dfn_tot){
	if(left==right){
		seg[root].maxn=0;
		return;
	}
	int mid=(left+right)>>1;
	if(x<=mid){
		update(x,root<<1,left,mid);
	}
	else{
		update(x,root<<1|1,mid+1,right);
	}
	push_up(root);
}
Segment_Node query(int l,int r,int root=1,int left=1,int right=dfn_tot){
	if(l>right||r<left){
		return Segment_Node(0,0);
	}
	if(l<=left&&r>=right){
		return seg[root];
	}
	int mid=(left+right)>>1;
	return push_up(query(l,r,root<<1,left,mid),query(l,r,root<<1|1,mid+1,right));
}
void init_dfs(int u,int fa){
	dfn[u]=++dfn_tot;
	rnk[dfn_tot]=u;
	val[dfn_tot]=p[u];
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
int main(){
	read(n),read(m),read(q);
	for(int i=1;i<=n;i++){
		read(p[i]);
		fa[i]=i;
	}
	id_tot=n;
	for(int i=1;i<=m;i++){
		read(edge[i].u),read(edge[i].v);
	}
	for(int i=1;i<=q;i++){
		read(qu[i].op),read(qu[i].x);
		if(qu[i].op==2){
			del[qu[i].x]=1;
		}
	}
	for(int i=1;i<=m;i++){
		if(!del[i]){
			merge(edge[i].u,edge[i].v);
		}
	}
	for(int i=q;i>0;i--){
		if(qu[i].op==2){
			merge(edge[qu[i].x].u,edge[qu[i].x].v);
		}
		else{
			qu[i].root=find(qu[i].x);
		}
	}
	for(int i=id_tot;i>0;i--){
		if(!dfn[i]){
			init_dfs(i,0);
		}
	}
	build();
	for(int i=1;i<=q;i++){
		if(qu[i].op==1){
			Segment_Node ans=query(dfn[qu[i].root],dfn[qu[i].root]+sz[qu[i].root]-1);
			if(ans.maxn==0){
				printf("%d\n",ans.maxn);
			}
			else{
				printf("%d\n",ans.maxn);
				update(ans.id);
			}
		}
	}
	return 0;
}