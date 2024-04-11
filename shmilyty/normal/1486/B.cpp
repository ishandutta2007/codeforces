#pragma GCC optimize ("Ofast")//1
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
int t,n,ans,minn,x[1001],y[1001];
signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;i++)
		{
			x[i]=read();
			y[i]=read();
		}
		if(n&1)
			puts("1");
		else
		{
			sort(x+1,x+1+n);
			sort(y+1,y+1+n);
			cout<<(x[n/2+1]-x[n/2]+1)*(y[n/2+1]-y[n/2]+1)<<endl;
		}
	}
	return 0;
}