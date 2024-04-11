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
int t,n,ans;
signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		ans=0;
		for(int i=3;i<=n+1;i++)
			ans+=(n-i/2)*(n-i/2);
		printf("%lld\n%lld ",ans,n/2+1);
		for(int i=1;i<n/2;i++)
			printf("%lld ",i);
		for(int i=n/2+2;i<=n;i++)
			printf("%lld ",i);
		printf("%lld\n%lld\n",n/2,n-1);
		for(int i=n/2;i>=2;i--)
			printf("%lld %lld\n",i,n);
		for(int i=n/2+1;i<=n;i++)
			printf("%lld %lld\n",i,1ll);
	}
	return 0;
}