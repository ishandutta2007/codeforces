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
const ll inf=1e18;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T; cin>>T;
	while (T--)
	{
		int n,m,i,j,x,y,k;
		cin>>n>>x>>y;
		string s,t;
		cin>>s>>t;
		vector<int> a;
		for (i=0; i<n; i++) if (s[i]!=t[i]) a.push_back(i);
		if (a.size()&1) { cout<<"-1\n"; continue; }
		if (!a.size()) cout<<"0\n";
		else if (x>=y)
		{
			if (a.size()>2||a[0]+1!=a[1]) cout<<(ll)y*(a.size()>>1)<<'\n';
			else if (a[0]<=1&&a[1]>=n-2) cout<<2ll*x<<'\n';
			else cout<<min(2*y,x)<<'\n';
		}
		else
		{
			n=a.size();
			vector<array<ll,2>> f(n+1,{inf,inf});
			f[0][0]=0; f[0][1]=inf;
			for (i=0; i<n; i++)
			{
				if (i+2<=n)
				{
					cmin(f[i+2][0],f[i][0]+(ll)x*(a[i+1]-a[i]));
					cmin(f[i+2][1],f[i][1]+(ll)x*(a[i+1]-a[i]));
				}
				cmin(f[i+1][0],f[i][1]+y);
				cmin(f[i+1][1],f[i][0]);
			}
			cout<<f[n][0]<<'\n';
		}
	}
}