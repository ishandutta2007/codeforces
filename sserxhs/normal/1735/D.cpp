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
	int n,m,i,j,k;
	cin>>n>>m;
	map<ui,int> mp;
	vector a(n,vector(m,0));
	vector v(n,0u);
	for (i=0; i<n; i++)
	{
		cin>>a[i];
		for (int x:a[i]) v[i]=v[i]*3+x;
		mp[v[i]]=i;
	}
	vector cnt(n,0);
	for (i=0; i<n; i++) for (j=i+1; j<n; j++)
	{
		ui tmp=0;
		for (k=0; k<m; k++) tmp=tmp*3+(6-a[i][k]-a[j][k])%3;
		if (mp.count(tmp)) ++cnt[mp[tmp]];
	}
	ll res=0;
	for (i=0; i<n; i++) res+=(ll)cnt[i]*(cnt[i]-1)/2;
	cout<<res<<'\n';
}