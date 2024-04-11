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
	int T; cin>>T;
	while (T--)
	{
		int n,m,i,k,j,r=0;
		cin>>n;
		vector<vector<int>> a(1,vector<int>(n)),b(1,vector<int>(n));
		cin>>a>>b;
		for (j=29; j>=0; j--)
		{
			m=a.size();
			// dbg(j,m);
			for (i=0; i<m; i++)
			{
				int cnt=0;
				for (int x:a[i]) cnt+=x>>j&1;
				for (int x:b[i]) cnt-=1^x>>j&1;
				if (cnt) break;
			}
			if (i==m)
			{
				vector<vector<int>> c,d;
				for (i=0; i<m; i++)
				{
					vector<int> ta[2],tb[2];
					int n=a[i].size(),cnt=0;
					for (int x:a[i]) cnt+=x>>j&1;
					for (int x:a[i]) ta[x>>j&1].push_back(x);
					for (int x:b[i]) tb[x>>j&1].push_back(x);
					for (int x:{0,1}) if (ta[x].size()) c.push_back(ta[x]);
					for (int x:{1,0}) if (tb[x].size()) d.push_back(tb[x]);
				}
				r|=1<<j;
				swap(a,c);
				swap(b,d);
			}
		}
		cout<<r<<'\n';
	}
}