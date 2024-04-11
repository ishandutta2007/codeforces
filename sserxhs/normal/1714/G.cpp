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
const ll inf=1e18;
struct Q
{
	int v,w1,w2;
};
vector<Q> e[N];
int f[20][N],dis[N];
ll dep1[N],dep2[N];
void dfs(int u)
{
	for (int i=1;f[i-1][u];i++) f[i][u]=f[i-1][f[i-1][u]];
	for (auto [v,w1,w2]:e[u])
	{
		dep1[v]=dep1[u]+w1;
		dep2[v]=dep2[u]+w2;
		dis[v]=dis[u]+1;
		dfs(v);
	}
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T;cin>>T;
	dep1[0]=dep2[0]=-inf;
	while (T--)
	{
		int n,m,i,j;
		cin>>n;
		for (i=1;i<=n;i++)
		{
			e[i].clear();
			for (j=0;j<=19;j++) f[j][i]=0;
		}
		for (i=2;i<=n;i++)
		{	
			int u,v,w;
			cin>>u>>v>>w;
			f[0][i]=u;
			e[u].push_back({i,v,w});
		}
		dfs(1);
		for (i=2;i<=n;i++)
		{
			ll tot=dep1[i];
			int u=i;
			for (j=19;j>=0;j--) if (dep2[f[j][u]]>tot) u=f[j][u];
			// u=f[j][u];
			// dbg(u,dis[u],dep2[u],tot);
			cout<<dis[u]-(dep2[u]>tot)<<" \n"[i==n];
		}
	}
}