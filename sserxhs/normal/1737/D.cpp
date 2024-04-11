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
#define all(x) (x).begin(),(x).end()
// void inc(ui &x,const ui &y) { if ((x+=y)>=p) x-=p; }
// void dec(ui &x,const ui &y) { if ((x+=p-y)>=p) x-=p; }
const int N=1e6+5;
const ll inf=1e18;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T; cin>>T;
	while (T--)
	{
		int n,m,i,j,k;
		cin>>n>>m;
		vector e(n,vector(n,inf));
		vector<tuple<int,int,int>> eg(m);
		for (i=0; i<n; i++) e[i][i]=0;
		for (auto &[u,v,w]:eg)
		{
			cin>>u>>v>>w; --u; --v;
			e[u][v]=e[v][u]=1;
		}
		for (k=0; k<n; k++) for (i=0; i<n; i++) for (j=0; j<n; j++) cmin(e[i][j],e[i][k]+e[k][j]);
		ll res=inf;
		for (auto &[u,v,w]:eg) for (k=0; k<n; k++) cmin(res,(ll)w*(e[0][k]+e[k][n-1]+min(e[k][u],e[k][v])+2));
		for (auto [u,v,w]:eg) res=min({res,(e[0][u]+e[n-1][v]+1ll)*w,(e[n-1][u]+e[0][v]+1ll)*w});
		cout<<res<<'\n';
	}
}