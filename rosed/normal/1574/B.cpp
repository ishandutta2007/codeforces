#include<bits/stdc++.h>
using namespace std;
namespace red{
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
	const int N=1e5+10;
	int T,a,b,c,m,x,y;
	inline void main()
	{
		T=read();
		while(T--)
		{
			a=read(),b=read(),c=read(),m=read();
			if(a>b) swap(a,b);
			if(b>c) swap(b,c);
			if(a>b) swap(a,b);
			x=max(0,c-a-b-1);
			y=max(0,a+b+c-3);
			if(x<=m&&m<=y) puts("YES");
			else puts("NO");	
		}
	}
}
signed main()
{
	red::main();
	return 0;
}