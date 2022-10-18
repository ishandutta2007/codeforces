//114514min
//ACM 
#include "bits/stdc++.h"
using namespace std;
template<typename typC> istream & operator>>(istream &in,vector<typC> &a)
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
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j,r=0;
		cin>>n>>m;//--m;
		vector<int> a(n),b(n-1),s(n);
		for (int &x:a) cin>>x;
		for (i=0;i<n-1;i++) b[i]=a[i+1]*2>a[i];
		--n;
		//for (i=0;i<n;i++) cout<<b[i]<<" \n"[i+1==n];
		for (i=0;i<n;i++) s[i+1]=s[i]+b[i];
		for (i=m;i<=n;i++) if (s[i]-s[i-m]==m) ++r;
		cout<<r<<'\n';
	}
}