#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=200005;
bool vis[N];
int n,h[N],cnt,stk[N],d[N],fa[N],root;
struct edge{int v,n;} e[N];

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
}

void del(int x)
{
	vis[x]=1,stk[++*stk]=x,--d[fa[x]];
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(!vis[e[i].v])
		{
			--d[e[i].v];
			if(!(d[e[i].v]&1)) del(e[i].v);
		}
}

void dfs(int x)
{
	for(int i=h[x]; i!=-1; i=e[i].n)
		dfs(e[i].v);
	if(!(d[x]&1)) del(x);
}

int main()
{
	n=getint(),memset(h,-1,sizeof(h));
	rep(i,1,n) if(!(fa[i]=getint())) root=i; else ++d[i],++d[fa[i]];
	rep(i,1,n) if(fa[i]) addedge(fa[i],i);
	dfs(root);
	if(*stk==n)
	{
		puts("YES");
		rep(i,1,n) printf("%d\n",stk[i]);
	}
	else puts("NO");
	return 0;
}