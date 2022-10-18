//114514min
//ACM 
#include "bits/stdc++.h"
using namespace std;
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef unsigned long long ll;
#define all(x) (x).begin(),(x).end()
const int N=1e6+5;
const ui p=998244353;
void inc(ui &x,const ui &y) { if ((x+=y)>=p) x-=p; }
void dec(ui &x,const ui &y) { if ((x+=p-y)>=p) x-=p; }
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int n,m,i,j,k;
	cin>>n>>m;
	vector f(2,vector(n+1,0u));
	f[0][0]=1;
	vector ans(n+1,0llu);
	for (k=0; k<699; k++)
	{
		j=k&1;
		for (i=1; i<=n; i++) ans[i]+=f[j][i];
		fill(all(f[j^1]),0);
		for (i=0; i+k+m<=n; i++) inc(f[j^1][i+k+m],f[j][i]);
		for (i=k+m; i<=n; i++) inc(f[j^1][i],f[j^1][i-(k+m)]);
	}
	// for (j=0; j<700; j++) for (i=1; i<=n; i++) ans[i]+=f[j][i];
	for (i=1; i<=n; i++) cout<<ans[i]%p<<" \n"[i==n];
}