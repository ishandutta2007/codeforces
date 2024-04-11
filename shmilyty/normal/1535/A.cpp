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
int t,a[5];
void solve()
{
	for(int i=1;i<=4;i++)
		a[i]=read();
	int x=max(a[1],a[2])*max(a[3],a[4]);
	sort(a+1,a+5);
	if(x==a[3]*a[4])
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