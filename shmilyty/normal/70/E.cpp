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
int n,k,d[181],dis[181][181],f[181][181],g[181],ans[181];
vector<int>G[181];
void dfs(int x,int fa,int rt)
{
	for(int i:G[x])
		if(i!=fa)
		{
			dis[rt][i]=dis[rt][x]+1;
			dfs(i,x,rt);
		}
}
void dfs1(int x,int fa)
{
	for(int i=1;i<=n;i++)
		f[x][i]=d[dis[x][i]]+k;
	for(int i:G[x])
		if(i!=fa)
		{
			dfs1(i,x);
			for(int l=1;l<=n;l++)
				f[x][l]+=min(f[i][g[i]],f[i][l]-k);
		}
	g[x]=1;
	for(int i=2;i<=n;i++)
		if(f[x][i]<f[x][g[x]])
			g[x]=i;
}
void getans(int x,int fa,int pos)
{
	for(int i:G[x])
		if(i!=fa)
		{
			ans[i]=(f[i][g[i]]>f[i][pos]-k?pos:g[i]);
			getans(i,x,ans[i]);
		}
}
signed main()
{
	n=read();
	k=read();
	for(int i=1;i<n;i++)
		d[i]=read();
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		dfs(i,0,i);
	dfs1(1,0);
	cout<<f[1][g[1]]<<'\n';
	ans[1]=g[1];
	getans(1,0,ans[1]);
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	return 0;
}