#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
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
int t,a,b,c,d;
void solve()
{
	a=read();
	b=read();
	c=read();
	if(a>b)
		swap(a,b);
	int n=2*(b-a);
	if(c>n||a>n||b>n)
	{
		puts("-1");
		return ;
	}
	if(c<=n/2)
		d=c+b-a;
	else
		d=c-(b-a);
	if(d==a||d==b||d>n||d<0)
	{
		puts("-1");
		return ;
	}
	cout<<d<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}