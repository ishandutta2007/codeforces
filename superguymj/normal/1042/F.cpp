#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=1000005;
int n,k,cnt,h[N],g[N],ans,tot,p[N],d[N];
struct edge{int v,n;} e[N<<1];

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
	if(d[x]==1) return;
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=fa) dfs(e[i].v,x);
	tot=0;
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=fa)
			p[++tot]=g[e[i].v]+1;
	sort(p+1,p+1+tot);
	int lst=tot;
	while(lst>1)
	{
		if(p[lst]+p[lst-1]<=k) break;
		++ans,--lst;
	}
	g[x]=p[lst];
}

int main()
{
	n=getint(),k=getint();
	memset(h,-1,sizeof(h));
	rep(i,1,n-1) addedge(getint(),getint());
	rep(i,1,n) if(d[i]>1) {dfs(i,0); break;}
	printf("%d\n",ans+1);
	return 0;
}