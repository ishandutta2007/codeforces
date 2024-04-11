#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define pb push_back
#define mid (l+r>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)

using namespace std;
const int N=500005;
typedef long long LL;
const LL INF=10000000000000000ll;
int n,m,cnt,h[N],fa[N],c[N];
int d[N],siz[N];
struct edge{int v,c,n;} e[N];
LL dep[N<<1],t[N<<2],cur[N<<2],ans[N];
struct data{int x,l,r;} dat[N];
vector <int> vt[N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void addedge(int u,int v,int c)
{
	e[cnt]=(edge){v,c,h[u]},h[u]=cnt++;
	++d[u],++d[v];
}

void build(int l,int r,int rt)
{
	if(l==r)
	{
		t[rt]=d[l]==1?dep[l]:INF;
		return;
	}
	build(l,mid,lch);
	build(mid+1,r,rch);
	t[rt]=min(t[lch],t[rch]);
}

void turn(int rt,LL x)
{
	t[rt]+=x,cur[rt]+=x;
}

void pushdown(int rt)
{
	if(cur[rt]) turn(lch,cur[rt]),turn(rch,cur[rt]),cur[rt]=0;
}

void ins(int l,int r,int rt,int ql,int qr,LL x)
{
	if(ql<=l && r<=qr) {turn(rt,x); return;}
	pushdown(rt);
	if(ql<=mid) ins(l,mid,lch,ql,qr,x);
	if(mid<qr) ins(mid+1,r,rch,ql,qr,x);
	t[rt]=min(t[lch],t[rch]);
}

LL query(int l,int r,int rt,int ql,int qr)
{
	if(ql<=l && r<=qr) return t[rt];
	pushdown(rt);
	if(qr<=mid) return query(l,mid,lch,ql,qr);
	if(ql>mid) return query(mid+1,r,rch,ql,qr);
	return min(query(l,mid,lch,ql,qr),query(mid+1,r,rch,ql,qr));
}

void solve(int x)
{
	int sz=vt[x].size();
	rep(i,0,sz-1)
		ans[vt[x][i]]=query(1,n,1,dat[vt[x][i]].l,dat[vt[x][i]].r);
	for(int i=h[x]; i!=-1; i=e[i].n)
	{
		LL ad=e[i].c;
		turn(1,ad);
		ins(1,n,1,e[i].v,e[i].v+siz[e[i].v]-1,-2*ad);
		solve(e[i].v);
		ins(1,n,1,e[i].v,e[i].v+siz[e[i].v]-1,2*ad);
		turn(1,-ad);
	}
}

int main()
{
	n=getint(),m=getint();
	memset(h,-1,sizeof(h));
	rep(i,2,n) fa[i]=getint(),addedge(fa[i],i,c[i]=getint());
	repd(i,n,2) ++siz[i],siz[fa[i]]+=siz[i];
	rep(i,2,n) dep[i]=dep[fa[i]]+c[i];
	rep(i,1,m)
	{
		dat[i].x=getint(),dat[i].l=getint(),dat[i].r=getint();
		vt[dat[i].x].pb(i);
	}
	build(1,n,1);
	solve(1);
	rep(i,1,m) printf("%lld\n",ans[i]);
	return 0;
}