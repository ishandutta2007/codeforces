#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=1e5+10,p=1e9+7;
	int haku,x,y,a,b,ret;
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			x=read(),y=read(),a=read(),b=read(),ret=0;
			if(b<2*a)
			{
				int t=min(x,y);
				ret=t*b;
				x-=t,y-=t;
			}
			ret+=(x+y)*a;
			printf("%lld\n",ret);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}