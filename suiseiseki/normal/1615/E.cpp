#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=200000;
const ll Inf=0x3f3f3f3f3f3f3f3fll;
int n,k;
bool vis[Maxn+5];
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int fa[Maxn+5],dfn[Maxn+5],sz[Maxn+5],rnk[Maxn+5],dfn_tot;
void init_dfs(int u){
	dfn[u]=++dfn_tot;
	rnk[dfn[u]]=u;
	sz[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa[u]){
			continue;
		}
		fa[v]=u;
		init_dfs(v);
		sz[u]+=sz[v];
	}
}
struct Segment_Node{
	int lazy;
	std::pair<int,int> max_val;
}seg[Maxn<<2|5];
void update_tag(int root,int a){
	seg[root].max_val.first+=a;
	seg[root].lazy+=a;
}
void push_up(int root){
	seg[root].max_val=std::max(seg[root<<1].max_val,seg[root<<1|1].max_val);
}
void push_down(int root){
	if(seg[root].lazy){
		update_tag(root<<1,seg[root].lazy);
		update_tag(root<<1|1,seg[root].lazy);
		seg[root].lazy=0;
	}
}
void build(int root=1,int left=1,int right=n){
	if(left==right){
		seg[root].max_val=std::make_pair(0,left);
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
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v),add_edge(v,u);
	}
	init_dfs(1);
	build();
	for(int i=1;i<=n;i++){
		update(dfn[i],dfn[i]+sz[i]-1,1);
	}
	ll ans=-1ll*(n/2)*(n-n/2);
	int num=0;
	int lst_val=n;
	for(num=1;num<=k;num++){
		std::pair<int,int> cur_u=seg[1].max_val;
		int u=rnk[cur_u.second];
		while(u>0&&!vis[u]){
			vis[u]=1;
			update(dfn[u],dfn[u]+sz[u]-1,-1);
			u=fa[u];
			lst_val--;
		}
		int cur_val=std::min(n/2,lst_val);
		ans=std::max(ans,1ll*(n-num-cur_val)*(num-cur_val));
	}
	printf("%lld\n",ans);
	return 0;
}