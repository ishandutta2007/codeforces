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
const int N=1e5+5;
struct Q
{
	int v,w;
	bool operator<(const Q &o) const { return v<o.v; }
};
vector<Q> e[N];
int a[N],ban[N];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int n,q,i;
	cin>>n>>q;
	while (q--)
	{
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
		ban[u]|=~w&(1<<30)-1;
		ban[v]|=~w&(1<<30)-1;
	}
	for (i=1; i<=n; i++)
	{
		sort(all(e[i]));
		for (auto [v,w]:e[i]) if (v<=i) a[i]|=w&~a[v];
		else a[i]|=w&ban[v];
		cout<<a[i]<<" \n"[i==n];
	}
}