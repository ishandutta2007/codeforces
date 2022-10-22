#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
const int N=100005;
int n,cnt,h[N],ans[N],d[N];

struct edge{int v,n;} e[N<<1];

void addedge(int u,int v)
{
	e[cnt]=(edge){v,h[u]},h[u]=cnt++,++d[u];
	e[cnt]=(edge){u,h[v]},h[v]=cnt++,++d[v];
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

void dfs(int x,int fa,int C)
{
	ans[x]=d[x]*C;
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=fa)
			dfs(e[i].v,x,-C);
}

void solve()
{
	n=getint(),cnt=0;
	rep(i,1,n) h[i]=-1,d[i]=0;
	rep(i,1,n-1) addedge(getint(),getint());
	dfs(1,0,1);
	rep(i,1,n) printf("%d ",ans[i]);
	puts("");
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}