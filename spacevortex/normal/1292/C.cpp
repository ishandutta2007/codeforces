#include<bits/stdc++.h>
#define cmax(a,b) a=max(a,b)
#define pb push_back
using namespace std;
typedef long long ll;
const ll N=3050;
ll n,m=0,rt,cur,ans=0;
ll fa[N],siz[N],dis[N][N],dp[N][N],bel[N][N],dfn[N],low[N];
vector<ll> e[N];
bool vis[N][N];
void dfs(ll x,ll nf)
{
	fa[x]=nf;dfn[x]=++cur;
	siz[x]=1;
	for(ll v:e[x])
	{
		if(v==nf) continue;
		if(x==rt) bel[rt][v]=v;
		else bel[rt][v]=bel[rt][x];
		dis[rt][v]=dis[rt][x]+1;
		dfs(v,x);
		siz[x]+=siz[v];
	}
	low[x]=cur;
}
struct Node{ll x,y,w;}p[N*N/2ll];
bool cmp(const Node &a,const Node &b)
{
	return a.w<b.w;
}
int main()
{
	ios::sync_with_stdio(false);
	ll i,j,x,y,u,v;
	cin>>n;
	for(i=1;i<n;i++)
	{
		cin>>u>>v;
		e[u].pb(v);e[v].pb(u);
	}
	for(i=n;i>=1;i--)
	{
		rt=i;cur=0;
		dfs(i,0);
	}
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			p[++m]=(Node){i,j,dis[i][j]};
		}
	}
	sort(p+1,p+m+1,cmp);
	//printf("U%lld %lld %lld\n",siz[1],siz[2],siz[3]);
	for(i=1;i<=m;i++)
	{
		x=p[i].x;y=p[i].y;
		if(dfn[x]<=dfn[y]&&low[y]<=low[x]) dp[x][y]+=siz[y]*(n-siz[bel[x][y]]);
		else if(dfn[y]<=dfn[x]&&low[x]<=low[y]) dp[x][y]+=siz[x]*(n-siz[bel[y][x]]);
		else dp[x][y]+=siz[x]*siz[y];
		cmax(ans,dp[x][y]);
		for(ll a:e[x])
		{
			if(dis[a][y]<dis[x][y]) continue;
			if(a<y) cmax(dp[a][y],dp[x][y]);
			else cmax(dp[y][a],dp[x][y]);
		}
		for(ll b:e[y])
		{
			if(dis[x][b]<dis[x][y]) continue;
			if(x<b) cmax(dp[x][b],dp[x][y]);
			else cmax(dp[b][x],dp[x][y]);
		}
	}
	cout<<ans;
	return 0;
}