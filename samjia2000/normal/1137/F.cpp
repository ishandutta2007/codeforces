#include<bits/stdc++.h>

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

int n,q;
struct edge{
	int x,nxt;
}e[N*2];
int h[N],tot;
int fa[N];
struct node{
	int s[2];
	bool bz;
	int col,siz;
}tree[N];
int a[N],lim,rt;

int bit[N*2];

void add(int x,int v){for(;x<=n+q;x+=x&-x)bit[x]+=v;}

int query(int x){int ret=0;for(;x;x-=x&-x)ret+=bit[x];return ret;}

void inse(int x,int y){e[++tot].x=y;e[tot].nxt=h[x];h[x]=tot;}

int mx[N];

void update(int x){
	tree[x].siz=tree[tree[x].s[0]].siz+tree[tree[x].s[1]].siz+1;
}

void down(int x){
	if (tree[x].bz){
		int y=tree[x].s[0];
		if (y)swap(tree[y].s[0],tree[y].s[1]),tree[y].bz^=1;
		y=tree[x].s[1];
		if (y)swap(tree[y].s[0],tree[y].s[1]),tree[y].bz^=1;
		tree[x].bz=0;
	}
	if (tree[x].s[0])tree[tree[x].s[0]].col=tree[x].col;
	if (tree[x].s[1])tree[tree[x].s[1]].col=tree[x].col;
}

int pd(int x){
	if (x==tree[fa[x]].s[0])return 0;
	if (x==tree[fa[x]].s[1])return 1;
	return -1;
}

int key[N];

void clear(int x){
	int k=0;
	for(;pd(x)!=-1;x=fa[x])key[++k]=x;
	key[++k]=x;
	for(;k;k--)down(key[k]);
}

void rotate(int x){
	int y=fa[x],z=fa[y];
	int tx=pd(x),ty=pd(y);
	if (ty!=-1)tree[z].s[ty]=x;
	fa[x]=z;
	if (tree[x].s[tx^1])fa[tree[x].s[tx^1]]=y;
	tree[y].s[tx]=tree[x].s[tx^1];
	tree[x].s[tx^1]=y;
	fa[y]=x;
	update(y);
	update(x);
	if (ty!=-1)update(z);
}

void splay(int x){
	clear(x);
	for(;pd(x)!=-1;){
		if (pd(fa[x])!=-1){
			if (pd(x)==pd(fa[x]))rotate(fa[x]);
			else rotate(x);
		}
		rotate(x);
	}
}

void paint(int x,int c){
	splay(x);
	tree[x].s[1]=0;
	update(x);
	add(tree[x].col,-tree[x].siz);
	tree[x].col=0;
	for(;fa[x];){
		int y=fa[x];
		splay(y);
		tree[y].s[1]=0;
		update(y);
		add(tree[y].col,-tree[y].siz);
		tree[y].s[1]=x,tree[y].col=0;
		update(y);
		splay(x);
	}
}

int getid(int x){
	if (x==rt)return n;
	splay(x);
	int ret=query(tree[x].col)-tree[tree[x].s[0]].siz;
	return ret;
}

void dfs(int x){
	mx[x]=a[x];
	int t=x;
	for(int p=h[x];p;p=e[p].nxt)
		if (!mx[e[p].x]){
			int y=e[p].x;
			fa[y]=x;
			dfs(y);
			if (mx[y]>mx[x]){
				mx[x]=max(mx[x],mx[y]);
				t=y;
			}
		}
	add(mx[x],1);
	tree[x].col=mx[x];
	tree[x].siz=1;
	if (t!=x){
		splay(t);
		tree[x].s[1]=t;
		update(x);
	}
}


int main(){
	n=get();q=get();
	fo(i,2,n){
		int x=get(),y=get();
		inse(x,y);
		inse(y,x);
	}
	fo(i,1,n)a[i]=i;
	dfs(n);
	rt=lim=n;
	fo(cas,1,q){
		char s[20];
		scanf("%s",s+1);
		if (s[1]=='u'){
			int x=get();
			paint(x,lim);
			a[rt=x]=++lim;
			splay(x);
			swap(tree[x].s[0],tree[x].s[1]);
			tree[x].bz^=1;
			tree[x].col=lim-1;
			add(lim-1,tree[x].siz);
		}
		if (s[1]=='w'){
			int x=get();
			int id=getid(x);
			printf("%d\n",id);
		}
		if (s[1]=='c'){
			int x=get(),y=get();
			int ix=getid(x),iy=getid(y);
			printf("%d\n",ix<iy?x:y);
		}
	}
	return 0;
}