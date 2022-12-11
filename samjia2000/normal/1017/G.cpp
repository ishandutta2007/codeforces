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

const int N = 1e5+5;

int n,q;
int fa[N];
int lef[N],rig[N];
struct Func{
	int a,b;
	Func(const int a_=0,const int b_=0){a=a_;b=b_;}
};
Func operator +(Func a,Func b){return Func(a.a+b.a,max(a.b+b.a,b.b));}
int be[N],u,tp[N],dfn[N],k,R[N];
int siz[N],mx[N];

void dfs1(int x){
	siz[x]=1;
	for(int y=lef[x];y;y=rig[y]){
		dfs1(y);
		siz[x]+=siz[y];
		if (!mx[x]||siz[y]>siz[mx[x]])mx[x]=y;
	}
}

void dfs2(int x){
	dfn[x]=++k;
	if (!mx[x]){
		tp[be[x]=++u]=x;
		R[x]=k;
		return;
	}
	dfs2(mx[x]);
	tp[be[x]=be[mx[x]]]=x;
	for(int y=lef[x];y;y=rig[y])
	if (y!=mx[x])dfs2(y);
	R[x]=k;
}

struct node{
	int l,r;
	Func v;
	bool cl;
}tree[N*2];
int a[N];
int rt,tot;

void build(int &now,int l,int r){
	now=++tot;
	tree[now].cl=0;
	if (l==r){
		tree[now].v=Func(-1,0);
		a[l]=0;
		return;
	}
	int mid=(l+r)/2;
	build(tree[now].l,l,mid);
	build(tree[now].r,mid+1,r);
	tree[now].v=tree[tree[now].l].v+tree[tree[now].r].v;
}

void down(int now,int l,int r){
	int mid=(l+r)/2;
	if (tree[now].cl){
		int x=tree[now].l;
		tree[x].v=Func(-(mid-l+1),0);
		if (l==mid)a[l]=0;
		tree[x].cl=1;
		
		x=tree[now].r;
		tree[x].v=Func(-(r-mid),0);
		if (r==mid+1)a[r]=0;
		tree[x].cl=1;
		
		tree[now].cl=0;
	}
}

void clear(int now,int l,int r,int x,int y){
	if (x<=l&&r<=y){
		tree[now].v=Func(-(r-l+1),0);
		if (l==r)a[l]=0;
		tree[now].cl=1;
		return;
	}
	down(now,l,r);
	int mid=(l+r)/2;
	if (x<=mid)clear(tree[now].l,l,mid,x,y);
	if (y>mid)clear(tree[now].r,mid+1,r,x,y);
	tree[now].v=tree[tree[now].l].v+tree[tree[now].r].v;
}

void change(int now,int l,int r,int x){
	if (l==r){
		tree[now].v=Func(a[x]-1,max(a[x],0));
		return;
	}
	down(now,l,r);
	int mid=(l+r)/2;
	if (x<=mid)change(tree[now].l,l,mid,x);
	else change(tree[now].r,mid+1,r,x);
	tree[now].v=tree[tree[now].l].v+tree[tree[now].r].v;
}

Func getv(int now,int l,int r,int x,int y){
	if (x<=l&&r<=y)return tree[now].v;
	down(now,l,r);
	int mid=(l+r)/2;
	Func ret=Func(0,0);
	if (x<=mid)ret=getv(tree[now].l,l,mid,x,y);
	if (y>mid)ret=ret+getv(tree[now].r,mid+1,r,x,y);
	return ret;
}

int query(int x){
	Func ret=Func(0,0);
	for(;x;){
		ret=getv(1,1,n,dfn[tp[be[x]]],dfn[x])+ret;
		x=fa[tp[be[x]]];
	}
	return max(ret.a,ret.b);
}

int main(){
	n=get();q=get();
	fo(i,2,n){
		fa[i]=get();
		rig[i]=lef[fa[i]];
		lef[fa[i]]=i;
	}
	dfs1(1);
	dfs2(1);
	build(rt,1,n);
	fo(cas,1,q){
		int ty=get(),x=get();
		if (ty==1){
			getv(1,1,n,dfn[x],dfn[x]);
			a[dfn[x]]++;
			change(1,1,n,dfn[x]);
		}
		if (ty==2){
			clear(1,1,n,dfn[x],R[x]);
			int val=query(x);
			getv(1,1,n,dfn[x],dfn[x]);
			a[dfn[x]]-=val;
			change(1,1,n,dfn[x]);
		}
		if (ty==3){
			int val=query(x);
			if (val>0)printf("black\n");
			else printf("white\n");
		}
	}
	return 0;
}