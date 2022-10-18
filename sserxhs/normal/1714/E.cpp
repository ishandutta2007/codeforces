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
	int T,i;cin>>T;
	vector<int> nxt(10);
	for (i=0;i<9;i++) nxt[i]=i*2%10;
	// for (i=0;i<9;i++) cerr<<i<<' '<<nxt[i]<<'\n';
	while (T--)
	{
		int n,i;
		cin>>n;
		vector<int> a(n);
		cin>>a;
		for (int &x:a) while (x%10!=2&&x%10) x+=x%10;
		for (i=1;i<n;i++) if ((a[i]-a[i-1])%20) goto no;
		if (a[0]%10==0&&count(all(a),a[0])!=n) goto no;
		cout<<"Yes\n";
		continue;
		no:cout<<"No\n";
	}
}