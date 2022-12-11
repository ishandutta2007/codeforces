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

const int N = 50005;

int n,m,q,C;
int col[N];
set<int>kp[N];
int dfn[N],k,R[N];
int dep[N];
int rmq[N*2][20],fir[N],u;
int cst[N];
int fa[N];
int lef[N],rig[N];
int nowc;
map<int,int>Dfn[N],Rig[N],Fa[N];
int d[N*4];

void dfs(int x){
	dfn[x]=++k;
	rmq[fir[x]=++u][0]=x;
	for(int y=lef[x];y;y=rig[y]){
		dep[y]=dep[x]+1;
		dfs(y);
		rmq[++u][0]=x;
	}
	R[x]=k;
}

void getrmq(){
	fo(j,1,log(u)/log(2))
		fo(i,1,u-(1<<j)+1)
		rmq[i][j]=dep[rmq[i][j-1]]<dep[rmq[i+(1<<(j-1))][j-1]]?rmq[i][j-1]:rmq[i+(1<<(j-1))][j-1];
}

int lca(int x,int y){
	x=fir[x],y=fir[y];
	if (x>y)swap(x,y);
	int t=log(y-x+1)/log(2);
	return dep[rmq[x][t]]<dep[rmq[y-(1<<t)+1][t]]?rmq[x][t]:rmq[y-(1<<t)+1][t];
}

bool cmp(int x,int y){return dfn[x]<dfn[y];}

struct operation{
	int ty,x,w;
}op[N];
struct node{
	int fa,s[2],tot,siz,sum,ext;
	LL val;
	//sum:splayext+siz
	//siz:sum
	//val:(siz+ext)*dep
}tree[N*4];
int key[N*2];
LL ans[N];

void build(int x){
	Dfn[x][nowc]=++k;
	d[k]=x;
	for(int y=lef[x];y;y=rig[y]){
		build(y);
		tree[Dfn[y][nowc]].fa=Dfn[x][nowc];
	}
	Rig[x][nowc]=k;
}

void update(int x){
	tree[x].tot=tree[tree[x].s[0]].tot+tree[tree[x].s[1]].tot+1;
	tree[x].sum=tree[tree[x].s[0]].sum+tree[tree[x].s[1]].sum+tree[x].ext+tree[x].siz;
	tree[x].val=tree[tree[x].s[0]].val+tree[tree[x].s[1]].val+1ll*dep[d[x]]*(tree[x].siz+tree[x].ext);
}

int pd(int x){
	if (x==tree[tree[x].fa].s[0])return 0;
	if (x==tree[tree[x].fa].s[1])return 1;
	return -1;
}

void rotate(int x){
	int y=tree[x].fa,z=tree[y].fa;
	int tx=pd(x),ty=pd(y);
	if (ty!=-1)tree[z].s[ty]=x;
	tree[x].fa=z;
	if (tree[x].s[tx^1])tree[tree[x].s[tx^1]].fa=y;
	tree[y].s[tx]=tree[x].s[tx^1];
	tree[y].fa=x;
	tree[x].s[tx^1]=y;
	update(y);
	update(x);
	if (ty!=-1)update(z);
}

void splay(int x){
	while(pd(x)!=-1){
		if (pd(tree[x].fa)!=-1){
			if(pd(x)==pd(tree[x].fa))rotate(tree[x].fa);
			else rotate(x);
		}
		rotate(x);
	}
}

void access(int x){
	splay(x);
	if (tree[x].s[1]){
		int y=tree[x].s[1];
		tree[x].s[1]=0;
		splay(y);
		tree[x].siz=tree[x].siz+tree[y].sum;
		update(x);
	}
	while(tree[x].fa){
		int y=tree[x].fa;
		splay(y);
		if (tree[y].s[1]){
			int z=tree[y].s[1];
			tree[y].s[1]=0;
			splay(z);
			tree[y].siz=tree[y].siz+tree[z].sum;
			update(y);
		}
		tree[y].s[1]=x;
		tree[y].siz=tree[y].siz-tree[x].sum;
		update(y);
		x=y;
	}
}

void Insert(int id,int col){
	int x=Dfn[id][col];
	access(x);
	splay(x);
	ans[col]=ans[col]+1ll*(tree[x].val*2+dep[id])*cst[col]*cst[col]-2ll*dep[id]*cst[col]*C;
	tree[x].ext=1;
	update(x);
}

void Delete(int id,int col){
	int x=Dfn[id][col];
	access(x);
	splay(x);
	ans[col]=ans[col]-1ll*(tree[x].val*2-dep[id])*cst[col]*cst[col]+2ll*dep[id]*cst[col]*C;
	tree[x].ext=0;
	update(x);
}

int main(){
	n=get();m=get();q=get();C=get();
	fo(i,1,n)col[i]=get();
	fo(i,1,n)kp[col[i]].insert(i);
	fo(i,2,n){
		fa[i]=get();
		rig[i]=lef[fa[i]];
		lef[fa[i]]=i;
	}
	fo(i,1,m)cst[i]=get();
	dfs(dep[1]=1);
	getrmq();
	k=0;
	fo(i,1,q){
		op[i].ty=get();
		op[i].x=get();
		if (op[i].ty==1){
			op[i].w=get();
			kp[op[i].w].insert(op[i].x);
		}
	}
	fo(i,1,n)lef[i]=rig[i]=0;
	fo(cl,1,m){
		nowc=cl;
		int l=0;
		for(set<int>::iterator h=kp[cl].begin();h!=kp[cl].end();h++)key[++l]=*h;
		if (!l)continue;
		sort(key+1,key+1+l,cmp);
		int l1=l;
		fo(i,2,l1)key[++l]=lca(key[i-1],key[i]);
		sort(key+1,key+1+l,cmp);
		int l_=1;
		fo(i,2,l)if (key[i]!=key[i-1])key[++l_]=key[i];
		l=l_;
		fo(i,1,l)lef[key[i]]=rig[key[i]]=0;
		int rt=key[1];
		fo(i,2,l){
			int x=key[i],y=key[i-1];
			while(!(dfn[y]<=dfn[x]&&dfn[x]<=R[y]))y=Fa[y][cl];
			Fa[x][cl]=y;
			rig[x]=lef[y];
			lef[y]=x;
		}
		build(rt);
	}
	fo(i,1,k)tree[i].tot=1;
	fo(i,1,m)ans[i]=1ll*n*C*C;
	fo(i,1,n)Insert(i,col[i]);
	fo(cq,1,q){
		int ty=op[cq].ty,x=op[cq].x,w=op[cq].w;
		if (ty==1){
			Delete(x,col[x]);
			col[x]=w;
			Insert(x,w);
		}
		else printf("%.9lf\n",1.0*ans[x]/n);
	}
	return 0;
}