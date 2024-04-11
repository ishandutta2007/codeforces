#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define eps (1e-6)
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
	int haku;
	int n,m,a,b;
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read(),m=read(),a=read(),b=read();
			n=m-n;
			a=a+b;
			if(n%a) puts("-1");
			else printf("%lld\n",n/a);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}