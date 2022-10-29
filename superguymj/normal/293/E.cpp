#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=100005,INF=1000000000;
bool vis[N];
int n,l,w,h[N],u,c,cnt,p,tot,root,minn,siz[N],t[N],maxn[N],sum;
typedef long long LL;
LL ans;
struct edge{int v,c,n;} e[N<<1];
struct data{int l,w;} dat[N];

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
	e[cnt]=(edge){u,c,h[v]},h[v]=cnt++;
}

void add(int x,int y)
{
	for(; x<=n+1; x+=x&-x) t[x]+=y;
}

int query(int x)
{
	int rt=0;
	for(; x; x-=x&-x) rt+=t[x];
	return rt;
}

void get_siz(int x,int fa)
{
	siz[x]=1,maxn[x]=0;
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=fa && !vis[e[i].v])
			get_siz(e[i].v,x),siz[x]+=siz[e[i].v],maxn[x]=max(maxn[x],siz[e[i].v]);
}

void get_root(int x,int fa)
{
	if(minn>max(maxn[x],sum-siz[x]))
		minn=max(maxn[x],sum-siz[x]),root=x;
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=fa && !vis[e[i].v])
			get_root(e[i].v,x);
}

void get_dis(int x,int fa,int l,int w)
{
	dat[++tot]=(data){l,w};
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=fa && !vis[e[i].v])
			get_dis(e[i].v,x,l+1,w+e[i].c);
}

bool cmp(data a,data b)
{
	return a.w<b.w;
}

LL calc(int x,int l,int w)
{
	LL rt=0;
	tot=0,get_dis(x,0,0,0),p=tot+1;
	sort(dat+1,dat+1+tot,cmp);
	rep(i,1,tot) add(dat[i].l+1,1);
	rep(i,1,tot)
	{
		while(p-1>0 && dat[p-1].w+dat[i].w>w) --p,add(dat[p].l+1,-1);
		if(l-dat[i].l+1>0) rt+=query(l-dat[i].l+1);
	}
	rep(i,1,p-1) add(dat[i].l+1,-1);
	return rt;
}

void dfs(int x)
{
	get_siz(x,0);
	sum=siz[x],minn=INF;
	get_root(x,0),vis[root]=1;
	ans+=calc(root,l,w);
	for(int i=h[root]; i!=-1; i=e[i].n)
		if(!vis[e[i].v])
			ans-=calc(e[i].v,l-2,w-2*e[i].c),dfs(e[i].v);
}

int main()
{
//	freopen("cf293E.in","r",stdin);
	n=getint(),l=getint(),w=getint(),memset(h,-1,sizeof(h));
	rep(i,2,n) u=getint(),c=getint(),addedge(i,u,c);
	dfs(1);
	printf("%I64d\n",(ans-n)>>1);
	return 0;
}