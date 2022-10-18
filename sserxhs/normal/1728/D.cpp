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
const string ans[3]={"Bob","Draw","Alice"};
const int N=5e3+5;
int f[N][N],a[N];
int sgn(int x)
{
	if (x>=0) return x>0;
	return -1;
}
int dfs(int l,int r)
{
	if (l>r) return 0;
	if (l==r) return 1;
	if (f[l][r]!=-2) return f[l][r];
	return f[l][r]=max(min(dfs(l+2,r)?dfs(l+2,r):sgn(a[l+1]-a[l]),dfs(l+1,r-1)?dfs(l+1,r-1):sgn(a[r]-a[l]))
		,min(dfs(l,r-2)?dfs(l,r-2):sgn(a[r-1]-a[r]),dfs(l+1,r-1)?dfs(l+1,r-1):sgn(a[l]-a[r])));
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T; cin>>T;
	while (T--)
	{
		int n,m,i,j;
		string s;
		cin>>s;
		n=s.size();
		for (i=1; i<=n; i++) a[i]=s[i-1]-'a';
		for (i=0; i<=n+1; i++) for (j=0; j<=n+1; j++) f[i][j]=-2;
		cout<<ans[dfs(1,n)+1]<<'\n';
		// for (i=1; i<=n; i++) for (j=i+1; j<=n; j++) if (f[i][j]!=-2) dbg(i,j,f[i][j]);
	}
}