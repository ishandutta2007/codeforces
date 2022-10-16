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
int n,k,c[300001],pre[300001],d[300001],f[300001][2];
struct node{
	int x;
	bool operator<(const node& y)const
	{
		return d[x]>d[y.x];	
	}
};
multiset<node> s[300001];
vector<int> G[300001],G1[300001];
void dfs(int x,int fa=0)
{
	pre[x]=fa;
	for(int i:G[x])
		if(i!=fa)
		{
			d[i]=d[x]+1;
			dfs(i,x);
		}
}
void dfs1(int x,int fa=0)
{
	f[x][0]=1;
	for(int i:G1[x])
		if(i!=fa)
		{
			dfs1(i,x);
			f[x][1]=(f[x][1]*(f[i][0]+f[i][1])+f[x][0]*f[i][1])%mod;
			f[x][0]=f[x][0]*(f[i][0]+f[i][1])%mod;
		}
	if(x<=k)
	{
		f[x][1]=f[x][0];
		f[x][0]=0;
	}
}
signed main()
{
	n=read();
	k=read();
	for(int i=1;i<=n;i++)
		c[i]=read();
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1);
	for(int i=1;i<=n;i++)
		if(c[i])
			s[c[i]].insert({i});
	for(int i=1;i<=k;i++)
		while(s[i].size()>1)
		{
			int x=(*s[i].begin()).x;
			s[i].erase(s[i].begin());
			if(!c[pre[x]])
			{
				c[pre[x]]=i;
				s[i].insert({pre[x]});
			}
			if(c[pre[x]]!=i)
			{
				puts("0");
				return 0; 
			}
		}
	for(int i=1,tot=k;i<=n;i++)
		if(!c[i])
			c[i]=++tot;
	for(int i=1;i<=n;i++)
		for(int l:G[i])
			if(c[i]!=c[l])
				G1[c[i]].push_back(c[l]);
	dfs1(1);
	cout<<f[1][1];
	return 0;
}