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
		int n,m,i,j;
		cin>>n>>m;
		vector<vector<int>> e(n);
		vector<map<int,ll>> dp(n);
		vector<int> f(n,-1),a(n);
		for (i=1; i<n; i++) cin>>f[i],e[--f[i]].push_back(i);
		cin>>a;
		function<ll(int,int)> dfs=[&](int u,int m)
		{
			if (dp[u].count(m)) return dp[u][m];
			ll &res=dp[u][m];
			res=(ll)m*a[u];
			int sz=e[u].size();
			if (!sz) return res;
			vector<int> tmp;
			for (int v:e[u])
			{
				auto [x,y]=pair{dfs(v,m/sz),dfs(v,(m+sz-1)/sz)};
				tmp.push_back(y-x);
				res+=x;
			}
			sort(all(tmp)); reverse(all(tmp));
			m%=sz;
			return res=accumulate(tmp.begin(),tmp.begin()+m,res);
		};
		cout<<dfs(0,m)<<'\n';
	}
}