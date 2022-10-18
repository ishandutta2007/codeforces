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
typedef pair<int,int> pa;
#define all(x) (x).begin(),(x).end()
// void inc(ui &x,const ui &y) { if ((x+=y)>=p) x-=p; }
// void dec(ui &x,const ui &y) { if ((x+=p-y)>=p) x-=p; }
const int N=1e6+5;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T; cin>>T;
	while (T--)
	{
		int n,m,i,j;
		cin>>n>>m;
		vector<int> a(n);
		cin>>a;
		vector<pa> b(n);
		for (i=0; i<n; i++) b[i]={a[i],i};
		deque<pa> q(all(b));
		vector<vector<int>> win(n);
		for (i=1; i<=n; i++)
		{
			auto [ax,x]=q.front(); q.pop_front();
			auto [ay,y]=q.front(); q.pop_front();
			if (ax<ay) swap(ax,ay),swap(x,y);
			win[x].push_back(i);
			q.push_front({ax,x});
			q.push_back({ay,y});
		}
		while (m--)
		{
			int x,k;
			cin>>x>>k;
			--x;
			if (k>=n) cout<<(k-n)*(a[x]==n)+win[x].size()<<'\n';
			else cout<<upper_bound(all(win[x]),k)-win[x].begin()<<'\n';
		}
	}
}