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
int dis(int x,int y)
{
	return abs(x-y);
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T; cin>>T;
	while (T--)
	{
		int n,m,i,j;
		string s;
		cin>>s;
		n=s.size();
		if (s[0]<s[n-1])
		{
			for (auto &c:s) c=25-(c-'a')+'a';
		}
		vector<basic_string<int>> cnt(26);
		for (i=0; i<n; i++) cnt[s[i]-='a']+=i+1;
		basic_string<int> r;
		// dbg((int)s[0],(int)s[n-1]);
		for (i=0; i<26; i++) if (dis(i,s[n-1])+dis(s[0],i)==dis(s[0],s[n-1])) r+=cnt[i];
		if (r.find(n)<r.find(1))
		{
			reverse(all(r));
		}
		// for (int x:r) cerr<<x<<' '; cerr<<'\n';
		if (r[0]!=1) rotate(r.begin(),find(all(r),1),find(all(r),1)+1);
		if (r.back()!=n) rotate(find(all(r),n),find(all(r),n)+1,r.end());
		cout<<dis(s[0],s[n-1])<<' '<<r.size()<<'\n';
		for (int x:r) cout<<x<<' '; cout<<'\n';
	}
}