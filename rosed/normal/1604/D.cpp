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
		int x=0;char f=0,ch;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=1,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	const int N=3e5+10,mod=998244353;
	int T,n,x,y;
	inline void main()
	{
		T=read();
		while(T--)
		{
			x=read(),y=read();
			if(x<=y)
			{
				int t1=y/x,t2=y%x;
				int q=t2/2;
				n=t1*x+q;
				printf("%lld\n",t1*x+q);
			}
			else
			{
				printf("%lld\n",x+y);
			}
		}
	}
}
signed main()
{
	red::main();
	return 0;
}