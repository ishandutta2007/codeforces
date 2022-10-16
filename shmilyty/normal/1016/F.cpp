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
int n,m,c,tot,top,ans,stk[300001],dis[300001][2],ok[300001],f[300001];
vector<array<int,2>> G[300001];
vector<int> v;
void dfs(int x,int fa)
{
	for(auto i:G[x])
		if(i[0]!=fa)
		{
			dis[i[0]][c]=dis[x][c]+i[1];
			dfs(i[0],x);
		}
}
void dfs1(int x,int fa)
{
	v.push_back(x);
	bool flag=1;
	for(auto i:G[x])
		if(i[0]!=fa)
		{
			if(ok[i[0]])
				dfs1(i[0],x);
			else
			{
				f[x]=i[1];
				tot+=flag;
				flag=0;
			}
		}
}
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read(),z=read();
		G[x].push_back({y,z});
		G[y].push_back({x,z});
	}
	dfs(1,0);
	c=1;
	dfs(n,0);
	for(int i=1;i<=n;i++)
		if(dis[i][0]+dis[i][1]==dis[n][0])
		{
			ok[i]=1;
			tot++;
		}
	dfs1(1,0);
	if(tot!=n)
	{
		while(m--)
			cout<<dis[n][0]<<'\n';
		return 0;
	}
	if(f[1]||f[v[1]])
		ans=max(ans,dis[1][0]+f[1]+f[v[1]]+dis[n][0]-dis[v[1]][0]);
	stk[++top]=1;
	for(int i=2;i<v.size();i++)
	{
		ans=max(ans,dis[stk[1]][0]+f[stk[1]]+f[v[i]]+dis[n][0]-dis[v[i]][0]);
		if(f[v[i]]||f[v[i-1]])
			ans=max(ans,dis[v[i-1]][0]+f[v[i]]+f[v[i-1]]+dis[n][0]-dis[v[i]][0]);
		while(top&&f[stk[top]]+dis[stk[top]][0]<=f[v[i]]+dis[v[i-1]][0])
			top--;
		stk[++top]=v[i-1];
	}
	while(m--)
		cout<<min(ans+read(),dis[n][0])<<'\n';
	return 0;
}