#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
	
using namespace std;

typedef double db;
typedef long long LL;

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
const int INF = 1e9;

int n;
struct edge{
	int x,nxt;
}e[N*2];
int h[N],et;

void inse(int x,int y){e[++et].x=y;e[et].nxt=h[x];h[x]=et;}

int st[N],ed[N],len;
int f[N],g[N],mx[N];
int val[N];
struct node{
	int l,r,v,ad,left;
}tree[N*2];
int rt,tot;
int dep[N],fa[N];
int ans[N];

void dfs1(int x){
	f[x]=0;
	int fi=0,se=0;
	for(int p=h[x];p;p=e[p].nxt)
	if (!dep[e[p].x]){
		dep[e[p].x]=dep[x]+1;
		fa[e[p].x]=x;
		dfs1(e[p].x);
		f[x]=max(f[x],f[e[p].x]);
		if (fi<f[e[p].x]){
			se=fi;
			fi=f[e[p].x];
		}
		else se=max(se,f[e[p].x]);
		if (g[e[p].x]>g[x]){
			g[x]=g[e[p].x];
			mx[x]=e[p].x;
		}
	}
	g[x]=max(g[x],fi+se+1);
	f[x]++;
}

void dfs2(int x){
	if (!st[x]){
		st[x]=++len;
		ed[x]=len+g[x]-1;
		len=ed[x];
	}
	if (mx[x]){
		st[mx[x]]=st[x];
		ed[mx[x]]=st[mx[x]]+g[mx[x]]-1;
		dfs2(mx[x]);
	}
	for(int p=h[x];p;p=e[p].nxt)
	if (fa[e[p].x]==x&&e[p].x!=mx[x])dfs2(e[p].x);
}

int key[N],k;
int vis[N],tim;
int sef[N];

void build(int &now,int l,int r){
	now=++tot;
	tree[now].v=tree[now].ad=-INF;
	tree[now].left=l;
	if (l==r)return;
	int mid=(l+r)/2;
	build(tree[now].l,l,mid);
	build(tree[now].r,mid+1,r);
}

void down(int now,int l,int r){
	int mid=(l+r)/2;
	if (tree[now].ad!=-INF){
		int ad=tree[now].ad;tree[now].ad=-INF;
		int x=tree[now].l;
		tree[x].ad=max(tree[x].ad,ad);
		if (tree[x].left<=mid)tree[x].v=max(tree[x].v,ad-tree[x].left);
		x=tree[now].r;
		tree[x].ad=max(tree[x].ad,ad);
		if (tree[x].left<=r)tree[x].v=max(tree[x].v,ad-tree[x].left);
	}
}

int getmax(int now,int l,int r,int x,int y){
	if (x<=l&&r<=y)return tree[now].v;
	down(now,l,r);
	int mid=(l+r)/2,ret=-INF;
	if (x<=mid)ret=getmax(tree[now].l,l,mid,x,y);
	if (y>mid)ret=max(ret,getmax(tree[now].r,mid+1,r,x,y));
	return ret;
}

int getval(int now,int l,int r,int x){
	if (l==r)return tree[now].v;
	int mid=(l+r)/2;
	down(now,l,r);
	if (x<=mid)return getval(tree[now].l,l,mid,x);
	return getval(tree[now].r,mid+1,r,x);
}

void update(int now,int l,int r){
	tree[now].v=max(tree[tree[now].l].v,tree[tree[now].r].v);
	int mid=(l+r)/2;
	if (tree[tree[now].l].left<=mid)tree[now].left=tree[tree[now].l].left;
	else tree[now].left=tree[tree[now].r].left;
}

void change(int now,int l,int r,int x,int v){
	if (l==r){
		tree[now].v=v;
		return;
	}
	down(now,l,r);
	int mid=(l+r)/2;
	if (x<=mid)change(tree[now].l,l,mid,x,v);
	else change(tree[now].r,mid+1,r,x,v);
	update(now,l,r);
}

void add(int now,int l,int r,int x,int y,int v){
	if (x<=l&&r<=y){
		if (tree[now].ad<v){
			tree[now].ad=v;
			if (tree[now].left<=r)tree[now].v=max(tree[now].v,v-tree[now].left);
		}
		return;
	}
	down(now,l,r);
	int mid=(l+r)/2;
	if (x<=mid)add(tree[now].l,l,mid,x,y,v);
	if (y>mid)add(tree[now].r,mid+1,r,x,y,v);
	update(now,l,r);
}

