#include<algorithm>
#include<iostream>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<string>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define pb push_back
#define mp make_pair

using namespace std;
const int N=100005;
int n,h[N],cnt,F[N],siz[N],mx[N],d[N];
struct edge{int v,n;} e[N<<1];
vector <int> vt[N];
int rt;

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
	e[cnt]=(edge){v,h[u]},h[u]=cnt++,++d[u];
	e[cnt]=(edge){u,h[v]},h[v]=cnt++,++d[v];
}

void dfs(int x,int fa)
{
	siz[x]=1;
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=fa)
		{
			dfs(e[i].v,x);
			siz[x]+=siz[e[i].v];
			mx[x]=max(mx[x],siz[e[i].v]);
		}
	mx[x]=max(mx[x],n-siz[x]);
}

void solve(int x,int fa,int d=1)
{
	vt[d].pb(x),F[x]=fa;
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=fa)
			solve(e[i].v,x,d+1);
}

int find(int x)
{
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=F[x]) return find(e[i].v);
	return x;
}

int check()
{
	bool ok=1;
	rep(i,1,n)
	{
		int sz=vt[i].size();
		if(!sz) break;
		rep(j,1,sz-1) if(d[vt[i][j]]!=d[vt[i][0]]) ok=0;
	}
	if(ok) return -1;
	repd(i,n,1)
	{
		int sz=vt[i].size();
		if(sz)
		{
			if(sz==1) return vt[i][0];
			break;
		}
	}
	int ret;
	rep(i,1,n)
	{
		ok=1;
		int sz=vt[i].size();
		if(!sz) break;
		rep(j,1,sz-1) if(d[vt[i][j]]!=d[vt[i][0]]) ok=0;
		if(!ok)
		{
			int cnt=0;
			rep(j,1,sz-1) if(d[vt[i][j]]==d[vt[i][0]]) ++cnt;
			if(cnt==0 && (sz!=2 || d[vt[i][0]]==1)) ret=vt[i][0];
			else rep(j,1,sz-1) if(d[vt[i][j]]!=d[vt[i][0]]) ret=vt[i][j];
		}
	}
	if(d[ret]==1)
		return ret;
	return find(ret);
}

int main()
{
	n=getint();
	memset(h,-1,sizeof(h));
	rep(i,1,n-1) addedge(getint(),getint());
	dfs(1,0);
	rep(i,1,n) if(mx[i]<=n/2) rt=i;
	rep(i,1,n) vt[i].clear();
	solve(rt,0);
	int jdg=check();
	if(jdg==-1) return printf("%d\n",rt),0;
	rt=jdg;
	rep(i,1,n) vt[i].clear();
	solve(rt,0);
	jdg=check();
	if(jdg==-1) return printf("%d\n",rt),0;
	puts("-1");
	return 0;
}