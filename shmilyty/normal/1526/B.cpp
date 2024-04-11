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
int t,n,cnt,a[20];
void work(int x,int y)
{
	for(int i=1;i<=y;i++)
	{
		if(a[i]<x)
		{
			a[i]+=10;
			a[i+1]--;
		}
		a[i]-=x;
	}
}
bool check()
{
	for(int i=1;i<=cnt;i++)
		if(a[i]<a[cnt])
			return 0;
	return 1;
}
void solve()
{
	n=read();
	int x=n%11;
	if(n>=111*x)
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