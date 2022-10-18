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
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j;
		vector<vector<int>> app(26);
		string s;
		cin>>s>>m;n=s.size();
		for (i=0;i<n;i++) app[s[i]-'a'].push_back(i);
		string t;
		for (i=0;i<26;i++) if (m>=(i+1)*app[i].size()) m-=(i+1)*app[i].size(); else
		{
			app[i].resize(m/(i+1));
			break;
		}
		if (i==26) i=25;
		for (auto &c:s) c='0';
		for (j=0;j<=i;j++) for (int x:app[j]) s[x]=j+'a';
		for (auto c:s) if (c!='0') t+=c;
		cout<<t<<'\n';
	}
}