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
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
struct union_set
{
	vector<int> f;
	int n;
	union_set() {}
	union_set(int nn):n(nn),f(nn+1)
	{
		iota(all(f),0);
	}
	int getf(int u) { return f[u]==u?u:f[u]=getf(f[u]); }
	void merge(int u,int v)
	{
		u=getf(u); v=getf(v);
		f[u]=v;
	}
	bool connected(int u,int v) { return getf(u)==getf(v); }
};
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T; cin>>T;
	while (T--)
	{
		int n,m,i,j;
		cin>>n>>m;
		vector<tuple<int,int,int>> eg(m);
		i=0;
		for (auto &[u,v,w]:eg) cin>>u>>v,w=i++;
		string ans(m,'0');
		while (1)
		{
			union_set s(n);
			shuffle(all(eg),rnd);
			vector<tuple<int,int,int>> res;
			vector<int> tmp;
			for (auto [u,v,w]:eg) if (s.connected(u,v))
			{
				res.push_back({u,v,w});
				tmp.push_back(u);
				tmp.push_back(v);
			}
			else s.merge(u,v);
			sort(all(tmp));
			if (unique(all(tmp))-tmp.begin()==3) continue;
			for (auto [u,v,w]:res) ans[w]='1';
			break;
		}
		cout<<ans<<'\n';
	}
}