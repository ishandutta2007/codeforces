#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid (l+r>>1)
#define pb push_back

using namespace std;
typedef long long LL;
const int N=2005;
bool vis[N*N],Vis[N*N];
int n,m,s,t,x,y,ans,head,tail,h[N*N],cnt;
char mp[N][N];
int dis[N*N],q[N*N],fa[N*N],id[N][N];
struct edge{int v,c,n;} e[N*N<<2];

void addedge(int u,int v)
{
	e[cnt]=(edge){v,0,h[u]},h[u]=cnt++;
	e[cnt]=(edge){u,1,h[v]},h[v]=cnt++;
}

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

LL getLL()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	LL x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

int getfa(int x)
{
	return fa[x]==x?x:fa[x]=getfa(fa[x]);
}

void merge(int x,int y)
{
	x=getfa(x),y=getfa(y);
	if(x!=y) fa[x]=y;
}

void ins1(int x,int d)
{
	q[++tail]=x,vis[x]=1,dis[x]=d;
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(!e[i].c && !vis[e[i].v]) ins1(e[i].v,d);
}

void dij1()
{
	ins1(getfa(id[s][t]),0);
	while(head<=tail)
	{
		int u=q[head++];
		for(int i=h[u]; i!=-1; i=e[i].n)
			if(e[i].c && dis[u]+1<=::x && !vis[e[i].v]) ins1(e[i].v,dis[u]+1);
	}
	rep(i,1,n*m) Vis[i]&=vis[i];
}

void ins2(int x,int d)
{
	q[++tail]=x,vis[x]=1,dis[x]=d;
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].c && !vis[e[i].v]) ins2(e[i].v,d);
}

void dij2()
{
	memset(vis,0,sizeof(vis));
	ins2(getfa(id[s][t]),0);
	while(head<=tail)
	{
		int u=q[head++];
		for(int i=h[u]; i!=-1; i=e[i].n)
			if(!e[i].c && dis[u]+1<=::y && !vis[e[i].v]) ins2(e[i].v,dis[u]+1);
	}
	rep(i,1,n*m) Vis[i]&=vis[i];
}

int main()
{
	n=getint(),m=getint();
	s=getint(),t=getint();
	x=getint(),y=getint();
	memset(h,-1,sizeof(h));
	rep(i,1,n) scanf("%s",mp[i]+1);
	rep(i,1,n*m) fa[i]=i,Vis[i]=1;
	rep(i,1,n) rep(j,1,m) id[i][j]=(i-1)*m+j;
	rep(i,1,n-1) rep(j,1,m) if(mp[i][j]=='.' && mp[i+1][j]=='.') merge(id[i][j],id[i+1][j]);
	rep(i,1,n) rep(j,1,m-1) if(mp[i][j]=='.' && mp[i][j+1]=='.') addedge(getfa(id[i][j]),getfa(id[i][j+1]));
	dij1(),dij2();
	rep(i,1,n*m) ans+=Vis[getfa(i)];
	printf("%d\n",ans);
	return 0;
}