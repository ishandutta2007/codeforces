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
unordered_map<int,int> mp[2][801];
int n,k,cnt,ans,a[4001][4001],f[4001],g[4001];
int sum(int x,int y)
{
	return a[x][x]-a[x][y]-a[y][x]+a[y][y];
}
void solve(int l,int r,int ll,int rr)
{
	if(l>r)
		return ;
	int mid=(l+r)>>1,c;
	f[mid]=INF;
	for(int i=ll;i<=rr;i++)
		if(f[mid]>g[i]+sum(mid,i))
		{
			f[mid]=g[i]+sum(mid,i);
			c=i;
		}
	solve(l,mid-1,ll,c);
	solve(mid+1,r,c,rr);
}
signed main()
{
	n=read();
	k=read();
	for(int i=1;i<=n;i++)
		for(int l=1;l<=n;l++)
			a[i][l]=a[i][l-1]+a[i-1][l]-a[i-1][l-1]+read();
	for(int i=1;i<=n;i++)
		g[i]=INF;
	while(k--)
	{
		solve(1,n,0,n);
		for(int i=0;i<=n;i++)
			g[i]=f[i];
	}
	cout<<f[n]/2;
	return 0;
}