#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#include<vector>
#include<cmath>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define pb push_back

using namespace std;
const int N=200005,Lim=200000;
typedef long long LL;
bool vis[N];
int n,cnt,fa[N],h[N],prm[N],mu[N],a[N];
LL ans[N],c[N];
vector <int> p[N];
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

void dfs(int x,int Fa)
{
	fa[x]=Fa;
	int lim=sqrt(a[x]);
	rep(i,1,lim)
		if(a[x]%i==0)
		{
			p[i].pb(x);
			if(i*i!=a[x]) p[a[x]/i].pb(x);
		}
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=Fa)
			dfs(e[i].v,x);
}

void prepare()
{
	mu[1]=1;
	rep(i,2,Lim)
	{
		if(!vis[i]) mu[i]=-1,prm[++*prm]=i;
		rep(j,1,*prm)
		{
			if(i*prm[j]>Lim) break;
			vis[i*prm[j]]=1;
			if(i%prm[j]) mu[i*prm[j]]=-mu[i];
			else break;
		}
	}
}

void solve(int x)
{
	int siz=ans[x]=(int)p[x].size();
	rep(i,0,siz-1) c[p[x][i]]=1,vis[p[x][i]]=1;
	repd(i,siz-1,0)
	{
		if(vis[fa[p[x][i]]]) ans[x]+=c[p[x][i]]*c[fa[p[x][i]]];
		c[fa[p[x][i]]]+=c[p[x][i]];
	}
	rep(i,0,siz-1) c[p[x][i]]=c[fa[p[x][i]]]=0,vis[p[x][i]]=0;
}

int main()
{
	n=getint(),memset(h,-1,sizeof(h));
	rep(i,1,n) a[i]=getint();
	rep(i,1,n-1) addedge(getint(),getint());
	prepare(),dfs(1,0);
	memset(vis,0,sizeof(vis));
	rep(i,1,Lim) solve(i);
	rep(i,1,Lim)
	{
		LL nw=0;
		for(int j=i; j<=Lim; j+=i)
			nw+=mu[j/i]*ans[j];
		if(nw) printf("%d %lld\n",i,nw);
	}
	return 0;
}