#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=100005;
int T,n,a,b,da,db,cnt,h[N];
int R,Dis,dis[N];
struct edge{int v,n;} e[N<<1];

void addedge(int u,int v)
{
	e[cnt]=(edge){v,h[u]},h[u]=cnt++;
	e[cnt]=(edge){u,h[v]},h[v]=cnt++;
}

void dfs1(int x,int fa,int d=0)
{
	dis[x]=d;
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=fa) dfs1(e[i].v,x,d+1);
}

int query()
{
	dfs1(1,0);
	int mx=0;
	rep(i,1,n) mx=max(mx,dis[i]);
	rep(i,1,n) if(mx==dis[i]) {dfs1(i,0); break;}
	rep(i,1,n) mx=max(mx,dis[i]);
	return mx;
}

int dfs(int x,int fa)
{
	if(x==b) return 0;
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=fa)
		{
			int rt=dfs(e[i].v,x);
			if(rt!=-1) return rt+1;
		}
	return -1;
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d%d",&n,&a,&b,&da,&db);
		rep(i,1,n) h[i]=-1;
		cnt=0;
		rep(i,1,n-1)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			addedge(x,y);
		}
		R=query();
		Dis=dfs(a,0);
		if(Dis<=da) puts("Alice");
		else if(da>=db) puts("Alice");
		else if(db<=2*da) puts("Alice");
		else if(R>2*da) puts("Bob");
		else puts("Alice");
	}
	return 0;
}