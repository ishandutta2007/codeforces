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
int t,n,a[40002],ans[40001];
void solve()
{
	n=read();
	int s=0,tot=n*(n+1)/2;
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
		s+=a[i];
	if(s%tot)
	{
		puts("No");
		return ;
	}
	s/=tot;
	if(s<n)
	{
		puts("No");
		return ;
	}
	a[0]=a[n];
	for(int i=1;i<=n;i++)
	{
		if((s+a[i-1]-a[i])%n)
		{
			puts("No");
			return ;
		}
		ans[i]=(s-a[i]+a[i-1])/n;
		if(ans[i]<=0)
		{
			puts("No");
			return ;
		}
	}
	puts("Yes");
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}