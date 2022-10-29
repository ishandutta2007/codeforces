#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back

using namespace std;
const int N=100005;
bool vis[N];
int n,m,h[N],cnt,scc,id[N],stk[N],dfn[N],low[N],lim,d[N],head,tail,q[N];
vector <int> vt[N],edg[N];
struct edge{int v,n;} e[N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void add(int u,int v)
{
	edg[u].pb(v),++d[v];
}

void addedge(int u,int v)
{
	e[cnt]=(edge){v,h[u]},h[u]=cnt++;
}

void tarjan(int x)
{
	dfn[x]=low[x]=++lim;
	vis[stk[++*stk]=x]=1;
	for(int i=h[x]; i!=-1; i=e[i].n)
	{
		int v=e[i].v;
		if(!dfn[v]) tarjan(v),low[x]=min(low[x],low[v]);
		else if(vis[v]) low[x]=min(low[x],dfn[v]);
	}
	if(dfn[x]==low[x])
	{
		++scc,vis[x]=0,id[x]=scc;
		while(stk[*stk]!=x) vis[stk[*stk]]=0,id[stk[(*stk)--]]=scc;
		--*stk;
	}
}

int query(int x,int y)
{
	printf("? %d %d\n",x,y),fflush(stdout);
	scanf("%d",&x);
	return x;
}

int merge(int x,int y)
{
	while(!vt[y].empty())
	{
		if(query(vt[x].back(),vt[y].back())) vt[y].pop_back();
		else vt[x].pop_back(),swap(x,y);
	}
	int sz=edg[y].size();
	rep(i,0,sz-1) if(!(--d[edg[y][i]])) q[++tail]=edg[y][i];
	return x;
}
	
int main()
{
	n=getint(),m=getint();
	memset(h,-1,sizeof(h));
	rep(i,1,m)
	{
		int u=getint(),v=getint();
		addedge(u,v);
	}
	rep(i,1,n) if(!dfn[i]) tarjan(i);
	rep(x,1,n)
	{
		vt[id[x]].pb(x);
		for(int i=h[x]; i!=-1; i=e[i].n)
			if(id[x]!=id[e[i].v])
				add(id[x],id[e[i].v]);
	}
	head=0,tail=-1;
	rep(i,1,scc) if(d[i]==0) q[++tail]=i;
	while(head<=tail)
	{
		int x=q[tail--],y=q[tail--];
		q[++tail]=merge(x,y);
	}
	printf("! %d\n",vt[q[head]].back());
	return 0;
}