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
string f(int t)
{
	int x=t/60,y=t%60;
	return to_string(x/10)+to_string(x%10)+to_string(y/10)+to_string(y%10);
}
int g(string s)
{
	return stoi(s.substr(0,2))*60+stoi(s.substr(3));
}
int h(int t)
{
	auto s=f(t);
	auto g=s;
	reverse(all(g));
	return s==g;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j;
		string s;
		cin>>s>>m;
		n=g(s);
		j=h(n);
		for (i=(n+m)%1440;i!=n;i=(i+m)%1440) j+=h(i);
		cout<<j<<'\n';
	}
}