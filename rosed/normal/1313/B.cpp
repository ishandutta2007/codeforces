#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();} 
		return f?x:-x;
	}
	const int N=1e5+10,p=998244353;
	int haku;
	int n,x,y,z;
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read(),x=read(),y=read();
			if(x==1&&y==1)
			{
				puts("1 1");
				continue;
			}
			if(x==n&&y==n)
			{
				printf("%lld %lld\n",n,n);
				continue;
			}
			z=x+y;
			if(x>y) swap(x,y);
			int sum1=0,sum2=0;
			sum1=max(1ll,z-n+1);
			sum2=min(z-1,n);
			printf("%lld %lld\n",sum1,sum2);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
1
5 5 1

*/