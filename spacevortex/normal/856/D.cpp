#include<bits/stdc++.h>
#define cmax(a,b) a=max(a,b)
#define lb(x) ((x)&(-(x)))
#define pb push_back
using namespace std;
typedef long long ll;
char gc()
{
	static char buf[1<<15],*p1,*p2;
	if(p1==p2) p2=(p1=buf)+fread(buf,1,1<<15,stdin);
	if(p1==p2) return EOF;
	else return *(p1++);
}
ll rd()
{
	ll rx=0,fx=1;char c=gc();
	while(c<48||c>57)
	{
		if(c=='-') fx=-1;
		c=gc();
	}
	while(c>=48&&c<=57)
	{
		rx=rx*10+c-48;
		c=gc();
	}
	return rx*fx;
}
const ll N=2e5+50,Log=20;
ll n,m,cur=0;
ll fa[N],det[N],dfn[N],low[N],vf[N][Log+3],dp[N],a[N],b[N],c[N];
vector<ll> e[N],vec[N];
struct Bit
{
	ll val[N];
	void add(ll x,ll w)
	{
		while(x<=n)
		{
			val[x]+=w;x+=lb(x);
		}
	}
	void add(ll x,ll y,ll w)
	{
		add(x,w);add(y+1,-w);
	}
	ll qry(ll x)
	{
		ll ret=0;
		while(x>0)
		{
			ret+=val[x];x-=lb(x);
		}
		return ret;
	}
}sbt;
void dfs(ll x)
{
	ll i;
	det[x]=det[fa[x]]+1;
	dfn[x]=++cur;
	vf[x][0]=fa[x];
	for(i=1;vf[x][i-1];i++) vf[x][i]=vf[vf[x][i-1]][i-1];
	for(ll v:e[x]) dfs(v);
	low[x]=cur;
}
ll LCA(ll x,ll y)
{
	ll i;
	if(det[x]<det[y]) swap(x,y);
	for(i=Log;i>=0;i--)
	{
		if(det[vf[x][i]]>=det[y]) x=vf[x][i];
	}
	if(x==y) return x;
	for(i=Log;i>=0;i--)
	{
		if(vf[x][i]!=vf[y][i]) x=vf[x][i],y=vf[y][i];
	}
	return fa[x];
}
void srh(ll x)
{
	ll sum=0;
	for(ll v:e[x]) srh(v);
	for(ll v:e[x])
	{
		sbt.add(dfn[x],low[x],dp[v]);
		sum+=dp[v];
	}
	dp[x]=sum;
	for(ll i:vec[x])
	{
		cmax(dp[x],c[i]+sbt.qry(dfn[a[i]])+sbt.qry(dfn[b[i]])-sum);
	}
	if(x!=1)
	{
		sbt.add(dfn[x],low[x],-dp[x]);
	}
}
int main()
{
	ll i,lca;
	n=rd();m=rd();
	for(i=2;i<=n;i++)
	{
		fa[i]=rd();
		e[fa[i]].pb(i);
	}
	dfs(1);
	for(i=1;i<=m;i++)
	{
		a[i]=rd();b[i]=rd();c[i]=rd();
		lca=LCA(a[i],b[i]);
		vec[lca].pb(i);
	}
	srh(1);
	cout<<dp[1];
	return 0;
}