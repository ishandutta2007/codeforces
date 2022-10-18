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
		int n,m,i,j,k,l;
		cin>>n;
		vector<pair<int,int>> e;
		vector<int> a(n),b(n),cnt(n);
		cin>>a>>b;
		for (i=1;i<n;i++) if (a[i]!=b[i])
		{
			for (j=i+2;j<n;j++) if (a[j]==a[i-1]&&a[j-1]==b[i]) break;
			if (j>=n)
			{
				cnt[i]=0;
				for (j=i+1;j<n;j++) cnt[j]=(a[j-1]==a[i-1]&&a[j]==b[i]);
				for (j=i+2;j<n;j++) cnt[j]+=cnt[j-1];
				for (j=i;j<n;j++) for (k=j+1;k<n;k++) if (a[j]==a[k]&&cnt[k]-cnt[j]) goto bk;
				bk:
				if (j==n) break;
				e.push_back({j,k});
				reverse(a.begin()+j+1,a.begin()+k);
				for (j=i+2;j<n;j++) if (a[j]==a[i-1]&&a[j-1]==b[i]) break;
			}
			if (j<n)
			{
				reverse(a.begin()+i,a.begin()+j);
				e.push_back({i-1,j});
			}
			else throw;
		}
		if (a[0]!=b[0]||a[n-1]!=b[n-1]||i<n) {cout<<"NO\n";continue;}
		cout<<"YES\n"<<e.size()<<'\n';
		for (auto [x,y]:e) cout<<x+1<<' '<<y+1<<'\n';
	}
}