//114514min
//ACM 
#include "bits/stdc++.h"
using namespace std;
template<typename typC,typename typD> istream & operator>>(istream &cin,pair<typC,typD> &a) {return cin>>a.first>>a.second;}
template<typename typC> istream & operator>>(istream &cin,vector<typC> &a){for (auto &x:a) cin>>x;return cin;}
template<typename typC,typename typD> ostream & operator<<(ostream &cout,const pair<typC,typD> &a) {return cout<<a.first<<' '<<a.second;}
template<typename typC,typename typD> ostream & operator<<(ostream &cout,const vector<pair<typC,typD>> &a){for (auto &x:a) cout<<x<<'\n';return cout;}
template<typename typC> ostream & operator<<(ostream &cout,const vector<typC> &a){int n=a.size();if (!n) return cout;cout<<a[0];for (int i=1;i<n;i++) cout<<' '<<a[i];return cout;}
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=1e5+5,M=2e5+5;
struct union_set
{
	vector<int> f;
	int n;
	union_set(){}
	union_set(int nn):n(nn),f(nn+1)
	{
		iota(all(f),0);
	}
	int getf(int u) {return f[u]==u?u:f[u]=getf(f[u]);}
	void merge(int u,int v)
	{
		u=getf(u);v=getf(v);
		f[u]=v;
	}
	bool connected(int u,int v) {return getf(u)==getf(v);}
};
vector<int> e[N];
int dfn[N],siz[N],f[18][N],a[N],dep[N];
void dfs(int u)
{
	static int id=0;
	dfn[u]=++id;
	siz[u]=1;
	for (int i=1;f[i-1][u];i++) f[i][u]=f[i-1][f[i-1][u]];
	for (int v:e[u]) if (v!=f[0][u]) f[0][v]=u,dep[v]=dep[u]+1,dfs(v),siz[u]+=siz[v];
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int n,m,i;
	cin>>n>>m;
	vector<pair<int,int>> edges;
	union_set s(n);
	while (m--)
	{
		int u,v;
		cin>>u>>v;
		if (s.connected(u,v)) edges.push_back({u,v});
		else e[u].push_back(v),e[v].push_back(u),s.merge(u,v);
	}
	dfs(dep[1]=1);
	for (auto [u,v]:edges)
	{
		if (dfn[u]>dfn[v]) swap(u,v);
		if (dfn[u]+siz[u]>dfn[v])
		{
			++a[1];
			++a[dfn[v]];
			--a[dfn[v]+siz[v]];
			for (int i=17;i>=0;i--) if (dep[f[i][v]]>dep[u]) v=f[i][v];
			--a[dfn[v]];
			++a[dfn[v]+siz[v]];
		}
		else ++a[dfn[u]],--a[dfn[u]+siz[u]],++a[dfn[v]],--a[dfn[v]+siz[v]];
	}
	for (i=1;i<=n;i++) a[i]+=a[i-1];
	string ans(n,'0');
	for (i=1;i<=n;i++) ans[i-1]+=a[dfn[i]]==edges.size();
	cout<<ans<<endl;
}