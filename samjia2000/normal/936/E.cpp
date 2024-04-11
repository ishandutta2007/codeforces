/*
Author:samjia2000
Problem:CF936E
*/
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

const int N = 300005;
const int INF = 1e9;

int n;
struct city{
	int x,y,id;
}a[N];
int be[N],m;
int cnt[N],yc[N][2],X[N];
int h[N],tot,hc[N],totc;
struct edge{
	int x,nxt;
}e[N*4],ec[N*4];
int fx[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
map<int,int>id[N];

bool cmp1(city a,city b){return a.x==b.x?a.y<b.y:a.x<b.x;}
bool cmp(city a,city b){return a.id<b.id;}

void inse(int x,int y){e[++tot].x=y;e[tot].nxt=h[x];h[x]=tot;}
void insec(int x,int y){ec[++totc].x=y;ec[totc].nxt=hc[x];hc[x]=totc;}

int dep[N],dis[N][20],Fa[N],co[N][20];
int key,mx[N],siz[N],vis_blk[N],vis_city[N],tim;
int fa[N];
int que[N];
bool bz[N];

void getkey(int blk){
	int he=0,ta=1;
	vis_blk[que[1]=blk]=++tim;
	fa[blk]=0;
	int sum=0;
	for(;he<ta;){
		int x=que[++he];
		sum+=cnt[x];
		mx[x]=siz[x]=0;
		for(int p=h[x];p;p=e[p].nxt)
		if (!bz[e[p].x]&&vis_blk[e[p].x]<tim){
			vis_blk[que[++ta]=e[p].x]=tim;
			fa[e[p].x]=x;
		}
	}
	key=0;
	fd(i,ta,1){
		int x=que[i];
		siz[x]+=cnt[x];
		mx[x]=max(mx[x],sum-siz[x]);
		if (fa[x])siz[fa[x]]+=siz[x],mx[fa[x]]=max(mx[fa[x]],siz[x]);
		if (!key||mx[x]<mx[key])key=x;
	}
}

void bfs(int blk,int depth){
	int he=0,ta=0;
	tim++;
	fo(i,yc[blk][0],yc[blk][1]){
		int y=id[X[blk]][i];
		vis_city[y]=tim;
		que[++ta]=y;
		dis[y][depth]=0;
		co[y][depth]=i;
	}
	for(;he<ta;){
		int x=que[++he];
		for(int p=hc[x];p;p=ec[p].nxt)
		if (vis_city[ec[p].x]<tim&&!bz[be[ec[p].x]]){
			vis_city[que[++ta]=ec[p].x]=tim;
			dis[ec[p].x][depth]=dis[x][depth]+1;
			co[ec[p].x][depth]=co[x][depth];
		}
	}
}

int root[N],ct;
struct node{
	int l,r,val0,val1;
}tree[N*27];

int build(int up,int depth){
	getkey(up);
	int x=key;
	bz[x]=1;
	dep[x]=depth;
	bfs(x,depth);
	for(int p=h[x];p;p=e[p].nxt)
	if (!bz[e[p].x])Fa[build(e[p].x,depth+1)]=x;
	return x;
}

void prepare(){
	sort(a+1,a+1+n,cmp1);
	fo(i,1,n){
		if (i>1&&a[i].x==a[i-1].x&&a[i].y==a[i-1].y+1)be[a[i].id]=be[a[i-1].id];
		else be[a[i].id]=++m;
	}
	sort(a+1,a+1+n,cmp);
	fo(i,1,m)yc[i][0]=N,yc[i][1]=0;
	fo(i,1,n){
		int t=be[i];
		yc[t][0]=min(yc[t][0],a[i].y);
		yc[t][1]=max(yc[t][1],a[i].y);
		cnt[t]++;
		X[t]=a[i].x;
		fo(u,0,3){
			int x1=a[i].x+fx[u][0],y1=a[i].y+fx[u][1];
			if (!id[x1][y1])continue;
			int s=be[id[x1][y1]];
			if (t!=s)inse(t,s);
			insec(i,id[x1][y1]);
		}
	}
	tree[0].val0=tree[0].val1=INF;
	build(1,1);
}

void change(int &now,int l,int r,int x,int v0,int v1){
	if (!now){
		now=++ct;
		tree[now].val0=tree[now].val1=INF;
	}
	tree[now].val0=min(tree[now].val0,v0);
	tree[now].val1=min(tree[now].val1,v1);
	if (l==r)return;
	int mid=(l+r)/2;
	if (x<=mid)change(tree[now].l,l,mid,x,v0,v1);
	else change(tree[now].r,mid+1,r,x,v0,v1);
}

void add(int x){
	int now=be[x];
	for(;now;now=Fa[now]){
		int depth=dep[now];
		change(root[now],yc[now][0],yc[now][1],co[x][depth],dis[x][depth]-co[x][depth],dis[x][depth]+co[x][depth]);
	}
}

int ask0(int now,int l,int r,int x){
	if (!now||x<l)return INF;
	if (r<=x)return tree[now].val0;
	int mid=(l+r)/2;
	return min(ask0(tree[now].l,l,mid,x),ask0(tree[now].r,mid+1,r,x));
}

int ask1(int now,int l,int r,int x){
	if (x>r||!now)return INF;
	if (x<=l)return tree[now].val1;
	int mid=(l+r)/2;
	return min(ask1(tree[now].l,l,mid,x),ask1(tree[now].r,mid+1,r,x));
}

int query(int x){
	int ret=INF,now=be[x];
	for(;now;now=Fa[now]){
		int depth=dep[now];
		ret=min(ret,ask0(root[now],yc[now][0],yc[now][1],co[x][depth])+dis[x][depth]+co[x][depth]);
		ret=min(ret,ask1(root[now],yc[now][0],yc[now][1],co[x][depth])+dis[x][depth]-co[x][depth]);
	}
	return ret>1e8?-1:ret;
}

void work(){
	int q=get();
	fo(cas,1,q){
		int ty=get(),x=get(),y=get();
		x=id[x][y];
		if (ty==1)add(x);
		else printf("%d\n",query(x));
	}
}

int main(){
	n=get();
	fo(i,1,n){
		a[i].x=get();a[i].y=get();
		a[i].id=i;
		id[a[i].x][a[i].y]=i;
	}
	prepare();
	work();
	return 0;
}