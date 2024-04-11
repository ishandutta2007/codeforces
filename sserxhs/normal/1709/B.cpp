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
	int n,m,i,j;
	cin>>n>>m;
	vector<int> a(n+1);
	vector<ll> b(n+2),c(n+2);
	for (i=1;i<=n;i++) cin>>a[i];
	for (i=1;i<n;i++) b[i]=b[i-1]+max(a[i]-a[i+1],0);
	for (i=n;i;i--) c[i]=c[i+1]+max(a[i]-a[i-1],0);
	while (m--)
	{
		int l,r;
		cin>>l>>r;
		if (l<r)
		{
			cout<<b[r-1]-b[l-1]<<'\n';
		}
		else
		{
			cout<<c[r+1]-c[l+1]<<'\n';
		}
	}
}