//114514min
//ACM 
#include "bits/stdc++.h"
using namespace std;
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
template<typename typC> bool cmin(typC &x,const typC &y) { if (x>y) { x=y; return 1; } return 0; }
template<typename typC> bool cmax(typC &x,const typC &y) { if (x<y) { x=y; return 1; } return 0; }
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
// void inc(ui &x,const ui &y) { if ((x+=y)>=p) x-=p; }
// void dec(ui &x,const ui &y) { if ((x+=p-y)>=p) x-=p; }
const int N=1e6+5;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int n,i;
	string s;
	cin>>n>>s;
	if (count(all(s),'1')==0) { cout<<0<<endl; return 0; }
	if (count(all(s),'0')==0) { cout<<s<<endl; return 0; }
	s=s.substr(s.find('1'));
	n=s.size();
	vector<int> a,b;
	for (i=0; i<n; i++) if (s[i]=='1') a.push_back(i); else b.push_back(i);
	string res=s;
	// dbg(a,b);
	while (a.back()>b[0]) a.pop_back();
	res[b[0]]='1';
	// dbg(a);
	for (i=1; i<b.size(); i++)
	{
		int D=b[i]-b[0];
		bool flg=0;
		while (a.size()&&a.back()+D>=n) a.pop_back();
		for (int x:a) if (s[x+D]=='1')
		{
			flg=1;
			break;
		}
		if (!flg) continue;
		vector<int> c;
		for (int x:a) if (x+D<n&&s[x+D]=='1') c.push_back(x);
		swap(a,c);
		res[b[i]]='1';
	}
	cout<<res<<endl;
}