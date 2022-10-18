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
const int N=1e6+5;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int n,i,x;
	ll r=0;
	cin>>n;
	vector a(2,vector(n+1,0));
	vector lz(2,0);
	for (auto &v:a) for (i=1;i<=n;i++) cin>>v[i];
	for (auto &v:a) for (i=1;i<=n;i++) cin>>x,v[i]-=x;
	for (auto &v:a) for (i=1;i<=n;i++) v[i]+=v[i-1];
	if (a[0][n]+a[1][n]) {cout<<"-1\n";return 0;}
	for (i=1;i<=n;i++) if ((a[0][i]+=lz[0])>0^(a[1][i]+=lz[1])>0)
	{
		if (a[0][i]>0)
		{
			x=min(a[0][i],-a[1][i]);
			r+=x;
			a[0][i]-=x;lz[0]-=x;
			a[1][i]+=x;lz[1]+=x;
			r+=abs(a[0][i])+abs(a[1][i]);
		}
		else
		{
			x=min(-a[0][i],a[1][i]);
			r+=x;
			a[0][i]+=x;lz[0]+=x;
			a[1][i]-=x;lz[1]-=x;
			r+=abs(a[0][i])+abs(a[1][i]);
		}
	} else r+=abs(a[0][i]+a[1][i]);
	cout<<r<<endl;
}