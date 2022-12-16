#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define fail return (void)puts("-1")
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();} 
		return f?x:-x;
	}
	const int N=3e5+10;
	int haku,n;
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read();
			if(n==1) puts("-1");
			else
			{
				putchar('2');
				for(int i=1;i<n;++i) putchar('3');
				puts("");
			}
		}
	}
}
signed main()
{
	red::main();
	return 0;
}