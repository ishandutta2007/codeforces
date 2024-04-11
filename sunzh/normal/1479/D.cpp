#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<random>
#include<chrono>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 Rnd(SEED);
int rt[300010];
int n,q;
vector<int>vec[300010];
int col[300010];
uint64_t rnd[300010];
int fa[300010],topf[300010];
int siz[300010],son[300010];
int dep[300010],dfn[300010];
int idx;
void dfs1(int x,int f);
void dfs2(int x,int top);
struct node{
	int ls,rs;
	uint64_t val;
}tre[6000010];
int cnt=0;
void pushup(int p){
	tre[p].val=tre[tre[p].ls].val^tre[tre[p].rs].val;
}
void modify(int &p,int x,int l,int r,int pos){
	p=++cnt;
	if(l==r){
		tre[p].val=tre[x].val^rnd[pos];
		return ;
	} 
	int mid=l+r>>1;
	if(pos<=mid) modify(tre[p].ls,tre[x].ls,l,mid,pos),tre[p].rs=tre[x].rs;
	else modify(tre[p].rs,tre[x].rs,mid+1,r,pos),tre[p].ls=tre[x].ls;
	pushup(p);
}
int query(int x,int y,int a,int b,int l,int r,int L,int R){ 
	if((tre[x].val^tre[y].val^tre[a].val^tre[b].val)==0) return -1;
	if(l==r) return l;
	int mid=l+r>>1;
	int lans=-1;
	if(L<=mid) lans=query(tre[x].ls,tre[y].ls,tre[a].ls,tre[b].ls,l,mid,L,R);
	if(lans==-1&&R>mid) return query(tre[x].rs,tre[y].rs,tre[a].rs,tre[b].rs,mid+1,r,L,R);
	else return lans;
}
int LCA(int u,int v){
	while(topf[u]!=topf[v]){
		if(dep[topf[u]]<dep[topf[v]]) swap(u,v);
		u=fa[topf[u]];
	}
	if(dep[u]>dep[v]) return v;else return u;
}
int getans(int u,int v,int l,int r){
	int lca=LCA(u,v);
	return query(rt[u],rt[v],rt[lca],rt[fa[lca]],1,n,l,r);
}
int main(){
	n=read(),q=read();
	for(int i=1;i<=n;++i) rnd[i]=Rnd();
	for(int i=1;i<=n;++i) col[i]=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();vec[u].pb(v),vec[v].pb(u);
	}
	dfs1(1,0);
	dfs2(1,1);
	while(q--){
		int u=read(),v=read(),l=read(),r=read();
		printf("%d\n",getans(u,v,l,r));
	}
}
void dfs1(int x,int f){
	modify(rt[x],rt[f],1,n,col[x]);
	siz[x]=1;
	fa[x]=f;dep[x]=dep[f]+1;
	for(int v:vec[x]){
		if(v==f) continue ;
		dfs1(v,x);
		if(siz[v]>siz[son[x]]) son[x]=v;
		siz[x]+=siz[v];
	}
}
void dfs2(int x,int top){
	topf[x]=top;dfn[x]=++idx;
	if(!son[x]) return ;else dfs2(son[x],top);
	for(int v:vec[x]){
		if(v==fa[x]||v==son[x]) continue ;
		dfs2(v,v);
	}
}