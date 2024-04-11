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
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j;
		cin>>n;
		vector<int> a(n),d(n);
		cin>>a;
		for (i=1;i+1<n;i++) d[i]=max(0,max(a[i-1],a[i+1])+1-a[i]);
		if (n&1)
		{
			ll res=0;
			for (i=1;i<n;i+=2) res+=d[i];
			cout<<res<<'\n';
		}
		else
		{
			// cout<<"?\n";
			vector<ll> b(n+3),c(n+3);
			for (i=1;i+2<=n;i+=2) b[i+2]=b[i]+d[i];
			for (i=n;i>2;i-=2) c[i-2]=c[i]+d[i-2];
			ll res=min(b[n-1],c[2]);
			for (i=1;i<n;i+=2) res=min(res,b[i]+c[i+1]);
			cout<<res<<'\n';
		}
	}
}