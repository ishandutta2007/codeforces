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
	string s;
	cin>>s;
	while (s.size()&&s.back()=='0') s.pop_back();
	reverse(all(s));
	int shift=0;
	while (s.size()&&s.back()=='0') s.pop_back(),++shift;
	if (!s.size()) {cout<<-1<<endl;return 0;}
	bitset<70> t(s),x,y,z;
	x[1]=1;
	int i;
	map<unsigned long long,int> f;
	int n=s.size(),j;
	if (n==1)
	{
		cout<<shift+1<<' '<<shift+2<<endl;
		return 0;
	}
	if (n==2) f[1^t.to_ullong()],x^=t; else f[1]=0;
	for (i=1;i<1<<17;i++)
	{
		if (x==bitset<70>(1))
		{
			cout<<shift+1<<' '<<shift+i+1<<endl;
			return 0;
		}
		f[x.to_ullong()]=i;
		x<<=1;
		if (x[n-1]) x^=t;
	}
	y=x;
	for (i=1;i<=1<<20;i++)
	{
		if (f.count(y.to_ullong()))
		{
			cout<<shift+1<<' '<<shift+((ll)i<<17)-f[y.to_ullong()]+1<<endl;
			return 0;
		}
		z.reset();
		for (j=0;j<n;j++) if (x[j]) z^=y<<j;
		y=z;
		for (j=n;j>=0;j--) if (y[n-1+j]) y^=t<<j;
		for (j=n;j<70;j++) assert(!y[j]);
		//dbg(y);
	}
	assert(0);
}