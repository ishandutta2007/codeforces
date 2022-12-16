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
	int a[N],maxn,n,m,ret,sum,pre;
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read(),m=read();
			maxn=ret=sum=pre=0;
			for(int i=1;i<=n;++i) a[i]=read(),sum+=a[i];
			if(sum<=m)
			{
				puts("0");
				continue;
			}
			sum=0;
			for(int i=1;i<=n;++i)
			{
				sum+=a[i];
				if(a[i]>maxn)
				{
					sum+=maxn;
					maxn=a[i];
					sum-=maxn;
					ret=i;
				}
				if(sum>m) break;
				pre=ret;
			}
			printf("%lld\n",pre);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}