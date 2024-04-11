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
const int N=1e6+5;
int dfn[N],siz[N],low[N];
int id;
namespace HLD
{
	const int N=5e5+2;
	vector<int> e[N];
	int dfn[N],dep[N],f[N],siz[N],hc[N],top[N];
	int id;
	void dfs1(int u)
	{
		siz[u]=1;
		for (int v:e[u]) if (v!=f[u])
		{
			dep[v]=dep[f[v]=u]+1;
			dfs1(v);
			siz[u]+=siz[v];
			if (siz[v]>siz[hc[u]]) hc[u]=v;
		}
	}
	void dfs2(int u)
	{
		dfn[u]=++id;
		if (hc[u])
		{
			top[hc[u]]=top[u];
			dfs2(hc[u]);
			for (int v:e[u]) if (v!=hc[u]&&v!=f[u]) dfs2(top[v]=v);
		}
	}
	int lca(int u,int v)
	{
		while (top[u]!=top[v])
		{
			if (dep[top[u]]<dep[top[v]]) swap(u,v);
			u=f[top[u]];
		}
		if (dep[u]>dep[v]) swap(u,v);
		return u;
	}
	int dis(int u,int v)
	{
		return dep[u]+dep[v]-(dep[lca(u,v)]<<1);
	}
	void init(int n)
	{
		for (int i=1;i<=n;i++)
		{
			e[i].clear();
			f[i]=hc[i]=0;
		}
		id=0;
	}
	void fun(int root)
	{
		dep[root]=1;dfs1(root);dfs2(top[root]=root);
	}
	vector<pair<int,int>> get_path(int u,int v)//u->v [r>l]
	{
		//cerr<<"path from "<<u<<" to "<<v<<": ";
		vector<pair<int,int>> v1,v2;
		while (top[u]!=top[v])
		{
			if (dep[top[u]]>dep[top[v]]) v1.push_back({dfn[u],dfn[top[u]]}),u=f[top[u]];
			else v2.push_back({dfn[top[v]],dfn[v]}),v=f[top[v]];
		}
		v1.reserve(v1.size()+v2.size()+1);
		v1.push_back({dfn[u],dfn[v]});
		reverse(v2.begin(),v2.end());
		for (auto v:v2) v1.push_back(v);
		//for (auto [x,y]:v1) cerr<<"["<<x<<','<<y<<"] ";cerr<<endl;
		return v1;
	}
}
using HLD::e,HLD::lca;
using HLD::fun;//5e5
void dfs(int u)
{
	dfn[u]=++id;siz[u]=1;
	for (int v:e[u]) if (!dfn[v]) dfs(v),siz[u]+=siz[v];
	low[u]=dfn[u]+siz[u];
}
bool intree(int u,int v)
{
	return dfn[u]<=dfn[v]&&dfn[v]<low[u];
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T=1;
	while (T--)
	{
		int n,m,i,j;
		cin>>n;id=0;
		HLD::init(n);
		for (i=1;i<=n;i++)
		{
			e[i].clear();
			dfn[i]=0;
		}
		for (i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		fun(1);
		cin>>m;
		dfs(1);
		while (m--)
		{
			int q;
			cin>>q;
			vector<int> a(q);
			cin>>a;
			sort(all(a),[&](int x,int y){return dfn[x]<dfn[y];});
			if (!intree(a[0],a.back())) a.insert(a.begin(),lca(a[0],a.back())),++q;
			int x=a[0];
			// dbg(1);
			for (i=1;i<q;i++) if (!intree(a[i-1],a[i])) break;
			if (i==q) {cout<<"YES\n";continue;}
			vector<int> r(1,1);
			for (i=2;i<q;i++) if (!intree(a[1],a[i])) {r.push_back(i);break;}
			if (r.size()!=2||lca(a[r[0]],a[r[1]])!=a[0]) {cout<<"NO\n";continue;}
			int u=a[r[0]],v=a[r[1]];
			dbg(u,v);
			for (i=2;i<q;i++) if (i!=r[1])
			{
				if (intree(u,a[i])) u=a[i]; else if (intree(v,a[i])) v=a[i]; else break;
			}
			if (i==q) cout<<"YES\n"; else cout<<"NO\n";
		}
	}
}