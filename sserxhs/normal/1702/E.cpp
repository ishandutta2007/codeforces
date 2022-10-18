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
const int N=2e5+5;
vector<int> e[N];
int col[N];
bool flg;
void dfs(int u)
{
	for (int v:e[u]) if (col[v]) flg|=col[u]==col[v]; else col[v]=3^col[u],dfs(v);
}
struct Q
{
	int u,v;

};
Q a[N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j;
		cin>>n;
		for (i=1;i<=n;i++) e[i].clear();
		vector<int> rd(n+1);
		vector<vector<int>> id(n+1);
		for (i=1;i<=n;i++) cin>>a[i].u>>a[i].v,++rd[a[i].u],++rd[a[i].v],id[a[i].u].push_back(i),id[a[i].v].push_back(i);
		if (*max_element(all(rd))!=2) {cout<<"NO\n";continue;}
		for (i=1;i<=n;i++)
		{
			int u,v;
			u=id[i][0];v=id[i][1];
			e[u].push_back(v);
			e[v].push_back(u);
		}
		flg=0;
		for (i=1;i<=n;i++) col[i]=0;
		for (i=1;i<=n;i++) if (!col[i]) col[i]=1,dfs(i);
		if (flg) cout<<"NO\n"; else cout<<"YES\n";
	}
}