#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
const int N=200005,mod=1000000007;
int n,cnt,h[N],a[N];
LL sum,ans,f[N][2],g[N][2];
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

void dfs(int x,int fa)
{
	f[x][1]=a[x],g[x][1]=1;
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=fa)
		{
			dfs(e[i].v,x);
			ans=(ans+f[x][1]*g[e[i].v][0]-f[e[i].v][0]*g[x][1])%mod;
			ans=(ans-f[x][0]*g[e[i].v][1]+f[e[i].v][1]*g[x][0])%mod;
			g[x][0]=(g[x][0]+g[e[i].v][1])%mod,g[x][1]=(g[x][1]+g[e[i].v][0])%mod;
			f[x][0]=(f[x][0]-f[e[i].v][1]+a[x]*g[e[i].v][1])%mod,f[x][1]=(f[x][1]-f[e[i].v][0]+a[x]*g[e[i].v][0])%mod;
		}
}

int main()
{
	n=getint(),memset(h,-1,sizeof(h));
	rep(i,1,n) a[i]=getint(),sum=(sum+a[i])%mod;
	rep(i,1,n-1) addedge(getint(),getint());
	dfs(1,0),ans=(ans*2+sum)%mod;
	printf("%I64d\n",(ans+mod)%mod);
	return 0;
}