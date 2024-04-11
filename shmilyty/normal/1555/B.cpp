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
int t,n,m,n1,m1,x1,x,y1,y,n2,m2;
void solve()
{
	n=read();
	m=read();
	x1=read(),y1=read(),x=read(),y=read();
	n1=x-x1,m1=y-y1;
	n2=read();
	m2=read();
	if(n1+n2>n&&m1+m2>m)
	{
		puts("-1");
		return ;
	}
	int ans=INF;
	if(n1+n2<=n)
	{
		ans=min(ans,max(0ll,n2-x1));
		ans=min(ans,max(0ll,x-(n-n2)));
	}
	if(m1+m2<=m)
	{
		ans=min(ans,max(0ll,m2-y1));
		ans=min(ans,max(0ll,y-(m-m2)));
	}
	cout<<ans<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}