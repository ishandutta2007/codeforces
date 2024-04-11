#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long 
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
	inline int read()
	{
		int x=0;char ch,f=0;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=1,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	const int N=3e5+10,mod=998244353;
	int T,n,m,dx,dy;
	int stx,sty,edx,edy;
	int sum;
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read(),m=read();sum=0;
			stx=read(),sty=read(),edx=read(),edy=read();
			dx=dy=1;
			int x=stx,y=sty;
			while(x!=edx&&y!=edy)
			{
				if(x+dx<1||x+dx>n) dx=-dx;
				if(y+dy<1||y+dy>m) dy=-dy;
				x+=dx,y+=dy;
				++sum;
			}
			printf("%lld\n",sum);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}