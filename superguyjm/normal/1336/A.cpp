#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid (l+r>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)

using namespace std;
const int N=200005;
struct edge{int v,n;} e[N<<1];
int n,k,cnt,p[N],h[N],dep[N],siz[N];
typedef long long LL;
LL ans;

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
	e[cnt]=(edge){u,h[v]},h[v]=cnt++;
}

void dfs(int x,int fa,int d)
{
	dep[x]=d,siz[x]=1;
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=fa) dfs(e[i].v,x,d+1),siz[x]+=siz[e[i].v];
}

bool cmp(int x,int y)
{
	int X=dep[x]-siz[x]+1,Y=dep[y]-siz[y]+1;
	return X>Y;
}

void add(int x)
{
	ans+=dep[x]-siz[x]+1;
}

int main()
{
	n=getint(),k=getint();
	memset(h,-1,sizeof(h));
	rep(i,1,n-1) addedge(getint(),getint());
	dfs(1,0,0);
	rep(i,1,n) p[i]=i;
	sort(p+1,p+1+n,cmp);
	rep(i,1,k) add(p[i]);
	printf("%lld\n",ans);
	return 0;
}