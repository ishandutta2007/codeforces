#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=500005,mod=998244353,inv2=(mod+1)/2;
typedef long long LL;
int n,h[N],cnt;
LL f[N],ans;
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
			f[x]=(1-inv2*(1-f[e[i].v]))%mod*f[x]%mod;
		}
	f[x]=(1-f[x]+mod)%mod;
}

int main()
{
	n=getint();
	memset(h,-1,sizeof(h));
	rep(i,1,n-1) addedge(getint(),getint());
	dfs(1,0);
	rep(i,1,n) ans=(ans+f[i])%mod;
	LL pw=1;
	rep(i,1,n) pw=pw*2%mod;
	printf("%lld\n",ans*pw%mod);
	return 0;
}