#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<set>
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

const int N = 100010;

struct flag{
	int tot;
	int ls[11],rs[11];
}ans;
struct point{
	int l,r;
	flag u;
}tree[N*2];
int tot,rt;
int A[11][N];
int n,m,q;
int rig;
int fa[50],k;
int vis[50],tim;
int id[50],t[50];

int getfather(int x){
	if (fa[x]==x)return fa[x];
	return fa[x]=getfather(fa[x]);
}

void merge(flag a,flag b,flag &c,int w){
	tim++;
	int as=0,bs=0;
	fo(i,0,n){
		if (vis[a.ls[i]]<tim){
			vis[a.ls[i]]=tim;
			as++;
		}
		if (vis[a.rs[i]]<tim){
			vis[a.rs[i]]=tim;
			as++;
		}
	}
	tim++;
	fo(i,0,n){
		if (vis[b.ls[i]]<tim){
			vis[b.ls[i]]=tim;
			bs++;
		}
		if (vis[b.rs[i]]<tim){
			vis[b.rs[i]]=tim;
			bs++;
		}
	}
	c.tot=a.tot+b.tot-as-bs;
	fo(i,1,as+bs)fa[i]=i;
	fo(i,0,n)
	if (A[i][w]==A[i][w+1]){
		int x=getfather(a.rs[i]),y=getfather(as+b.ls[i]);
		fa[x]=y;
	}
	fo(i,1,as+bs){
		int x=getfather(i);
		if (x==i)c.tot++;
	}
	k=0;
	fo(i,0,n){
		t[++k]=fa[a.ls[i]];
		t[++k]=fa[b.rs[i]+as];
	}
	sort(t+1,t+1+k);
	int k_=1;
	fo(i,2,k)
	if (t[i]>t[i-1])t[++k_]=t[i];
	k=k_;
	fo(i,1,k_)id[t[i]]=i;
	fo(i,0,n){
		c.ls[i]=id[fa[a.ls[i]]];
		c.rs[i]=id[fa[b.rs[i]+as]];
	}
}

void build(int &now,int l,int r){
	now=++tot;
	if (l==r){
		tree[now].u.tot=1;
		tree[now].u.ls[0]=1;
		fo(i,1,n)
		if (A[i][l]==A[i-1][l])tree[now].u.ls[i]=tree[now].u.ls[i-1];
		else tree[now].u.ls[i]=++tree[now].u.tot;
		fo(i,0,n)tree[now].u.rs[i]=tree[now].u.ls[i];
		return;
	}
	int mid=(l+r)/2;
	build(tree[now].l,l,mid);
	build(tree[now].r,mid+1,r);
	merge(tree[tree[now].l].u,tree[tree[now].r].u,tree[now].u,mid);
}

void getans(int now,int l,int r,int x,int y){
	if (x<=l&&r<=y){
		if (!rig)ans=tree[now].u;
		else merge(ans,tree[now].u,ans,rig);
		rig=r;
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid)getans(tree[now].l,l,mid,x,y);
	if (y>mid)getans(tree[now].r,mid+1,r,x,y);
}

int main(){
	n=get()-1;m=get();q=get();
	fo(i,0,n)
		fo(j,1,m)A[i][j]=get();
	build(rt,1,m);
	fo(cas,1,q){
		fo(i,0,n)ans.ls[i]=ans.rs[i]=0;
		ans.tot=0;
		rig=0;
		int l=get(),r=get();
		getans(1,1,m,l,r);
		printf("%d\n",ans.tot);
	}
	return 0;
}