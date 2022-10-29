#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=200005;
bool vis[N];
int n,a[N],siz[N],m,cnt,h[N],ans[N];
struct edge{int v,n;} e[N<<1];

void addedge(int u,int v)
{
	e[cnt]=(edge){v,h[u]},h[u]=cnt++;
	e[cnt]=(edge){u,h[v]},h[v]=cnt++;
}

void dfs(int x)
{
	vis[x]=1,siz[x]=a[x];
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(!vis[e[i].v])
		{
			dfs(e[i].v),siz[x]+=siz[e[i].v];
			int tp=(i&1)?-1:1;
			ans[(i>>1)+1]=tp*siz[e[i].v];
		}
}

int main()
{
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	scanf("%d",&m);
	memset(h,-1,sizeof(h));
	rep(i,1,m)
	{
		int u,v;
		scanf("%d%d",&u,&v),addedge(u,v);
	}
	rep(i,1,n) if(!vis[i])
	{
		dfs(i);
		if(siz[i]) return puts("Impossible"),0;
	}
	puts("Possible");
	rep(i,1,m) printf("%d\n",ans[i]);
	return 0;
}