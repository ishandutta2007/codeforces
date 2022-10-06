#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 1020000;
const ll inf = 1e18;
int n,q,fa[N],w[N],deg[N];
struct node{
	int l,r,idx;
};
vector<node>b[N];Vi e[N];
ll d[N],ans[N];
struct Tre{
	int l,r;ll mn,lzy;
}tree[N<<2];
void upd(int k){
	tree[k].mn=min(tree[k<<1].mn,tree[k<<1|1].mn);
}
void pushdown(int k){
	if(tree[k].lzy){
		tree[k<<1].lzy+=tree[k].lzy;
		tree[k<<1].mn+=tree[k].lzy;
		tree[k<<1|1].lzy+=tree[k].lzy;
		tree[k<<1|1].mn+=tree[k].lzy;
		tree[k].lzy=0;
	}
}
void build(int k, int l, int r){//d[1..n]
	tree[k].l=l;tree[k].r=r;
	if(l==r){tree[k].mn=d[l];return;}
	int md=(l+r)>>1;build(k<<1,l,md);build(k<<1|1,md+1,r);
	upd(k);
}

void modify(int k, int l, int r, ll v){//add
	if(r<tree[k].l||l>tree[k].r)return;
	if(l<=tree[k].l&&r>=tree[k].r){
		tree[k].mn+=v;tree[k].lzy+=v;return;
	}
	pushdown(k);
	modify(k<<1,l,r,v);modify(k<<1|1,l,r,v);
	upd(k);
}
ll query(int k, int l, int r){//querymin
	if(r<tree[k].l||l>tree[k].r)return inf;
	if(l<=tree[k].l&&r>=tree[k].r)return tree[k].mn;
	pushdown(k);
	return min(query(k<<1,l,r),query(k<<1|1,l,r));
}
int ed[N];//[u,ed[u]]
void dfs1(int u){
	ed[u]=u;
	rep(i,0,SZ(e[u])-1)dfs1(e[u][i]),umax(ed[u],ed[e[u][i]]);
}
void dfs(int u){
	rep(i,0,SZ(b[u])-1)ans[b[u][i].idx]=query(1,b[u][i].l,b[u][i].r);
	rep(i,0,SZ(e[u])-1){
		int v=e[u][i];
		modify(1,v,ed[v],-w[v]);
		if(1<=v-1)modify(1,1,v-1,w[v]);
		if(ed[v]+1<=n)modify(1,ed[v]+1,n,w[v]);
		dfs(e[u][i]);
		modify(1,v,ed[v],w[v]);
		if(1<=v-1)modify(1,1,v-1,-w[v]);
		if(ed[v]+1<=n)modify(1,ed[v]+1,n,-w[v]);
	}
}
int main() {
	read(n);read(q);
	rep(i,2,n){
		read(fa[i]),read(w[i]),deg[i]++,deg[fa[i]]++;
		d[i]=d[fa[i]]+w[i];
		e[fa[i]].pb(i);
	}
	rep(i,1,q){
		node t;int u;read(u);read(t.l);read(t.r);t.idx=i;
		b[u].pb(t);
	}
	rep(i,1,n)if(deg[i]>1)d[i]=inf;
	build(1,1,n);
	dfs1(1);dfs(1);
	rep(i,1,q)printf("%lld\n",ans[i]);
	return 0;
}