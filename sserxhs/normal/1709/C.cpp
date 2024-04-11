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
bool check(const string &s)
{
	int cur=0;
	for (auto c:s) if ((cur+=c=='('?1:-1)<0) return 0;
	return !cur;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T;cin>>T;
	while (T--)
	{
		string s;
		cin>>s;
		int n=s.size(),i,j,m;
		bool flg=0;
		vector cnt(2,0);
		string t2=s;
		vector<int> pos;
		for (i=0;i<n;i++) if (s[i]=='?') pos.push_back(i);
		if (n&1) goto no;
		for (i=0;i<n;i++) if (s[i]=='(') ++cnt[0]; else if (s[i]==')') ++cnt[1];
		if (min(cnt[0],cnt[1])+pos.size()<max(cnt[0],cnt[1])) goto no;
		for (i=0;i+cnt[0]<n>>1;i++) t2[pos[i]]='(';
		m=i;
		for (++i;i<pos.size();i++) t2[pos[i]]=')';
		if (!check(t2)) goto no;
		if (m&&m<pos.size())
		{
			t2[pos[m-1]]=')';
			t2[pos[m]]='(';
			if (check(t2)) goto no;
		}
		cout<<"YES\n";continue;
		no:cout<<"NO\n";
	}
}