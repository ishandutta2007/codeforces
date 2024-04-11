//114514min
//ACM 
#include "bits/stdc++.h"
using namespace std;
template<typename typC,typename typD> istream & operator>>(istream &cin,pair<typC,typD> &a) {return cin>>a.first>>a.second;}
template<typename typC> istream & operator>>(istream &cin,vector<typC> &a)
{
	for (auto &x:a) cin>>x;
	return cin;
}
template<typename typC,typename typD> ostream & operator<<(ostream &cout,const pair<typC,typD> &a) {return cout<<a.first<<' '<<a.second;}
template<typename typC,typename typD> ostream & operator<<(ostream &cout,const vector<pair<typC,typD>> &a)
{
	for (auto &x:a) cout<<x<<'\n';
	return cout;
}
template<typename typC> ostream & operator<<(ostream &cout,const vector<typC> &a)
{
	int n=a.size(),i;
	if (!n) return cout;
	cout<<a[0];
	for (i=1;i<n;i++) cout<<' '<<a[i];
	return cout;
}
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=6e5+5;
struct Q
{
	int v,w;
};
vector<Q> e[N];
bool ed[N],eed[N];
vector<int> pt;
void dfs(int u)
{
	ed[u]=1;
	pt.push_back(u);
	for (auto [v,w]:e[u]) if (!eed[w])
	{
		eed[w]=1;
		if (ed[v]) pt.push_back(v); else dfs(v);
		pt.push_back(u);
	}
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int m,n,i,j;
	cin>>m;n=m*2;
	for (i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		e[u].push_back({v,i});
		e[v].push_back({u,i});
	}
	vector a(2,vector(0,0));
	vector b(4,string(0,'0'));
	for (i=1;i<=n;i++) if (!ed[i]&&e[i].size())
	{
		pt.clear();
		dfs(i);
		pt.pop_back();
		if (pt.size()==2)
		{
			cout<<-1<<endl;
			return 0;
		}
		assert(pt.size()%2==0);
		int q=pt.size()>>1;
		for (j=0;j<q;j++) a[0].push_back(pt[j]);
		reverse(all(pt));
		for (j=0;j<q;j++) a[1].push_back(pt[j]);
		if (q&1)
		{
			for (j=1;j<q;j+=2) b[0]+="LR";
			b[0]+="U";
			for (j=1;j<q;j+=2) b[1]+="LR";
			b[1]+="D";
			b[2]+="U";
			for (j=1;j<q;j+=2) b[2]+="LR";
			b[3]+="D";
			for (j=1;j<q;j+=2) b[3]+="LR";
		}
		else
		{
			for (j=0;j<q;j+=2) b[0]+="LR";
			for (j=0;j<q;j+=2) b[1]+="LR";
			b[2]+="U";for (j=2;j<q;j+=2) b[2]+="LR";b[2]+="U";
			b[3]+="D";for (j=2;j<q;j+=2) b[3]+="LR";b[3]+="D";
		}
	}
	cout<<"2 "<<m<<'\n';
	for (auto &v:a) cout<<v<<'\n';
	for (auto &s:b) cout<<s<<'\n';
}