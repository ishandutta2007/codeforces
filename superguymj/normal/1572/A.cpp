#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=200005;
bool vis[N],jdg;
int n,cnt,h[N];
struct edge{int v,n;} e[N];
struct data{int cnt,id;} f[N],ans;

bool operator < (data a,data b)
{
	return a.cnt==b.cnt?a.id<b.id:a.cnt<b.cnt;
}

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

data dfs(int x)
{
	if(vis[x]) jdg=0;
	if(!jdg || f[x].cnt) return f[x];
	vis[x]=1;
	for(int i=h[x]; i!=-1; i=e[i].n)
		f[x]=max(f[x],dfs(e[i].v));
	if(x<f[x].id) ++f[x].cnt;
	f[x].id=x,vis[x]=0;
	return f[x];
}

void solve()
{
	n=getint(),cnt=0,jdg=1;
	rep(i,1,n) h[i]=-1;
	rep(i,1,n)
	{
		f[i]=(data){0,n+1};
		int k=getint();
		rep(j,1,k) addedge(i,getint());
	}
	ans.cnt=0;
	rep(i,1,n) ans=max(ans,dfs(i));
	if(jdg) printf("%d\n",ans.cnt);
	else puts("-1");
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}