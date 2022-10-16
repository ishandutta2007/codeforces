#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
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
int T,n,k,a[200010];
std::vector<int> G[200010];
map<array<int,2>,int> mp;
void dfs(int x)
{
	for(int i:G[x])
	{
		a[i]+=a[x];
		dfs(i);
	}
}
int dfs1(int x,int y)
{
	if(G[x].empty())
		return y*a[x];
	if(mp.count({x,y}))
		return mp[{x,y}];
	vector<int> v;
	int tot=0,len=G[x].size();
	if(len==1)
		return mp[{x,y}]=dfs1(G[x][0],y);
	for(int i:G[x])
	{
		int X=dfs1(i,y/len),Y=dfs1(i,y/len+1);
		tot+=X;
		v.push_back(Y-X);
	}
	sort(ALL(v),greater<int>());
	for(int i=0;i<y%len;i++)
		tot+=v[i];
	return mp[{x,y}]=tot;
}
void solve()
{
	n=read();
	k=read();
	for(int i=1;i<=n;i++)
		G[i].clear();
	mp.clear();
	for(int i=2;i<=n;i++)
	{
		int x=read();
		G[x].push_back(i);
	}
	for(int i=1;i<=n;i++)
		a[i]=read();
	dfs(1);
	cout<<dfs1(1,k)<<'\n';
}
signed main()
{
	T=read();
	while(T--)
		solve();
	return 0;
}