void tag(int now,int l,int r,int x,int v){
	if (l==r){
		tree[now].left=l+1;
		tree[now].v=v;
		return;
	}
	down(now,l,r);
	int mid=(l+r)/2;
	if (x<=mid)tag(tree[now].l,l,mid,x,v);
	else tag(tree[now].r,mid+1,r,x,v);
	update(now,l,r);
}

void update(int now,int l,int r,int x){
	if(l==r){
		tree[now].ad=-INF;
		tree[now].left=l;
		return;
	}
	down(now,l,r);
	int mid=(l+r)/2;
	if (x<=mid)update(tree[now].l,l,mid,x);
	else update(tree[now].r,mid+1,r,x);
	update(now,l,r);
}

int Lim;

int getw(int now,int l,int r,int x,int y){
	if (tree[now].v<Lim)return 0;
	if (x<=l&&r<=y){
		if (l==r)return l;
		down(now,l,r);
		int mid=(l+r)/2;
		if (tree[tree[now].l].v==tree[now].v)return getw(tree[now].l,l,mid,x,y);
		return getw(tree[now].r,mid+1,r,x,y);
	}
	down(now,l,r);
	int mid=(l+r)/2,ret=0;
	if (x<=mid)ret=getw(tree[now].l,l,mid,x,y);
	if (!ret&&y>mid)ret=getw(tree[now].r,mid+1,r,x,y);
	return ret;
}

void getans(int x){
	int se=0;
	for(int p=h[x];p;p=e[p].nxt)
	if (fa[e[p].x]==x){
		getans(e[p].x);
		if (e[p].x!=mx[x])se=max(se,g[e[p].x]);
	}
	int L=g[mx[x]];
	k=0,tim++;
	fo(i,L+1,g[x]){
		vis[key[++k]=i]=tim;
		tag(1,1,len,st[x]+i-1,dep[x]-i);
	}
	for(int p=h[x];p;p=e[p].nxt)
	if (fa[e[p].x]==x&&e[p].x!=mx[x]){
		int y=e[p].x;
		fo(i,1,g[y])
		if (vis[i]<tim){
			int vx=getval(1,1,len,st[x]+i-1),vy=getval(1,1,len,st[y]+i-1);
			if (vx+vy+i-dep[x]*2-1>=0){
				vis[key[++k]=i]=tim;
				tag(1,1,len,st[x]+i-1,dep[x]-i);
			}
			else
				if (vy>vx)change(1,1,len,st[x]+i-1,vy);
		}
		//g[y]+1..L
		if (g[y]<L){
			int tmp=getmax(1,1,len,st[x]+g[y],st[x]+L-1);
			while(tmp-dep[x]+f[y]>=0){
				Lim=tmp;
				int w=getw(1,1,len,st[x]+g[y],st[x]+L-1);
				w=w-st[x]+1;
				vis[key[++k]=w]=tim;
				tag(1,1,len,st[x]+w-1,dep[x]-w);
				tmp=getmax(1,1,len,st[x]+g[y],st[x]+L-1);
			}
			add(1,1,len,st[x]+g[y],st[x]+L-1,dep[x]+f[y]+st[x]);
		}
	}
	int tmp=getmax(1,1,len,st[x],ed[x]);
	while(tmp>=dep[x]){
		Lim=tmp;
		int w=getw(1,1,len,st[x],ed[x]);
		w=w-st[x]+1;
		vis[key[++k]=w]=tim;
		tag(1,1,len,st[x]+w-1,dep[x]-w);
		tmp=getmax(1,1,len,st[x],ed[x]);
	}
	fo(i,1,k){
		ans[key[i]]++;
		update(1,1,len,st[x]+key[i]-1);
	}
}

int main(){
	n=get();
	fo(i,2,n){
		int x=get(),y=get();
		inse(x,y),inse(y,x);
	}
	tree[0].v=-INF;
	dep[1]=1;
	dfs1(1);
	dfs2(1);
	build(rt,1,len);
	getans(1);
	fo(i,1,n)printf("%d\n",ans[i]);
	return 0;
}