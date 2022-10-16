#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int x=0,flag=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			flag=0;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
    return (flag?x:~(x-1));
}
int t,n,flag,a[200001],b[200001],c[200001];
signed main()
{
	t=read();
	while(t--)
	{
		flag=0;
		n=read();
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			b[i]=c[i]=0;
		}
		c[n+1]=0;
		for(int i=1;i<=n;i++)
			b[i]=a[i]>=b[i-1]&&b[i-1]!=-1?a[i]-b[i-1]:-1;
		for(int i=n;i>=1;i--)
			c[i]=a[i]>=c[i+1]&&c[i+1]!=-1?a[i]-c[i+1]:-1;
		if(!b[n])
		{
			puts("YES");
			continue;
		} 
		for(int i=1;i<n;i++)
			if(b[i-1]!=-1&&c[i+2]!=-1&&b[i-1]<=a[i+1]&&c[i+2]<=a[i]&&a[i+1]-b[i-1]==a[i]-c[i+2])
			{
				puts("YES");
				flag=1;
				break;
			}
		if(!flag)
			puts("NO");
	}
	return 0;
}