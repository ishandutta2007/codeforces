#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<set>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mp make_pair
#define mid (l+r>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)

using namespace std;
const int N=1000005;
int n,k,a[N],cur[N<<2],t0[N<<2],t1[N<<2];
int cnt,h[N],dfn[N],siz[N],tot,ql,qr,x,t[N];
struct edge{int v,n;} e[N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void addedge(int u,int v)
{
	e[cnt]=(edge){v,h[u]},h[u]=cnt++;
}

void dfs(int x)
{
	siz[x]=1,dfn[x]=++tot;
	for(int i=h[x]; i!=-1; i=e[i].n)
		dfs(e[i].v),siz[x]+=siz[e[i].v];
}

void turn(int rt,int x)
{
	cur[rt]+=x,t0[rt]+=x;
	if(t1[rt]) t1[rt]+=x;
}

void pushdown(int rt)
{
	if(cur[rt])
		turn(lch,cur[rt]),turn(rch,cur[rt]),cur[rt]=0;
}

void ins(int l,int r,int rt)
{
	if(ql<=l && r<=qr)
	{
		turn(rt,1);
		return;
	}
	pushdown(rt);
	if(ql<=mid) ins(l,mid,lch);
	if(mid<qr) ins(mid+1,r,rch);
	t0[rt]=max(t0[lch],t0[rch]);
	t1[rt]=max(t1[lch],t1[rch]);
}

void rever(int l,int r,int rt)
{
	if(l==r)
	{
		if(!t1[rt]) t1[rt]=t0[rt];
		else t1[rt]=0;
		return;
	}
	pushdown(rt);
	if(x<=mid) rever(l,mid,lch);
	else rever(mid+1,r,rch);
	t0[rt]=max(t0[lch],t0[rch]);
	t1[rt]=max(t1[lch],t1[rch]);
}

void ins(int x,int y)
{
	for(int i=x; i; i-=i&-i) t[i]=min(t[i],y);
}

int query(int x)
{
	int rt=n+1;
	for(int i=x; i<=n+1; i+=i&-i) rt=min(t[i],rt);
	return rt;
}

int main()
{
	n=getint(),k=getint();
	rep(i,1,n) a[i]=getint();
	rep(i,1,n+1) t[i]=n+1;
	memset(h,-1,sizeof(h));
	repd(i,n,1)
	{
		int x=query(a[i]+1);
		addedge(x,i),ins(a[i],i);
	}
	dfs(n+1);
	rep(i,1,k)
	{
		ql=dfn[i],qr=ql+siz[i]-1,ins(1,n+1,1);
		x=dfn[i],rever(1,n+1,1);
	}
	printf("%d",t1[1]);
	rep(i,k+1,n)
	{
		ql=dfn[i],qr=ql+siz[i]-1,ins(1,n+1,1);
		x=dfn[i],rever(1,n+1,1),x=dfn[i-k],rever(1,n+1,1);
		printf(" %d",t1[1]);
	}
	puts("");
	return 0;
}