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
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T; cin>>T;
	while (T--)
	{
		int n,i,j;
		vector x(4,0),y(4,0);
		cin>>n;
		for (i=0; i<4; i++) cin>>x[i]>>y[i];
		int X=x[0]^x[1]^x[2],Y=y[0]^y[1]^y[2];
		auto spe=[&]()
		{
			if (X!=2&&X!=n-1||Y!=2&&Y!=n-1) return 1;
			set<pair<int,int>> s;
			for (i=0; i<3; i++) s.insert({x[i],y[i]});
			set<set<pair<int,int>>> t={{{1,1},{1,2},{2,1}},{{1,n},{1,n-1},{2,n}},{{n,n},{n,n-1},{n-1,n}},{{n,1},{n-1,1},{n,2}}};
			if (!t.count(s)) return 1;
			if (count(all(x),x[3])>=3||count(all(y),y[3])>=3) return 1;
			return 0;
		};
		if ((((X^x[3])&1)||((Y^y[3])&1))&&spe()) cout<<"YES\n"; else cout<<"NO\n";
	}
}