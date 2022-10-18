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
string s;
map<tuple<ll,ll,ll>,ll> g;
ll f(ll l1,ll l2,ll n)
{
	if (l1>l2) swap(l1,l2);
	if (n==0) return 0;
	// dbg(l1,l2,n);
	if (n<=20&&l2+n<=s.size())
	{
		ll res=0;
		for (int i=0; i<n; i++) res+=s[l1+i]!=s[l2+i];
		return res;
	}
	if (g.count({l1,l2,n})) return g[{l1,l2,n}];
	int x=__lg(l2);
	if (1ll<<x+1>=l2+n)
	{
		return g[{l1,l2,n}]=n-f(l1,l2-(1ll<<x),n);
	}
	ll len=(1ll<<x+1)-l2;
	return g[{l1,l2,n}]=f(l1,l2,len)+f(l1+len,l2+len,n-len);
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T; cin>>T;
	s="01";
	for (int i=1; i<=19; i++)
	{
		auto t=s;
		for (auto &c:t) c^=1;
		s+=t;
	}
	while (T--)
	{
		ll n,m;
		cin>>n>>m;
		cout<<f(0,n,m)<<'\n';
	}
}