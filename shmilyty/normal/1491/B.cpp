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
int t,n,u,v,a[101];
signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		u=read();
		v=read();
		bool ok=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			if(i!=1&&abs(a[i]-a[i-1])>1)
				ok=1;
		}
		if(ok)
		{
			puts("0");
			continue;
		}
		for(int i=2;i<=n;i++)
			if(a[i]!=a[1])
			{
				ok=1;
				break;
			}
		if(ok==0)
		{
			cout<<min(u+v,v*2)<<endl;
			continue;
		}
		cout<<min(u,v)<<endl;
	}
	return 0;
}