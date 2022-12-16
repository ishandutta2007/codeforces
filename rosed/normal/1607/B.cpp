#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-12)
	inline int read()
	{
		int x=0;char ch,f=0;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=1,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	const int N=3e5+10,mod=998244353;
	int T,x,n;
	inline void main()
	{
		T=read();
		while(T--)
		{
			x=read(),n=read();
			if(x%2==0)
			{
				int m=n/4*4+1;
				for(int i=m;i<=n;++i)
				{
					if(x%2==0) x-=i;
					else x+=i;
				}
				printf("%lld\n",x);
			}
			else
			{
				int m=n/4*4+1;
				for(int i=m;i<=n;++i)
				{
					if(x%2==0) x-=i;
					else x+=i;
				}
				printf("%lld\n",x);
			}
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
// 1 +1 -2 -3  +4