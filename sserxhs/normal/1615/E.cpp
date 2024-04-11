#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=2e5+2,M=8e5+2;
int s[M],l[M],r[M],lz[M];
vector<int> e[N];
int siz[N],f[N],v[N],dep[N],dfn[N],nfd[N];
int n,m,id,y,z;
ll ans;
bool ed[N];
void mdf(int x)
{
	//if (x==1) cout<<"["<<z<<","<<y<<"]"<<endl;
	if (z<=l[x]&&r[x]<=y)
	{
		lz[x]++;
		s[x]--;
		return;
	}
	int c=x<<1;
	if (lz[x])
	{
		lz[c]+=lz[x];
		s[c]-=lz[x];c|=1;
		lz[c]+=lz[x];
		s[c]-=lz[x];c^=1;
		lz[x]=0;
	}
	if (z<=r[c]) mdf(c);
	if (y>r[c]) mdf(c|1);
	s[x]=max(s[c],s[c|1]);
}
void build(int x)
{
	if (l[x]==r[x])
	{
		int p=nfd[l[x]];
		if (p!=1&&e[p].size()==1) s[x]=dep[p];
		return;
	}
	int c=x<<1;
	l[c]=l[x];r[c]=l[x]+r[x]>>1;
	l[c|1]=r[c]+1;r[c|1]=r[x];
	build(c);build(c|1);
	s[x]=max(s[c],s[c|1]);
}
int findmax()
{
	int x=1;
	while (l[x]<r[x])
	{
		int c=x<<1;
		if (lz[x])
		{
			lz[c]+=lz[x];
			s[c]-=lz[x];c|=1;
			lz[c]+=lz[x];
			s[c]-=lz[x];c^=1;
			lz[x]=0;
		}
		if (s[c]>s[c|1]) x=c; else x=c|1;
	}
	return x;
}
void dfs1(int u)
{
	siz[u]=1;dfn[u]=++id;nfd[id]=u;
	for (int v:e[u]) if (v!=f[u])
	{
		dep[v]=dep[u]+1;
		f[v]=u,dfs1(v);
		siz[u]+=siz[v];
	}
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int i;
	cin>>n>>m;ans=-1e18;
	for (i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs1(dep[1]=1);ed[0]=1;
	r[l[1]=1]=n;build(1);
	int res=n;
	int tm=m,cnt=0;
	while (m--&&s[1]>0)
	{
		int x=findmax();
		x=nfd[l[x]];
		while (!ed[x])
		{
			ed[x]=1;--res;
			z=dfn[x];y=dfn[x]+siz[x]-1;
			mdf(1);
			x=f[x];
		}
		++cnt;
	}
	res=min(res,n/2);tm=max(cnt,min(tm,n/2));
	ans=(ll)(n-res-tm)*(tm-res);
	cout<<ans<<endl;
}