#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	bool flag=1;
	int x=0;
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
int t,n,a[100001];
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	if(n<3)
	{
		puts("0");
		return ;
	}
	int m=-1;
	for(int i=1;i+2<=n;i++)
		if(a[i+2]-a[i+1]!=a[i+1]-a[i])
		{
			m=abs((a[i+2]-a[i+1])-(a[i+1]-a[i]));
			break;
		}
	if(m==-1)
	{
		puts("0");
		return ;
	}
	for(int i=1;i<=n;i++)
		if(a[i]>=m)
		{
			puts("-1");
			return ;
		}
	int c=((a[2]-a[1])%m+m)%m;
	int cnt=a[1];
	for(int i=1;i<=n;i++)
	{
		if(cnt!=a[i])
		{
			puts("-1");
			return ;
		}
		(cnt+=c)%=m;
	}
	cout<<m<<" "<<c<<endl;
}
signed main()
{
	t=read();
	while(t--)
	{
		solve();
	}
	return 0;
}