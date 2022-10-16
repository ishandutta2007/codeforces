#include <cstdio>
template<typename Elem>
Elem min(Elem a,Elem b){
	return a<b?a:b;
}
template<typename Elem>
Elem max(Elem a,Elem b){
	return a>b?a:b;
}
template<typename Elem>
void swap(Elem &a,Elem &b){
	Elem t=a;
	a=b;
	b=t;
}
template<typename Elem>
void read(Elem &a){
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
typedef long long ll;
const int Maxn=100000;
struct Edge{
	int u,v;
	ll w;
}edge[Maxn+5];
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
ll val[Maxn<<1|5];
void add_edge(int from,int to,ll w){
	arrive[++tot]=to;
	val[tot]=w;
	nxt[tot]=head[from];
	head[from]=tot;
}
int dfn[Maxn+5],right[Maxn+5],dfn_tot;
int lis[Maxn<<1|5];
ll dis[Maxn+5];
void init_dfs(int u,int fa){
	dfn[u]=++dfn_tot;
	lis[dfn_tot]=u;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		dis[v]=dis[u]+val[i];
		init_dfs(v,u);
		lis[++dfn_tot]=u;
	}
	right[u]=dfn_tot;
}
struct Segment_Node{
	ll lazy;
	ll maxn,minn;
	ll l_m,m_r,l_m_r;
	void update_tag(ll x){
		lazy+=x;
		maxn+=x;
		minn-=(x<<1);
		l_m-=x;
		m_r-=x;
	}
}seg[Maxn<<3|5];
void push_down(int root){
	if(seg[root].lazy==0){
		return;
	}
	seg[root<<1].update_tag(seg[root].lazy);
	seg[root<<1|1].update_tag(seg[root].lazy);
	seg[root].lazy=0;
}
void push_up(int root){
	seg[root].maxn=max(seg[root<<1].maxn,seg[root<<1|1].maxn);
	seg[root].minn=max(seg[root<<1].minn,seg[root<<1|1].minn);
	seg[root].l_m=max(seg[root<<1].l_m,seg[root<<1|1].l_m);
	seg[root].l_m=max(seg[root].l_m,seg[root<<1].maxn+seg[root<<1|1].minn);
	seg[root].m_r=max(seg[root<<1].m_r,seg[root<<1|1].m_r);
	seg[root].m_r=max(seg[root].m_r,seg[root<<1|1].maxn+seg[root<<1].minn);
	seg[root].l_m_r=max(seg[root<<1].l_m_r,seg[root<<1|1].l_m_r);
	seg[root].l_m_r=max(seg[root].l_m_r,seg[root<<1].l_m+seg[root<<1|1].maxn);
	seg[root].l_m_r=max(seg[root].l_m_r,seg[root<<1].maxn+seg[root<<1|1].m_r);
}
void build(int root=1,int left=1,int right=dfn_tot){
	seg[root].lazy=0;
	if(left==right){
		seg[root].maxn=dis[lis[left]];
		seg[root].minn=-(dis[lis[left]]<<1);
		seg[root].l_m=seg[root].m_r=-dis[lis[left]];
		seg[root].l_m_r=0;
		return;
	}
	int mid=(left+right)>>1;
	build(root<<1,left,mid);
	build(root<<1|1,mid+1,right);
	push_up(root);
}
void update(int l,int r,ll v,int root=1,int left=1,int right=dfn_tot){
	if(l>right||r<left){
		return;
	}
	if(l<=left&&r>=right){
		seg[root].update_tag(v);
		return;
	}
	push_down(root);
	int mid=(left+right)>>1;
	update(l,r,v,root<<1,left,mid);
	update(l,r,v,root<<1|1,mid+1,right);
	push_up(root);
}
int main(){
	int n,q;
	ll w;
	read(n),read(q),read(w);
	for(int i=1;i<n;i++){
		read(edge[i].u),read(edge[i].v),read(edge[i].w);
		add_edge(edge[i].u,edge[i].v,edge[i].w);
		add_edge(edge[i].v,edge[i].u,edge[i].w);
	}
	init_dfs(1,0);
	for(int i=1;i<n;i++){
		if(dfn[edge[i].u]>dfn[edge[i].v]){
			swap(edge[i].u,edge[i].v);
		}
	}
	build();
	ll ans=0;
	for(int i=1;i<=q;i++){
		int id;
		ll c;
		read(id),read(c);
		id=(id+ans)%(n-1)+1;
		c=(c+ans)%w;
		update(dfn[edge[id].v],right[edge[id].v],c-edge[id].w);
		edge[id].w=c;
		ans=seg[1].l_m_r;
		printf("%lld\n",ans);
	}
	return 0;
}
/*
I dont know what happened...
*/