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
int T,n,m,ans,dis1[501][501],dis2[501][501],vis[501];
queue<int> q;
std::vector<array<int,2>> G[501];
void solve()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
		G[i].clear();
	memset(dis1,0x3f,sizeof(dis1));
	memset(dis2,0x3f,sizeof(dis2));
	for(int i=1;i<=n;i++)
		dis1[i][i]=dis2[i][i]=0;
	while(m--)
	{
		int x=read(),y=read(),z=read();
		dis1[x][y]=dis1[y][x]=1;
		dis2[x][y]=dis2[y][x]=min(z,dis2[x][y]);
	}
	for(int i=1;i<=n;i++)
		for(int l=1;l<=n;l++)
			for(int j=1;j<=n;j++)
				dis1[l][j]=min(dis1[l][i]+dis1[i][j],dis1[l][j]);
	ans=INF;
	for(int i=1;i<=n;i++)
		for(int l=1;l<=n;l++)
			if(i!=l&&dis2[i][l]<dis2[0][0])
			{
				// cout<<i<<" "<<l<<" "<<dis2[i][l]<<'\n';
				ans=min(ans,(dis1[1][i]+1+dis1[l][n])*dis2[i][l]);
				for(int j=1;j<=n;j++)
					ans=min(ans,dis2[i][l]*(dis1[1][j]+dis1[j][n]+dis1[j][i]+2));
			}
	cout<<ans<<'\n';
}
signed main()
{
	T=read();
	while(T--)
		solve();
	return 0;
}