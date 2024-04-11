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
	const int N=4e5+10;
	int haku;
	int x,y,n,m,ans;
	int u,v,w;
	inline void main()
	{
		v=5,u=v+1,w=v+1;
		x=read(),y=read();
		if(x>y||(y-x)&1)
		{
			puts("-1");
			return;
		}
		else
		{
			if(x==y)
			{
				if(!x) puts("0");
				else printf("1\n%lld\n",x);
			}
			else
			{
				int t=(y-x)>>1;
				if(!(x&t)) printf("2\n%lld %lld\n",x|t,t);
				else printf("3\n%lld %lld %lld\n",x,t,t);
			}
		}
	}
}
signed main()
{
	red::main();
	return 0;
}