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
int t,n,a[101];
void solve()
{
	n=read();
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		int k=1;
		a[i]=read();
		for(int l=1;l<=100;l++)
			if(l*l==a[i])
			{
				k=0;
				break;
			} 
		if(k)
			ans=0;
	}
	if(ans)
		puts("No");
	else
		puts("Yes"); 
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}