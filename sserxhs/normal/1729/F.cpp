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
		int n,m,i,j;
		string t;
		cin>>t; n=t.size();
		int w;
		cin>>w>>m;
		vector<int> a(n),s(n+1);
		for (i=0; i<n; i++) a[i]=(t[i]-'0')%9,s[i+1]=s[i]+a[i];
		vector<vector<int>> fir(9);
		for (i=0; i<=n-w; i++) fir[(s[i+w]-s[i])%9].push_back(i);
		while (m--)
		{
			int l,r,k,x;
			cin>>l>>r>>k;
			x=s[r]-s[l-1];
			pair<int,int> res={n+1,n+1};
			for (i=0; i<9; i++) if (int y=(k+(9-i)*x)%9; fir[i].size()&&fir[y].size()>(i==y)) res=min(res,pair{fir[i][0],fir[y][i==y]});
			if (res.first>n) cout<<"-1 -1\n"; else
			{
				auto [x,y]=res;
				cout<<x+1<<' '<<y+1<<'\n';
			}
		}
	}
}