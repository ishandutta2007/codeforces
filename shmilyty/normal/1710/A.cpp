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
int t,n,m,k,a[100001];
void solve()
{
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=k;i++)
		a[i]=read();
	int res=0;
	for(int i=1;i<=k;i++)
	{
		if(a[i]/m>=2)
			res+=a[i]/m;
	}
	if(res>=n)
	{
		if(n&1)
		{
			for(int i=1;i<=k;i++)
				if(a[i]/m>2)
				{
					puts("Yes");
					return ;
				}
		}
		else
		{
			puts("Yes");
			return ;
		}
	}
	res=0;
	for(int i=1;i<=k;i++)
		if(a[i]/n>=2)
			res+=a[i]/n;
	if(res>=m)
	{
		if(m&1)
		{
			for(int i=1;i<=k;i++)
				if(a[i]/n>2)
				{
					puts("Yes");
					return ;
				}
		}
		else
		{
			puts("Yes");
			return ;
		}
	}
	puts("No");
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}