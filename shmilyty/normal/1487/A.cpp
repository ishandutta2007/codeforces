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
signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		int ans=0,minn=114514114514114514;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			minn=min(minn,a[i]);
		}
		for(int i=1;i<=n;i++)
			if(a[i]!=minn)
				ans++;
		cout<<ans<<endl; 
	}
	return 0;
}