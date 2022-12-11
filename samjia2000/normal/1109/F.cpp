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

const int N = 1e3+5;
const int MAXN = 2e5+5;

int n,m;
int a[N][N];
int lef[MAXN];
vector<int>to[MAXN];
struct node{
	int ad,mi,tot;
}tree[MAXN*2];

void build(int now,int l,int r){
	tree[now].mi=0;
	tree[now].tot=r-l+1;
	if (l==r)return;
	int mid=(l+r)/2;
	int ls=now+1,rs=now+(mid-l+1)*2;
	build(ls,l,mid);
	build(rs,mid+1,r);
}

void down(int now,int ls,int rs){
	tree[ls].mi+=tree[now].ad;
	tree[ls].ad+=tree[now].ad;
	tree[rs].mi+=tree[now].ad;
	tree[rs].ad+=tree[now].ad;
	tree[now].ad=0;
}

void update(int now,int ls,int rs){
	tree[now].mi=tree[ls].mi,tree[now].tot=tree[ls].tot;
	if (tree[rs].mi<tree[now].mi)tree[now].mi=tree[rs].mi,tree[now].tot=0;
	if (tree[rs].mi==tree[now].mi)tree[now].tot+=tree[rs].tot;
}

void change(int now,int l,int r,int x,int y,int v){
	if (x<=l&&r<=y){
		tree[now].mi+=v;
		tree[now].ad+=v;
		return;
	}
	int mid=(l+r)/2;
	int ls=now+1,rs=now+(mid-l+1)*2;
	down(now,ls,rs);
	if (x<=mid)change(ls,l,mid,x,y,v);
	if (y>mid)change(rs,mid+1,r,x,y,v);
	update(now,ls,rs);
}

int getans(int now,int l,int r,int x,int y){
	if (x<=l&&r<=y)return tree[now].mi==1?tree[now].tot:0;
	int mid=(l+r)/2;
	int ls=now+1,rs=now+(mid-l+1)*2;
	down(now,ls,rs);
	int ret=0;
	if (x<=mid)ret=getans(ls,l,mid,x,y);
	if (y>mid)ret+=getans(rs,mid+1,r,x,y);
	return ret;
}

struct point{
	int s[2];
	int val,mi;
	bool bz;
}pt[MAXN];
int fa[MAXN],u;
int L_most;

void update(int x){
	pt[x].mi=min(pt[pt[x].s[0]].mi,pt[pt[x].s[1]].mi);
	pt[x].mi=min(pt[x].mi,pt[x].val);
}

void down(int x){
	if (pt[x].bz){
		swap(pt[x].s[0],pt[x].s[1]);
		pt[pt[x].s[0]].bz^=1;
		pt[pt[x].s[1]].bz^=1;
		pt[x].bz=0;
	}
}

int pd(int x){
	if (x==pt[fa[x]].s[0])return 0;
	if (x==pt[fa[x]].s[1])return 1;
	return -1;
}

void rotate(int x){
	int y=fa[x],z=fa[y];
	int tx=pd(x),ty=pd(y);
	if (ty!=-1)pt[z].s[ty]=x;
	fa[x]=z;
	if (pt[x].s[tx^1])fa[pt[x].s[tx^1]]=y;
	pt[y].s[tx]=pt[x].s[tx^1];
	pt[x].s[tx^1]=y;
	fa[y]=x;
	update(y);
	update(x);
	if(ty!=-1)update(z);
}

int key[MAXN];

void clear(int x){
	int k=0;
	for(;pd(x)!=-1;x=fa[x])key[++k]=x;
	key[++k]=x;
	fd(i,k,1)down(key[i]);
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

void access(int x){
	splay(x);
	pt[x].s[1]=0;update(x);
	for(;fa[x];){
		int y=fa[x];
		splay(y);
		pt[y].s[1]=x;update(y);
		splay(x);
	}
}

void makeroot(int x){
	access(x);
	splay(x);
	pt[x].bz^=1;
}

void add(int x,int y){
	makeroot(x);makeroot(y);
	if (!fa[x]){fa[x]=y;return;}
	int z=pt[y].mi;
	if (z==x){L_most=max(L_most,x+1);return;}
	L_most=max(L_most,z+1);
	splay(z);
	int p=pt[z].s[0];
	fa[p]=0;
	pt[z].s[0]=0;
	update(z);
	makeroot(x);makeroot(y);
	fa[x]=y;
}

int main(){
	n=get();m=get();
	fo(i,1,n)fo(j,1,m)a[i][j]=get();
	fo(i,1,n)
		fo(j,1,m-1){
			int l=min(a[i][j],a[i][j+1]),r=max(a[i][j],a[i][j+1]);
			to[r].push_back(l);
		}
	fo(i,1,n-1)
		fo(j,1,m){
			int l=min(a[i][j],a[i+1][j]),r=max(a[i][j],a[i+1][j]);
			to[r].push_back(l);
		}
	int k=n*m;
	build(1,1,k);
	LL ans=0;
	L_most=1;
	u=k;
	fo(i,1,k)pt[i].mi=pt[i].val=i;
	pt[0].mi=pt[0].val=1e9;
	fo(i,1,k){
		change(1,1,k,1,i,1);
		for(auto c:to[i]){
			change(1,1,k,1,c,-1);
			add(c,i);
		}
		ans=ans+getans(1,1,k,L_most,i);
	}
	cout<<ans<<endl;
	return 0;
}