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
	const int N=1e5+10;
	int haku;
	int n;
	int a[N],y,sum,tmp,t=2e15;
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read();
			sum=y=0;
			for(int i=1;i<=n;++i) a[i]=read(),y^=a[i],sum+=a[i];
			if(y*2==sum)
			{
				puts("0");
				puts("");
				continue;
			}
			puts("3");
			tmp=4e15-sum-(t^y);
			tmp>>=1;
			printf("%lld %lld %lld\n",t^y,tmp,tmp);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}