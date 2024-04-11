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
mt19937 rnd(125);
// #define int ll
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T; cin>>T;
	while (T--)
	{
		int n,m,i,j;
		cin>>n;
		ll res=0;
		vector<int> a(n),p(n+1,n);
		// iota(all(a),0);
		// shuffle(all(a),rnd);
		cin>>a;
		for (i=0; i<n; i++) p[a[i]]=i;
		int L=n,R=0;
		auto solve=[&](int L,int R,int k) -> ll
		{
			if (k<R-L+1) return 0ll;
			int x=max(0,R-k);
			// dbg(L,R,k,(x+k-R+L+k-R)*(L-x+1ll)/2);
			return (x+k-R+L+k-R)*(L-x+1ll)/2;
		};
		for (i=0; i<n; i++)
		{
			cmin(L,p[i]),cmax(R,p[i]);
			int x=p[i+1],len=2*(i+1);
			if (x<L) ++x,res+=solve(L-x,R-x,len)-solve(L-x,n-x,len);
			else if (x>R) res+=solve(L,R,len)-solve(L,x,len);
		}
		cout<<res<<'\n';
	}
}