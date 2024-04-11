//114514min
//ACM 
#include "bits/stdc++.h"
using namespace std;
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
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
const int inf=1e9;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T; cin>>T;
	while (T--)
	{
		int n,m,i,j,res=2.1e9,cur=-1;
		cin>>n;
		vector a(2,vector(n,0)),b(2,vector(n+1,-inf)),c(2,vector(n+1,-inf));
		cin>>a; a[0][0]=-1;
		for (auto &v:a) for (int &x:v) ++x;
		for (i=0; i<2; i++) for (j=n-1; j>=0; j--) b[i][j]=max(a[i][j]+j,b[i][j+1]);
		for (i=0; i<2; i++) for (j=n-1; j>=0; j--) c[i][j]=max(a[i][j]-j,c[i][j+1]);
		i=-1;
		res=min(res,max({cur+2*(n-i-1),c[0][i+1]+n-2+n-i,b[1][i+1]-i-1}));
		// dbg(cur+2*(n-i-1),c[0][i+1]+n-2+n-i,b[1][i+1]-i-1);
		for (i=0; i<n; i++)
		{
			if (i&1)
			{
				cur=max({cur+2,a[0][i],a[1][i]+1});
				res=min(res,max({cur+2*(n-i-1),c[0][i+1]+n-2+n-i,b[1][i+1]-i-1}));
			}
			else
			{
				cur=max({cur+2,a[0][i]+1,a[1][i]});
				res=min(res,max({cur+2*(n-i-1),c[1][i+1]+n-2+n-i,b[0][i+1]-i-1}));
			}
			// dbg(res);
		}
		cout<<res<<'\n';
	}
}