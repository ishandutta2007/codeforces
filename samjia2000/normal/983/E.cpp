#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 2e5+5;

int n,m,q;
int lef[N],rig[N];
int Fa[N];
struct Route{
	int x,y;
}r[N];
int dep[N];
int fa1[N][20],fa[N][20];
int val[N];
int dis[N];
struct query{
	int x,y;
}qry[N];
int mx[N],siz[N],dfn[N],k,R[N];
int be[N],u,tp[N];

void dfs1(int x){
	val[x]=x;
	siz[x]=1;
	fo(i,1,log(n)/log(2))fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int y=lef[x];y;y=rig[y]){
		fa[y][0]=x;
		dep[y]=dep[x]+1;
		dfs1(y);
		siz[x]+=siz[y];
		if (!mx[x]||siz[y]>siz[mx[x]])mx[x]=y;
	}
}

void dfs2(int x){
	dfn[x]=++k;
	if (!mx[x]){
		R[x]=k;
		tp[be[x]=++u]=x;
		return;
	}
	dfs2(mx[x]);
	tp[be[x]=be[mx[x]]]=x;
	for(int y=lef[x];y;y=rig[y])
	if(y!=mx[x])dfs2(y);
	R[x]=k;
}

int pmin(int x,int y){return dep[x]<dep[y]?x:y;}

int lca(int x,int y){
	if (dep[x]<dep[y])swap(x,y);
	fd(i,log(n)/log(2),0)
	if (dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if (x==y)return x;
	fd(i,log(n)/log(2),0)
	if (fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}

typedef pair<int,int> pir;
typedef unsigned int ui;

ui seed;
ui getrand(){seed^=seed<<13;seed^=seed>>17;seed^=seed<<5;return seed;}

int ans[N];
struct node{
	int l,r,rt;
}tree[N*2];
int tot,rt;
struct Node{
	int l,r,tot;
	ui key;
	int val;
}treap[N*20];
int Nt;

void build(int &now,int l,int r){
	now=++tot;
	if (l==r)return;
	int mid=(l+r)/2;
	build(tree[now].l,l,mid);
	build(tree[now].r,mid+1,r);
}

void update(int x){treap[x].tot=treap[treap[x].l].tot+treap[treap[x].r].tot+1;}

const int INF = 1e9;

int getv(int x,int v){
	if (!x)return INF;
	if (treap[x].val<v)return getv(treap[x].r,v);
	return min(getv(treap[x].l,v),treap[x].val);
}

pir split(int x,int v){
	if (!x)return make_pair(0,0);
	if (treap[x].val<v){
		pir u=split(treap[x].r,v);
		treap[x].r=u.first;
		update(x);
		return make_pair(x,u.second);
	}
	pir u=split(treap[x].l,v);
	treap[x].l=u.second;
	update(x);
	return make_pair(u.first,x);
}

int merge(int x,int y){
	if (!x||!y)return x|y;
	if (treap[x].key<treap[y].key){
		treap[x].r=merge(treap[x].r,y);
		update(x);
		return x;
	}
	treap[y].l=merge(x,treap[y].l);
	update(y);
	return y;
}

void add(int now,int l,int r,int x,int v){
	pir u=split(tree[now].rt,v);
	treap[++Nt].val=v;
	treap[Nt].tot=1;
	treap[Nt].key=getrand();
	tree[now].rt=merge(merge(u.first,Nt),u.second);
	if (l==r)return;
	int mid=(l+r)/2;
	if (x<=mid)add(tree[now].l,l,mid,x,v);
	else add(tree[now].r,mid+1,r,x,v);
}

bool request(int now,int l,int r,int x,int y,int key){
	if (x<=l&&r<=y){
		if (getv(tree[now].rt,dfn[key])<=R[key])return 1;
		return 0;
	}
	int mid=(l+r)/2;
	bool ret=0;
	if (x<=mid)ret=ret|request(tree[now].l,l,mid,x,y,key);
	if (!ret&&y>mid)ret=ret|request(tree[now].r,mid+1,r,x,y,key);
	return ret;
}

bool cmp(Route a,Route b){return dfn[a.y]<dfn[b.y];}

int main(){
	seed=20010419;
	n=get();
	fo(i,2,n){
		Fa[i]=get();
		rig[i]=lef[Fa[i]];
		lef[Fa[i]]=i;
	}
	dep[1]=1;
	dfs1(1);
	dfs2(1);
	m=get();
	build(rt,1,n);
	fo(i,1,m){
		r[i].x=get();
		r[i].y=get();
	}
	sort(r+1,r+1+m,cmp);
	fo(i,1,m){
		int z=lca(r[i].x,r[i].y);
		val[r[i].x]=pmin(val[r[i].x],z);
		val[r[i].y]=pmin(val[r[i].y],z);
		add(1,1,n,dfn[r[i].x],dfn[r[i].y]);
	}
	fd(i,n,1){
		for(int y=lef[i];y;y=rig[y])
		val[i]=pmin(val[i],val[y]);
		fa1[i][0]=val[i];
	}
	fo(i,1,n){
		dis[i]=dis[val[i]]+1;
		fo(j,1,log(n)/log(2))fa1[i][j]=fa1[fa1[i][j-1]][j-1];
	}
	q=get();
	fo(id,1,q){
		int x=get(),y=get();
		int tx=x,ty=y;
		fd(i,log(n)/log(2),0)tx=fa1[tx][i],ty=fa1[ty][i];
		if (tx!=ty){ans[id]=-1;continue;}
		int z=lca(x,y);
		if(dep[x]<dep[y])swap(x,y);
		if (y==z){
			tx=x;
			fd(i,log(n)/log(2),0)
			if (dep[fa1[tx][i]]>dep[y])tx=fa1[tx][i];
			ans[id]=dis[x]-dis[tx]+1;
			continue;
		}
		tx=x;ty=y;
		fd(i,log(n)/log(2),0)
		if (dep[fa1[tx][i]]>dep[z])tx=fa1[tx][i];
		fd(i,log(n)/log(2),0)
		if (dep[fa1[ty][i]]>dep[z])ty=fa1[ty][i];
		ans[id]=dis[x]-dis[tx]+dis[y]-dis[ty]+2;
		qry[id].x=tx,qry[id].y=ty;
		if (request(1,1,n,dfn[tx],R[tx],ty)||request(1,1,n,dfn[ty],R[ty],tx))ans[id]--;
	}
	fo(i,1,q)printf("%d\n",ans[i]);
	return 0;
}