#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
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
int t,a,b,n;
void solve()
{
	n=read();
	a=read();
	b=read();
	if((n-1)%b==0)
	{
		puts("Yes");
		return ;
	}
	if(a==1)
	{
		puts("No");
		return ;
	}
	int cnt=a;
	while(cnt<=n)
	{
		if((n-cnt)%b==0)
		{
			puts("Yes");
			return ;
		}
		cnt*=a;
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