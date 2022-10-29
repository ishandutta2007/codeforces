#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#include<map>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define pb push_back
 
using namespace std;
const int N=200005;
int n,cnt,h[N],f[N],ans;
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
	e[cnt]=(edge){v,h[u]},h[u]=cnt++;
	e[cnt]=(edge){u,h[v]},h[v]=cnt++;
}
 
void dfs(int x,int fa)
{
	f[x]=1;
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=fa)
		{
			dfs(e[i].v,x);
			if(f[e[i].v]) f[x]=0;
		}
	ans+=f[x];
	if(!f[x] && x!=1) --ans;
}
 
void solve()
{
	n=getint(),ans=cnt=0;
	rep(i,1,n) h[i]=-1;
	rep(i,1,n-1) addedge(getint(),getint());
	dfs(1,0);
	printf("%d\n",ans);
}
 
int main()
{	
	int T=getint();
	while(T--) solve();
	return 0;
}