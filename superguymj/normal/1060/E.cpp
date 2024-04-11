#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=200005;
int n,h[N],cnt,fa[N],p[N];
typedef long long LL;
LL f[N][2],g[N][2],siz[N],L[N][2],R[N][2];
LL ans,ans2;
struct edge{int v,n;} e[N<<1];

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

void addedge(int u,int v)
{
	e[cnt]=(edge){v,h[u]},h[u]=cnt++;
	e[cnt]=(edge){u,h[v]},h[v]=cnt++;
}

void dfs(int x,int f)
{
	fa[x]=f,siz[x]=1;
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=f)
		{
			dfs(e[i].v,x),siz[x]+=siz[e[i].v];
			ans+=(LL)siz[e[i].v]*(n-siz[e[i].v]);
		}
}

void dp1(int x)
{
	f[x][0]=1;
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=fa[x])
		{
			dp1(e[i].v);
			f[x][0]+=f[e[i].v][1];
			f[x][1]+=f[e[i].v][0];
		}
}

int main()
{
	n=getint();
	memset(h,-1,sizeof(h));
	rep(i,1,n-1) addedge(getint(),getint());
	dfs(1,0);
	dp1(1);
	
	ans2=f[1][1]*f[1][0];
	printf("%lld\n",(ans+(ans2))>>1);
	return 0;
}