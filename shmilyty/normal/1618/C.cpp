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
int t,n,a[101],g[2];
bool check(int x)
{
	for(int i=1;i<=n;i++)
		if((i&1)!=x)
			if(a[i]%g[x]==0)
				return 0;
	return 1;
}
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	if(n==1)
	{
		puts("1");
		return ;
	}
	g[0]=g[1]=0;
	for(int i=1;i<=n;i++)
		g[i&1]=__gcd(g[i&1],a[i]);
	for(int i=0;i<2;i++)
		if(check(i))
		{
			cout<<g[i]<<endl;
			return ;
		}
	puts("0");
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}