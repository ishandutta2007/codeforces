#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
const int N=100005;
int n,u,v,c,h[N],cnt,tot,p[N];
LL ans[N],sum[N],siz[N];
struct edge{int v,c,n;} e[N<<1];

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

void dfs1(int x,int fa)
{
	siz[x]=1;
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=fa)
		{
			dfs1(e[i].v,x);
			siz[x]+=siz[e[i].v];
			sum[e[i].v]+=2*e[i].c;
			sum[x]+=sum[e[i].v];
		}
}

bool cmp(int x,int y)
{
	return siz[y]*sum[x]<siz[x]*sum[y];
}

void dfs2(int x,int fa)
{
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=fa)
			dfs2(e[i].v,x),ans[e[i].v]+=e[i].c*siz[e[i].v];
	tot=0;
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=fa)
			p[++tot]=e[i].v;
	sort(p+1,p+1+tot,cmp);
	LL sm=0;
	rep(i,1,tot) sm+=sum[p[i-1]],ans[x]+=ans[p[i]]+sm*siz[p[i]];
}

namespace spj
{
	const int INF=1000000000;
	bool vis[N];
	int ans,mp[1005][1005],a[N];

	void dfs(int rt,int x,int fa,int d)
	{
		mp[rt][x]=d;
		for(int i=h[x]; i!=-1; i=e[i].n)
			if(e[i].v!=fa) dfs(rt,e[i].v,x,d+e[i].c);
	}
	
	void solve(int x)
	{
		if(x>n)
		{
			int sz=0,ret=0;
			rep(i,2,n) sz+=mp[a[i]][a[i-1]],ret+=sz;
			ans=min(ans,ret);
			return;
		}
		rep(i,2,n) if(!vis[i])
		{
			a[x]=i,vis[i]=1,solve(x+1);
			vis[i]=0;
		}
	}

	void solve()
	{
		rep(i,1,n) dfs(i,i,0,0);
		ans=INF,a[1]=1,vis[1]=1;
		solve(2);
		printf("%.10lf\n",(double)ans/(n-1));
	}
}

int main()
{
	n=getint();
	memset(h,-1,sizeof(h));
	rep(i,1,n-1)
	{
		u=getint(),v=getint(),c=getint();
		addedge(u,v,c);
	}
	dfs1(1,0);
	dfs2(1,0);
	printf("%.10lf\n",(double)ans[1]/(n-1));
	return 0;
}