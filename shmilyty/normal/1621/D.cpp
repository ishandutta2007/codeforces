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
int t,n,ans,c[501][501],f[501][501];
int area(int x,int y,int xx,int yy)
{
	if(x>xx||y>yy)
		return 0;
	return f[xx][yy]+f[x-1][y-1]-f[x-1][yy]-f[xx][y-1];
}
void solve()
{
	n=read();
	for(int i=1;i<=2*n;i++)
		for(int l=1;l<=2*n;l++)
			c[i][l]=read();
	ans=0;
	for(int i=n+1;i<=2*n;i++)
		for(int l=n+1;l<=2*n;l++)
			ans+=c[i][l];
	cout<<ans+min({c[1][n*2],c[n*2][1],c[n*2][n],c[1][n+1],c[n+1][1],c[n][n*2],c[n][n+1],c[n+1][n]})<<endl; 
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}