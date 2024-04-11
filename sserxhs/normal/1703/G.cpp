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
const ll inf=1e18;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T;cin>>T;
	while (T--)
	{
		ll r=-1e18;
		int n,m,i,j;
		cin>>n>>m;
		vector<int> a(n);
		cin>>a;
		vector f(n+1,vector(31,-inf));
		f[0][0]=0;
		for (i=0;i<n;i++) for (j=0;j<31;j++)
		{
			f[i+1][j]=max(f[i+1][j],f[i][j]+(a[i]>>j)-m);
			f[i+1][min(j+1,30)]=max(f[i+1][min(j+1,30)],f[i][j]+(a[i]>>min(j+1,30)));
		}
		cout<<*max_element(all(f[n]))<<'\n';
	}
}