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
struct union_set
{
	vector<int> f,siz;
	int n;
	union_set() {}
	union_set(int nn):n(nn),f(nn+1),siz(nn+1)
	{
		iota(all(f),0);
		fill(all(siz),1);
	}
	int getf(int u) { return f[u]==u?u:f[u]=getf(f[u]); }
	void merge(int u,int v)
	{
		dbg(u,v);
		u=getf(u); v=getf(v);
		if (u!=v) siz[v]+=siz[u];
		f[u]=v;
	}
	bool connected(int u,int v) { return getf(u)==getf(v); }
};
struct Q
{
	int x,y;
	Q operator+(const Q &o) const { return {x+o.x,y+o.y}; }
	Q operator-(const Q &o) const { return {x-o.x,y-o.y}; }
	Q &operator+=(const Q &o) { x+=o.x; y+=o.y; return *this; }
	Q &operator-=(const Q &o) { x-=o.x; y-=o.y; return *this; }
	bool operator<(const Q &o) const { return x==o.x?y<o.y:x<o.x; }
	bool operator==(const Q &o) const { return x==o.x&&y==o.y; }
	bool operator!=(const Q &o) const { return x!=o.x||y!=o.y; }
	ll len() const { return (ll)x*x+(ll)y*y; }
};
const Q dd[4]={{0,1},{1,0},{0,-1},{-1,0}};
const Q d[8]={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T; cin>>T;
	while (T--)
	{
		int n,m,i,j,k;
		auto av=[&](const Q &o) -> bool
		{
			return o.x>=0&&o.y>=0&&o.x<n &&o.y<m;
		};
		cin>>n>>m;
		vector<string> a(n);
		cin>>a;
		union_set s(n*m),t(n*m);
		for (i=0; i<n; i++) for (j=0; j<m; j++) if (a[i][j]=='*')
		{
			Q o{i,j};
			for (k=0; k<8; k++) if (Q v=o+d[k]; av(v)&&a[v.x][v.y]=='*')
			{
				s.merge(o.x*m+o.y,v.x*m+v.y);
			}
			for (k=0; k<4; k++) if (Q v=o+dd[k]; av(v)&&a[v.x][v.y]=='*')
			{
				t.merge(o.x*m+o.y,v.x*m+v.y);
			}
		}
		for (i=0; i<n; i++) for (j=0; j<m; j++) if (a[i][j]=='*'&&s.siz[s.getf(i*m+j)]!=3||s.siz[s.getf(i*m+j)]!=t.siz[t.getf(i*m+j)]) goto no;
		for (i=0; i<n; i++) for (j=2; j<m; j++) if (a[i].substr(j-2,3)=="***") goto no;
		for (i=2; i<n; i++) for (j=0; j<m; j++) if (a[i][j]=='*'&&a[i-1][j]=='*'&&a[i-2][j]=='*') goto no;
		cout<<"YES\n"; continue;
		no:cout<<"NO\n";
	}
}