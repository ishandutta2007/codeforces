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
const int mod=998244353;
int t,n,m,k,in[300001],f[300001],num[300001];
vector<int> G[300001],v;
map<pair<int,int>,int> mp;
void dfs(int x,int d)
{
	if(in[x]>1||G[x].size()>1)
		return ;
	if(G[x].empty())
	{
		num[d]++;
		if(num[d]==1)
			v.push_back(d);
	}
	for(int i:G[x])
		dfs(i,d+1);
}
signed main()
{
	t=read();
	m=read();
	k=read();
	while(t--)
	{
		n=read();
		int x=read(),y;
		for(int i=1;i<n;i++)
		{
			y=read();
			if(!mp[{x,y}])
			{
				G[x].push_back(y);
				in[y]++;
				mp[{x,y}]=1;		
			}
			x=y;
		}
	}
	for(int i=1;i<=k;i++)
		if(!in[i])
			dfs(i,1);
	f[0]=1;
	for(int i=1;i<=m;i++)
		for(int l:v)
			if(i>=l)
				(f[i]+=f[i-l]*num[l])%=mod;
	cout<<f[m];
	return 0;
}