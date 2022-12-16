#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
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
	const int N=1e5+10,mod=1e9+7;
	int haku;
	int n;
	int a,b,x,y,ret;
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			ret=0;
			a=read()-1,b=read()-1,x=read(),y=read();
			ret=max(ret,x*(b+1));
			ret=max(ret,(a-x)*(b+1));
			ret=max(ret,(a+1)*y);
			ret=max(ret,(a+1)*(b-y));
			printf("%lld\n",ret);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}