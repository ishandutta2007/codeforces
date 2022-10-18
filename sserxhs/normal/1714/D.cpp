//114514min
//ACM 
#include "bits/stdc++.h"
using namespace std;
template<typename typC,typename typD> istream & operator>>(istream &cin,pair<typC,typD> &a) {return cin>>a.first>>a.second;}
template<typename typC> istream & operator>>(istream &cin,vector<typC> &a){for (auto &x:a) cin>>x;return cin;}
template<typename typC,typename typD> ostream & operator<<(ostream &cout,const pair<typC,typD> &a) {return cout<<a.first<<' '<<a.second;}
template<typename typC,typename typD> ostream & operator<<(ostream &cout,const vector<pair<typC,typD>> &a){for (auto &x:a) cout<<x<<'\n';return cout;}
template<typename typC> ostream & operator<<(ostream &cout,const vector<typC> &a){int n=a.size();if (!n) return cout;cout<<a[0];for (int i=1;i<n;i++) cout<<' '<<a[i];return cout;}
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=1e6+5,inf=1e9;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j,k;
		string s;
		cin>>s;n=s.size();
		cin>>m;
		map<string,int> t;
		for (i=1;i<=m;i++)
		{
			string tt;cin>>tt;
			t[tt]=i;
		}
		vector<int> f(n),g(n),l(n);
		for (i=0;i<n;i++) for (j=1;i+j<=n&&j<=10;j++) if (t.count(s.substr(i,j)))
		{
			f[i]=i+j;
			g[i]=t[s.substr(i,j)];
			l[i]=i;
		}
		for (i=1;i<n;i++) if (f[i]<f[i-1])
		{
			f[i]=f[i-1];
			g[i]=g[i-1];
			l[i]=l[i-1];
		}
		int r=0;i=0;
		vector<pair<int,int>> ans;
		while (i<n)
		{
			if (i==f[i]) break;
			ans.push_back({g[i],l[i]+1});
			i=f[i];
			// dbg(i);
		}
		if (i<n) cout<<"-1\n";
		else
		{
			cout<<ans.size()<<'\n'<<ans;
		}
	}
}