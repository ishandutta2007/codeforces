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
int t,n,k,a[100001];
void solve()
{
	n=read();
	k=read();
	for(int i=n-k+1;i<=n;i++)
		a[i]=read();
	if(k==1)
	{
		puts("YES");
		return ;
	}
	for(int i=n;i>n-k+1;i--)
	{
		a[i]-=a[i-1];
		if(i!=n&&a[i]>a[i+1])
		{
			puts("NO");
			return ;
		}
	}
	int s=a[n-k+1];
	s-=(n-k)*a[n-k+2];
	if(s<=a[n-k+2])
		puts("YES");
	else
		puts("NO");
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}