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
int n,k,f[101][102],g[101];
vector<int> G[101];
const int mod=1e9+7;
void dfs(int x,int fa)
{
	f[x][0]=f[x][k+1]=1;
	for(int i:G[x])
		if(i!=fa)
		{
			dfs(i,x);
			fill(g,g+2*k+2,0);
			for(int l=0;l<=2*k;l++)
				for(int j=0;j<=2*k;j++)
					(g[(l+j)<=2*k?min(l,j+1):max(l,j+1)]+=f[x][l]*f[i][j]%mod)%=mod;
			for(int l=0;l<=2*k;l++)
				f[x][l]=g[l];
		}
}
signed main()
{
	n=read();
	k=read();
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1,0);
	int ans=0;
	for(int i=0;i<=k;i++)
		(ans+=f[1][i])%=mod;
	cout<<ans; 
	return 0;
}