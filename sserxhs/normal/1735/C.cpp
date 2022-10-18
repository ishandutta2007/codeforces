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
		u=getf(u); v=getf(v);
		if (u!=v) siz[v]+=siz[u];
		f[u]=v;
	}
	bool connected(int u,int v) { return getf(u)==getf(v); }
};
const int N=1e6+5;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T; cin>>T;
	while (T--)
	{
		int n,m,i,j;
		string s;
		cin>>n>>s;
		string t;
		vector<int> nxt(26,-1),pre(26,-1);
		m=0;
		for (auto c:s) if (find(all(t),c)==t.end()) t+=c;
		union_set e(25);
		for (auto c:t)
		{
			c-='a';
			for (i=0; i<26; i++) if (c!=i&&nxt[i]==-1&&(!e.connected(c,i)||e.siz[c]==26))
			{
				pre[c]=i;
				nxt[i]=c;
				e.merge(c,i);
				break;
			}
		}
		for (auto &c:s) c=pre[c-'a']+'a';
		cout<<s<<'\n';
	}
}