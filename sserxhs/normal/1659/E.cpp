#include "bits/stdc++.h"
using namespace std;
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=1e6+5;
struct union_set
{
	vector<int> f;
	int n;
	union_set(int nn):n(nn),f(nn+1)
	{
		iota(all(f),0);
	}
	int getf(int u) {return f[u]==u?u:f[u]=getf(f[u]);}
	void uni(int u,int v)
	{
		u=getf(u);v=getf(v);
		f[u]=v;
	}
	bool con(int u,int v) {return getf(u)==getf(v);}
};
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int n,m,q,i;
	cin>>n>>m;
	vector<union_set> s(30,union_set(n)),t(30,union_set(n));
	while (m--)
	{
		int u,v,w;
		cin>>u>>v>>w;
		if (1^w&1) for (i=0;i<30;i++) s[i].uni(0,u),s[i].uni(0,v);
		else for (i=1;i<30;i++) if (w>>i&1) s[i].uni(u,v);
		for (i=0;i<30;i++) if (w>>i&1) t[i].uni(u,v);
	}
	cin>>q;
	while (q--)
	{
		int u,v,r=1,rr=1;
		cin>>u>>v;
		for (auto &s:s) rr&=!s.con(u,0);
		for (auto &s:t) r&=!s.con(u,v);
		cout<<r*(1+rr)<<'\n';
	}
}