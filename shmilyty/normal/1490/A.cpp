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
int t,n,a[50],b,c;
signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		a[1]=read();
		int ans=0;
		for(int i=2;i<=n;i++)
		{
			a[i]=read();
			b=max(a[i],a[i-1]);
			c=min(a[i],a[i-1]);
			while(c*2<b)
			{
				ans++;
				c=c*2;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}