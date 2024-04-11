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
int t,n,m,x,y,xx,yy,t1,t2;
void solve()
{
	n=read();
	m=read();
	x=read();
	y=read();
	xx=read();
	yy=read();
	t1=t2=1;
	int ans=0;
	while(x!=xx&&y!=yy)
	{
		if(x+t1==n+1||x+t1==0)
			t1=-t1;
		if(y+t2==m+1||y+t2==0)
			t2=-t2;
		x+=t1;
		y+=t2;
		ans++;
	}
	cout<<ans<<'\n';
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}