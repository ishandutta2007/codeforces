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
int t,n,f[20];
void solve()
{
	n=read();
	int ans=0;
	if(n%2050)
	{
		puts("-1");
		return ;
	}
	ans=n/2050;
	int num=0;
	while(ans)
	{
		num+=ans%10;
		ans/=10;
	}
	cout<<num<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}