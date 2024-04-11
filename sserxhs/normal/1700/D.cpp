//114514min
//ACM 
#include "bits/stdc++.h"
using namespace std;
template<typename typC,typename typD> istream & operator>>(istream &cin,pair<typC,typD> &a) {return cin>>a.first>>a.second;}
template<typename typC> istream & operator>>(istream &cin,vector<typC> &a)
{
	for (auto &x:a) cin>>x;
	return cin;
}
template<typename typC,typename typD> ostream & operator<<(ostream &cout,const pair<typC,typD> &a) {return cout<<a.first<<' '<<a.second;}
template<typename typC,typename typD> ostream & operator<<(ostream &cout,const vector<pair<typC,typD>> &a)
{
	for (auto &x:a) cout<<x<<'\n';
	return cout;
}
template<typename typC> ostream & operator<<(ostream &cout,const vector<typC> &a)
{
	int n=a.size(),i;
	if (!n) return cout;
	cout<<a[0];
	for (i=1;i<n;i++) cout<<' '<<a[i];
	return cout;
}
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
	cin>>n;
	vector<int> a(n);
	vector<ll> s(n+1),ans(n);
	for (i=0;i<n;i++) cin>>a[i],s[i+1]=s[i]+a[i];
	ans[0]=a[0];
	for (i=1;i<n;i++) ans[i]=max(ans[i-1],(s[i+1]+i)/(i+1));
	for (i=0;i<n;i++) ans[i]=max(ans[i],(s[n]+i)/(i+1));
	//assert(is_sorted(all(ans)));
	//dbg(ans);
	cin>>m;
	while (m--)
	{
		ll x;cin>>x;
		auto y=lower_bound(all(ans),x,[&](ll x,ll y){return x>y;})-ans.begin();
		if (y<n) cout<<y+1<<'\n'; else cout<<"-1\n";
	}
}