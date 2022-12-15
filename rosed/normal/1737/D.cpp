#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-8)
const int inf=1e15;
void solve()
{
	int n,m;
	cin>>n>>m;
	vector f(n+1,vector<int>(n+1,inf));
	vector g(n+1,vector<int>(n+1,inf));
	typedef array<int,3> node;
	vector<node> a(m+1);
	vector<int> minn(n+1,inf);
	for(int i=1;i<=n;++i) g[i][i]=0;
	for(int i=1;i<=m;++i)
	{
		int x,y,z;
		cin>>x>>y>>z;
		a[i]=node{x,y,z};
		g[x][y]=g[y][x]=1;
		minn[x]=min(minn[x],z);
		minn[y]=min(minn[y],z);
	}
	for(int k=1;k<=n;++k)
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	int ans=1e18;
	
	for(int i=1;i<=m;++i)
	{
		ans=min(ans,(g[1][a[i][0]]+g[a[i][1]][n]+1)*a[i][2]);
		ans=min(ans,(g[1][a[i][1]]+g[a[i][0]][n]+1)*a[i][2]);
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			ans=min(ans,(g[i][j]+g[1][j]+g[j][n]+2)*minn[i]);
		}
	}
	cout<<ans<<'\n';
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1;cin>>T;
	while(T--) solve();
	return 0;
}