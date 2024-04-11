//114514min
//ACM 
#include "bits/stdc++.h"
using namespace std;
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
template<typename typC> bool cmin(typC &x,const typC &y) { if (x>y) { x=y; return 1; } return 0; }
template<typename typC> bool cmax(typC &x,const typC &y) { if (x<y) { x=y; return 1; } return 0; }
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
typedef __int128 lll;
#define all(x) (x).begin(),(x).end()
// void inc(ui &x,const ui &y) { if ((x+=y)>=p) x-=p; }
// void dec(ui &x,const ui &y) { if ((x+=p-y)>=p) x-=p; }
const int N=1e5+5;
const ll inf=1e18;
typedef pair<ll,int> pa;
struct Q
{
	int v;
	ll w;
};
vector<Q> e[N];
ll f[21][N],y[N];
int n;
void dijkstra(ll *dis)
{
	int i;
	priority_queue<pa,vector<pa>,greater<pa>> q;
	static bool ed[N];
	for (i=2; i<=n; i++)
	{
		ed[i]=0;
		e[1].push_back({i,dis[i]});
		dis[i]=inf;
	}
	q.push({0,1});
	while (q.size())
	{
		int u=q.top().second; q.pop();
		for (auto [v,w]:e[u]) if (dis[v]>dis[u]+w) q.push({dis[v]=dis[u]+w,v});
		while (q.size()&&ed[q.top().second]) q.pop();
	}
	for (i=2; i<=n; i++) e[1].pop_back();
}
void dfs(int l,int r,int L,int R,int j)
{
	if (l>r) return;
	int m=l+r>>1,i,x=L;
	f[j+1][m]=inf;
	for (i=L; i<=R; i++) if (cmin(f[j+1][m],f[j][i]+(ll)(i-m)*(i-m))) x=i;
	dfs(l,m-1,L,x,j); dfs(m+1,r,x,R,j);
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int m,q,i,j;
	cin>>n>>m>>q;
	while (m--)
	{
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	fill_n(f[0]+1,n,inf);
	f[0][1]=0;
	for (j=0; j<=q; j++)
	{
		dijkstra(f[j]);
		if (j==q) break;
		dfs(1,n,1,n,j);
	}
	for (i=1; i<=n; i++) cout<<f[q][i]<<" \n"[i==n];
}