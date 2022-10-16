#include <ctime>
#include <random>
#include <cstdio>
using namespace std;
void swap(int &a,int &b){
	int t=a;
	a=b;
	b=t;
}
typedef unsigned long long ull;
const int Maxn=300000;
mt19937 rnd(time(NULL));
int n,q;
int a[Maxn+5];
ull mask[Maxn+5];
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int Root[Maxn+5];
struct Segment_Node{
	int lson,rson;
	ull val;
}seg[Maxn*20+5];
int id_tot;
void insert(int last,int &root,int x,ull a,int left=1,int right=n){
	root=++id_tot;
	seg[root]=seg[last];
	seg[root].val^=a;
	if(left==right){
		return;
	}
	int mid=(left+right)>>1;
	if(x<=mid){
		insert(seg[last].lson,seg[root].lson,x,a,left,mid);
	}
	else{
		insert(seg[last].rson,seg[root].rson,x,a,mid+1,right);
	}
}
int query(int root_1,int root_2,int l,int r,int x,ull a,int left=1,int right=n){
	if(l>right||r<left||(seg[root_1].val^seg[root_2].val^((left<=x&&x<=right)?a:0))==0){
		return -1;
	}
	if(left==right){
		return left;
	}
	int mid=(left+right)>>1;
	int t=query(seg[root_1].lson,seg[root_2].lson,l,r,x,a,left,mid);
	if(t!=-1){
		return t;
	}
	return query(seg[root_1].rson,seg[root_2].rson,l,r,x,a,mid+1,right);
}
int fa[20][Maxn+5];
int dep[Maxn+5];
void init_dfs(int u){
	for(int i=1;fa[i-1][fa[i-1][u]];i++){
		fa[i][u]=fa[i-1][fa[i-1][u]];
	}
	dep[u]=dep[fa[0][u]]+1;
	insert(Root[fa[0][u]],Root[u],a[u],mask[a[u]]);
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa[0][u]){
			continue;
		}
		fa[0][v]=u;
		init_dfs(v);
	}
}
int find_lca(int u,int v){
	if(dep[u]<dep[v]){
		swap(u,v);
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
			u=fa[i][u];
			v=fa[i][v];
		}
	}
	return fa[0][u];
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		mask[i]=rnd();
		scanf("%d",&a[i]);
	}
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	init_dfs(1);
	for(int i=1;i<=q;i++){
		int u,v,l,r;
		scanf("%d%d%d%d",&u,&v,&l,&r);
		int lca=find_lca(u,v);
		printf("%d\n",query(Root[u],Root[v],l,r,a[lca],mask[a[lca]]));
	}
	return 0;
}