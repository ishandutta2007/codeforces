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
		cin>>n>>m;
		vector<int> s(n+1);
		for (i=1;i<=n;i++) cin>>s[i],s[i]+=s[i-1];
		if (s[n]<m) {cout<<"-1\n";continue;}
		for (i=0,j=0;i<n;i++)
		{
			while (j<n&&s[j+1]-s[i]<=m) ++j;
			if (s[j]-s[i]!=m) break;
			r=max(r,j-i);
		}
		cout<<n-r<<'\n';
	}
}