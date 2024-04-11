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
const int N=5e6+5;
int a[N],b[N],mx[N],cnt[N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T;cin>>T;
	while (T--)
	{
		int n,m,mn,i,j,ans=1e9;
		cin>>n>>m;
		iota(mx,mx+m+1,0);
		fill_n(a+1,m,0);
		fill_n(cnt+1,m,0);
		while (n--)
		{
			int x;
			cin>>x;
			a[x]=1;
		}
		int xx;
		for (mn=1;mn<=m;mn++) if (a[mn]) break;
		for (xx=m;xx;xx--) if (a[xx]) break;
		ans=xx-mn;
		for (i=1;i<=m;i++) if (a[i]) ++cnt[i];
		for (i=sqrt(m);i;i--)
		{
			for (j=i;j*i<=m;j++) if (int x=max(mx[i],mx[j]);mx[i*j]>x)
			{
				if (a[i*j])
				{
					--cnt[mx[i*j]];
					++cnt[x];
					while (!cnt[xx]) --xx;
				}
				mx[i*j]=x;
			} 
			ans=min(ans,xx-min(i,mn));
		}
		cout<<ans<<'\n';
	}
}