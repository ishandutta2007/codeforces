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
int t,n,ans,x,a[100001],b[100001],c[100001];
signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;i++)
			c[i]=read()-1;
		for(int i=1;i<=n;i++)
			a[i]=read();
		for(int i=1;i<=n;i++)
			b[i]=read();
		x=abs(a[2]-b[2]);
		ans=0;
		for(int i=2;i<n;i++)
		{
			x+=c[i]-abs(a[i+1]-b[i+1])+2;
			ans=max(ans,x+abs(a[i+1]-b[i+1]));
			if(b[i+1]==a[i+1])
			{
				ans=max(ans,x);
				x=0;
			}
			x=max(x,abs(b[i+1]-a[i+1]));
		}
		cout<<max(ans,x+2+c[n])<<endl;
	}
	return 0;
}