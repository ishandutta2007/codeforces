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
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T; cin>>T;
	while (T--)
	{
		int n,m,i,j;
		cin>>n>>m;
		vector e(n,vector(0,0));
		while (m--)
		{
			int u,v;
			cin>>u>>v;
			e[--u].push_back(--v);
			e[v].push_back(u);
		}
		int q;
		cin>>q;
		vector<int> b(q);
		vector<int> flg(q);
		for (int &x:b) cin>>x,--x;
		int k,K;
		cin>>k;
		vector<int> p(k);
		for (int &x:p) cin>>x,flg[--x]=1,x=b[x];
		K=1<<k;
		vector id(n,0);
		for (i=0; i<k; i++) id[p[i]]|=1<<i;
		vector f(n,bitset<64>());
		vector dis(n,0);
		f[0][id[0]]=1;
		dis[0]=1;
		queue<int> Q; Q.push(0);
		while (Q.size())
		{
			int u=Q.front(); Q.pop();
			if (id[u])
			{
				for (i=0; i<K; i++) f[u][i|id[u]]=f[u][i|id[u]]|f[u][i];
			}
			for (int v:e[u]) if (!dis[v])
			{
				dis[v]=dis[u]+1;
				f[v]=f[u];
				Q.push(v);
			}
			else if (dis[v]==dis[u]+1) f[v]|=f[u];
		}
		// dbg(id);
		// for (i=0; i<n; i++) for (j=0; j<K; j++) if (f[i][j]) dbg(i,bitset<5>(j));
		bitset<64> cur;
		cur[0]=1;
		// dbg(flg);
		for (int l=0; l<q; l++) if (!flg[l])
		{
			int u=b[l];
			// dbg(u);
			bitset<64> tmp;
			for (i=0; i<K; i++) for (j=i; j; j=j-1&i) tmp[i]=tmp[i]|(cur[i^j]&f[u][j]);
			cur|=tmp;
		}
		int res=0;
		for (i=0; i<K; i++) if (cur[i]) cmax(res,__builtin_popcount(i));
		cout<<k-res<<'\n';
	}
}