//114514min
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
	union_set(){}
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
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j;
		ll r=0;
		cin>>n;
		union_set s(n);
		vector<int> a(n),b(n),siz(n+1);
		for (int &x:a) cin>>x;
		for (int &x:b) cin>>x;
		for (i=0;i<n;i++) s.uni(a[i],b[i]);
		for (i=1;i<=n;i++) ++siz[s.getf(i)];
		int L=1,R=n;
		for (i=1;i<=n;i++) if (s.f[i]==i&&siz[i]>1)
		{
			int x=siz[i]>>1;
			vector<int> d;
			for (j=0;j<x;j++) d.push_back(L++),d.push_back(R--);
			d.push_back(d[0]);x<<=1;
			for (j=0;j<x;j++) r+=abs(d[j+1]-d[j]);
		}
		cout<<r<<'\n';
	}
}