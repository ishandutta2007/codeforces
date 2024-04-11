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
const int mod=1e9+7;
int qp(int x,int y)
{
	int res=1;
	while(y)
	{
		if(y&1)
			(res*=x)%=mod;
		(x*=x)%=mod;
		y>>=1;
	}
	return res;
}
int n,m,ans1,ans2,msk[20],f[1010][1<<12];
std::vector<int> G[1010],G1[20],g[1010];
void dfs(int x,int fa)
{
	g[x].clear();
	for(int i:G[x])
		if(i!=fa)
		{
			g[x].push_back(i);
			dfs(i,x);
		}
}
void dfs1(int x,int fa)
{
	msk[x]=0;
	for(int i:G1[x])
		if(i!=fa)
		{
			msk[x]|=(1<<i);
			dfs1(i,x);
		}
}
int dfs2(int x,int id,int mk)
{
	// cout<<x<<" "<<id<<" "<<mk<<'\n';
	if(id==(int)(g[x].size()))
		return !mk;
	if(~f[g[x][id]][mk])
		return f[g[x][id]][mk];
	int &res=f[g[x][id]][mk];
	res=dfs2(x,id+1,mk);
	for(int i=0;i<m;i++)
		if((mk>>i)&1)
			(res+=dfs2(x,id+1,mk^(1<<i))*dfs2(g[x][id],0,msk[i]))%=mod;
	return res;
}
signed main()
{
	//fileio("trtr");
	n=read();
	for(int i=1;i<n;i++)
	{
		int x=read()-1,y=read()-1;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	m=read();
	for(int i=1;i<m;i++)
	{
		int x=read()-1,y=read()-1;
		G1[x].push_back(y);
		G1[y].push_back(x);
	}
	dfs(0,-1);
	for(int i=0;i<m;i++)
	{
		dfs1(i,-1);
		// for(int l=0;l<m;l++)
			// cout<<msk[l]<<" ";
		// cout<<'\n';
		// continue;
		// cout<<i<<'\n';
		memset(f,-1,sizeof(f));
		// cout<<i<<'\n';
		for(int l=0;l<n;l++)
			(ans1+=dfs2(l,0,msk[i]))%=mod;
	}
	// cout<<ans1<<'\n';
	n=m;
	for(int i=0;i<n;i++)
		G[i]=G1[i];
	dfs(0,-1);
	for(int i=0;i<m;i++)
	{
		dfs1(i,-1);
		memset(f,-1,sizeof(f));
		for(int l=0;l<n;l++)
			(ans2+=dfs2(l,0,msk[i]))%=mod;
	}
	cout<<ans1*qp(ans2,mod-2)%mod;
	return 0;
}