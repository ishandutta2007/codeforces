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
bool fun(vector<int> a,int n,int m)
{
	ll r=0;
	for (int &x:a) x/=n;
	sort(all(a));reverse(all(a));
	while (a.size()&&a.back()<2) a.pop_back();
	if ((r=accumulate(all(a),0ll))<m) return 0;
	r-=m;
	// dbg(r);
	for (int x:a) if (x>2) return 1;
	return r%2==0;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T;cin>>T;
	while (T--)
	{
		int n,m,q,i,j;
		cin>>n>>m>>q;
		vector<int> a(q);
		ll r=0;
		cin>>a;
		if (fun(a,n,m)||fun(a,m,n)) cout<<"Yes\n"; else cout<<"No\n";
	}
}