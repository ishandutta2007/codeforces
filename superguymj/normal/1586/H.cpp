#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define pb push_back

using namespace std;
const int N=200005;
int n,q,a[N],h[N],cnt,fa[20][N],val[20][N],dep[N];
struct edge{int v,w,n;} e[N<<1];
struct D{int u,v,c;} dat[N];
struct qry{int id,x,c;} Q[N];
pair <int,int> ans[N];

int get(int x,int y)
{
	int ret=0;
	if(dep[x]<dep[y]) swap(x,y);
	int d=dep[x]-dep[y];
	rep(i,0,17) if(d&(1<<i)) ret=max(ret,val[i][x]),x=fa[i][x];
	repd(i,17,0) if(fa[i][x]!=fa[i][y]) ret=max(ret,max(val[i][x],val[i][y])),x=fa[i][x],y=fa[i][y];
	if(x!=y) ret=max(ret,max(val[0][x],val[0][y]));
	return ret;
}

struct ds
{
	int f,mx,l;

	int query(int x)
	{
		return max(mx,get(x,l));
	}
} t[N];

int getfa(int x)
{
	return t[x].f==x?x:t[x].f=getfa(t[x].f);
}

void merge(int x,int y)
{
	x=getfa(x),y=getfa(y),t[x].f=y;
	if(a[t[x].l]==a[t[y].l])
		t[y].mx=max(max(t[y].mx,t[x].mx),get(t[x].l,t[y].l));
	else if(a[t[x].l]>a[t[y].l])
		t[y].mx=t[x].mx,t[y].l=t[x].l;
}

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void addedge(int u,int v,int w)
{
	e[cnt]=(edge){v,w,h[u]},h[u]=cnt++;
	e[cnt]=(edge){u,w,h[v]},h[v]=cnt++;
}

void dfs(int x,int f)
{
	fa[0][x]=f,dep[x]=dep[f]+1;
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=f)
			val[0][e[i].v]=e[i].w,dfs(e[i].v,x);
}

bool cmp1(D a,D b)
{
	return a.c>b.c;
}

bool cmp2(qry a,qry b)
{
	return a.c>b.c;
}

void solve()
{
	sort(dat+1,dat+n,cmp1);
	rep(i,1,q) 
	{
		int v=getint(),x=getint();
		Q[i]=(qry){i,x,v};
	}
	rep(i,1,n) t[i].f=t[i].l=i;
	sort(Q+1,Q+1+q,cmp2);
	int p=1;
	rep(i,1,q)
	{
		while(p<=n-1 && dat[p].c>=Q[i].c) merge(dat[p].u,dat[p].v),++p;
		int x=Q[i].x,y=getfa(x);
		ans[Q[i].id]=make_pair(a[t[y].l],t[y].query(x));
	}
	rep(i,1,q) printf("%d %d\n",ans[i].first,ans[i].second);
}

int main()
{
	n=getint(),q=getint();
	rep(i,1,n) a[i]=getint();
	memset(h,-1,sizeof(h));
	rep(i,1,n-1)
	{
		dat[i].u=getint(),dat[i].v=getint(),dat[i].c=getint();
		addedge(dat[i].u,dat[i].v,getint());
	}
	dfs(1,0);
	rep(i,1,17) rep(j,1,n) fa[i][j]=fa[i-1][fa[i-1][j]],val[i][j]=max(val[i-1][j],val[i-1][fa[i-1][j]]);
	
	solve();
	return 0;
}