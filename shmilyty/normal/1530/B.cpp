#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
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
int t,n,m,a[21][21];
void solve()
{
	n=read();
	m=read();
	memset(a,0,sizeof(a));
	int x=1,y=1;
	for(;y<=m;y+=2)
		a[x][y]=1;
	x=3;
	y=m;
	for(;x<=n;x+=2)
		a[x][y]=1;
	x=n;
	y=m-2;
	for(;y>0;y-=2)
		a[x][y]=1;
	y=1;
	x=n-2;
	for(;x>2;x-=2)
		a[x][y]=1;
	for(int i=1;i<=n;i++)
	{
		for(int l=1;l<=m;l++)
			cout<<a[i][l];
		cout<<endl;
	}
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}