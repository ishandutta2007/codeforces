#include<bits/stdc++.h>
using namespace std;
namespace red{
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=2e5+10;
	int haku;
	int n;
	int a[N],b[N];
	int minn,pre;
	bool flag;
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read();
			for(int i=1;i<=n;++i) b[i]=read(),a[i]=b[i]-i;
			minn=a[1],pre=1;
			flag=0;
			for(int i=2;i<=n;++i)
			{
				if(a[i]-minn>0)
				{
					flag=1;
					puts("YES");
					printf("%d %d\n",pre,i);
					break;
				}
				if(a[i]<minn) minn=a[i],pre=i;
			}
			if(flag) continue;
			for(int i=1;i<=n;++i) a[i]=b[i]-(n-i);
			minn=a[n],pre=n;
			for(int i=n-1;i;--i)
			{
				if(a[i]-minn>0)
				{
					flag=1;
					puts("YES");
					printf("%d %d\n",i,pre);
					break;
				}
				if(a[i]<minn) minn=a[i],pre=i;
			}
			if(!flag) puts("NO");
		}
	}
}
signed main()
{
	red::main();
	return 0;
}