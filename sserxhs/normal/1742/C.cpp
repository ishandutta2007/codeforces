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
		n=m=8;
		char res;
		vector<string> a(8);
		cin>>a;
		// cout<<a<<endl;
		/*{
			auto b=a;
			for (i=0; i<n; i++) for (j=0; j<n; j++) a[i][j]=b[j][i];
		}*/
		// for (auto &s:a) cerr<<s<<'\n';
		for (i=0; i<n; i++)
		{
			for (j=0; j<n; j++) if (a[i][j]!=a[i][0]) break;
			if (j==n&&a[i][0]=='R')
			{
				res=a[i][0];
				goto end;
			}
		}
		{
			auto b=a;
			for (i=0; i<n; i++) for (j=0; j<n; j++) a[i][j]=b[j][i];
		}
		// for (auto &s:a) cerr<<s<<'\n';
		for (i=0; i<n; i++)
		{
			for (j=0; j<n; j++) if (a[i][j]!=a[i][0]) break;
			if (j==n&&a[i][0]=='B')
			{
				res=a[i][0];
				goto end;
			}
		}
		end:cout<<res<<'\n';
	}
}