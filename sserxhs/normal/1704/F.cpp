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
const int N=5e5+5;
int sg[N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	{
		int n=5e5,i,j;
		for (i=2;i<=n;i++) if (i<=500)
		{
			set<int> s;
			for (j=0;j<=i-2;j++) s.insert(sg[j]^sg[i-j-2]);
			while (s.count(sg[i])) ++sg[i];
		} else sg[i]=sg[i-34];
	}//010xx10
	int T;cin>>T;
	while (T--)
	{
		int n,i,j,r=0;
		string s;
		cin>>n>>s;
		vector cnt(2,0);
		cnt[0]=count(all(s),'R');
		cnt[1]=count(all(s),'B');
		if (cnt[0]!=cnt[1])
		{
			if (cnt[0]>cnt[1]) cout<<"Alice\n"; else cout<<"Bob\n";
			continue;
		}
		for (i=j=0;i<n;i=j)
		{
			while (j<n&&(s[i]!=s[j])==(j-i&1)) ++j;
			r^=sg[j-i];
		}
		if (r) cout<<"Alice\n"; else cout<<"Bob\n";
	}
}