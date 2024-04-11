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
int t,n;
void solve()
{
	n=read();
	int x=sqrt(n/4);
	if(x*x*4==n)
	{
		puts("YES");
		return ;
	}
	x=sqrt(n/2);
	if(x*x*2==n)
	{
		puts("YES");
		return ;
	}
	puts("NO");
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}