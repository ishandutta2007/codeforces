#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+2,M=4e5+2;
template<typename typC,int N> struct bit
{
	typC a[N],s[N];
	int n;
	bit()
	{
		memset(s,0,sizeof s);
		memset(a,0,sizeof a);
	}
	void init(int nn)
	{
		n=nn;
		memset(a+1,0,n*sizeof a[0]);
		memset(s+1,0,n*sizeof a[0]);
	}
	void init(int nn,int *b)
	{
		n=nn;
		for (int i=1;i<=n;i++) s[i]=s[i-1]+b[i];
		memset(a+1,0,n*sizeof a[0]);
	}
	void mdf(int x,typC y)
	{
		a[x]+=y;
		while ((x+=x&-x)<=n) a[x]+=y; 
	}
	typC sum(int x)
	{
		typC r=a[x];
		while (x^=x&-x) r+=a[x];
		return r;
	}
	typC sum(int x,int y)
	{
		return sum(y)-sum(x-1);
	}
};
bit<ll,N> s;
ll ans;
vector<int> lj[N];
int dfn[N],siz[N],low[N],hc[N],top[N],f[N],a[N],b[N],dep[N];
int n,m,q,i,j,x,y,z;
int lca(int x,int y)
{
	while (top[x]^top[y]) if (dep[top[x]]<dep[top[y]]) y=f[top[y]]; else x=f[top[x]];
	return dep[x]<dep[y]?x:y;
}
void dfs1(int u)
{
	siz[u]=1;
	for (auto v:lj[u]) if (v!=f[u])
	{
		dep[v]=dep[f[v]=u]+1;
		dfs1(v);
		siz[u]+=siz[v];
		if (siz[hc[u]]<siz[v]) hc[u]=v;
	}
}
void dfs2(int u)
{
	dfn[u]=++m;low[u]=dfn[u]+siz[u]-1;
	if (hc[u])
	{
		top[hc[u]]=top[u];
		dfs2(hc[u]);
		for (auto v:lj[u]) if (v!=f[u]&&v!=hc[u]) dfs2(top[v]=v);
	}
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q;
	for (i=1;i<=n;i++) cin>>a[i],a[i]=abs(a[i]);
	for (i=1;i<n;i++)
	{
		cin>>x>>y;
		lj[x].push_back(y);
		lj[y].push_back(x);
	}
	dfs1(dep[1]=1);dfs2(top[1]=1);
	s.init(n);
	for (i=1;i<=n;i++) s.mdf(dfn[i],a[i]),s.mdf(low[i]+1,-a[i]);
	while (q--)
	{
		cin>>x>>y>>z;
		if (x==1)
		{
			z=abs(z);
			s.mdf(dfn[y],z-a[y]);
			s.mdf(low[y]+1,a[y]-z);
			a[y]=z;
		}
		else
		{
			x=lca(y,z);
			ans=s.sum(dfn[y])+s.sum(dfn[z])-s.sum(dfn[x])*2+a[x];
			ans=ans*2-(a[y]+a[z]);
			cout<<ans<<'\n';
		}
	}
}