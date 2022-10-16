#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
int t,n,q[200001],a[200001];
vector<pair<int,int>> v[2];
string s;
void solve()
{
	n=read();
	v[0].clear();
	v[1].clear();
	for(int i=1;i<=n;i++)
		a[i]=read();
	cin>>s;
	for(int i=1;i<=n;i++)
		v[s[i-1]-'0'].push_back({a[i],i});
	sort(ALL(v[0]));
	sort(ALL(v[1]));
	for(auto i:v[1])
		v[0].push_back(i);
	int cnt=0;
	for(auto i:v[0])
		q[i.second]=++cnt;
	for(int i=1;i<=n;i++)
		cout<<q[i]<<" ";
	cout<<'\n';
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}