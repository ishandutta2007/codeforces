#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
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
int t,n;
void solve()
{
	n=read();
	int cnt=0,tot=1;
	while(tot<n)
	{
		cnt++;
		tot*=2;
	}
	if(tot==n&&(cnt&1))
		if(cnt&1)
		{
			puts("Bob");
			return ;
		}
	if(n&1)
		puts("Bob");
	else
		puts("Alice");
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}