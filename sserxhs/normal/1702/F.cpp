//114514min
//ACM 
#include "bits/stdc++.h"
using namespace std;
template<typename typC,typename typD> ostream & operator<<(ostream &cout,const pair<typC,typD> &a) {return cout<<a.first<<' '<<a.second;}
template<typename typC,typename typD> ostream & operator<<(ostream &cout,const vector<typC,typD> &a)
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
const int N=6e6+5;
int c[N][2],s[N][2];
int typ,id=1,ans;
void ins(int v)
{
	int g=__lg(v);
	int u=1;
	for (int i=1;i<=g;i++)
	{
		int o=v>>g-i&1;
		if (!c[u][o]) c[u][o]=++id;
		u=c[u][o];
	}
	++s[u][typ];
}
int ids=1;
bool flg;
void dfs(int u)
{
	int i,j,v;
	if (v=c[u][0])
	{
		ids<<=1;
		dfs(v);
		if (flg) return;
		ids>>=1;
		for (i=0;i<2;i++) s[u][i]+=s[v][i];
	}
	if (v=c[u][1])
	{
		ids=ids<<1|1;
		dfs(v);
		if (flg) return;
		ids>>=1;
		if (s[v][1]>0)
		{
			cout<<"NO\n";
			flg=1;
			return;
		}
		s[u][0]+=s[v][0];
	}
	j=min(s[u][0],s[u][1]);
	s[u][0]-=j;
	s[u][1]-=j;
	ans+=s[u][0]+s[u][1];
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T;cin>>T;
	while (T--)
	{
		cout.flush();
		for (int i=1;i<=id;i++) c[i][0]=c[i][1]=s[i][0]=s[i][1]=0;
		flg=0;ids=id=1;ans=0;
		int n,i,j;
		cin>>n;
		vector<int> a(n),b(n),cnt(2);
		for (int &x:b)
		{
			cin>>x;typ=1;
			if (x) ins(x); else ++cnt[1];
		}
		for (int &x:a)
		{
			cin>>x;typ=0;
			if (x) ins(x); else ++cnt[0];
		}
		if (cnt[0]>cnt[1]) {cout<<"NO\n";continue;}
		dfs(1);if (flg) continue;
		cout<<"YES\n";
	}
}