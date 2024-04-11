#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=300005;
int n,m,cnt,h[N],f[N],mx[N],siz[N],ans[N];
struct edge{int v,n;} e[N];

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
}

void dfs_1(int x)
{
	siz[x]=1;
	for(int i=h[x]; i!=-1; i=e[i].n)
		dfs_1(e[i].v),siz[x]+=siz[e[i].v],mx[x]=max(mx[x],siz[e[i].v]);
}

void dfs_2(int x)
{
	ans[x]=x;
	for(int i=h[x]; i!=-1; i=e[i].n)
	{
		dfs_2(e[i].v);
		int y=ans[e[i].v];
		while(x!=y)
		{
			if(max(siz[x]-siz[y],mx[y])<=siz[x]/2)
			{
				ans[x]=y;
				break;
			}
			y=f[y];
		}
	}
}

int main()
{
	n=getint(),m=getint(),memset(h,-1,sizeof(h));
	rep(i,2,n) f[i]=getint(),addedge(f[i],i);
	dfs_1(1);
	dfs_2(1);
	while(m--) printf("%d\n",ans[getint()]);
	return 0;
}