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
int t,n,a[100001],b[100001],c[100001];
signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			b[i]=read();
		}
		for(int i=1;i<=n;i++)
			c[i]=read();
		int now=0;
		for(int i=1;i<n;i++)
		{
			now+=a[i]-b[i-1]+c[i];
			now=max(now+(b[i]-a[i]+1)/2,b[i]);
		}
		cout<<now+a[n]-b[n-1]+c[n]<<endl;
	}
	return 0;
}