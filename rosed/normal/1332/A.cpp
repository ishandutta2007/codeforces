#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define y1 qwq 
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=3e5+10,p=1e9+7;
	int haku;
	int a,b,c,d;
	int x,y,x1,x2,y1,y2;
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			a=read(),b=read(),c=read(),d=read();
			x=read(),y=read(),x1=read(),y1=read(),x2=read(),y2=read();
			if((a||b)&&(x==x1)&&(x==x2))
			{
				
				puts("No");
				continue;
			}
			if((c||d)&&(y==y1)&&(y==y2))
			{
				puts("No");
				continue;
			}
			if(a>b) a-=b,b=0; else b-=a,a=0;
			if(c>d) c-=d,d=0; else d-=c,c=0;
			if(a>x-x1||b>x2-x||c>y-y1||d>y2-y) puts("No");
			else puts("Yes");
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
6
5 1 1 1
0 0 -100 -100 0 100

1 1 5 1
0 0 -100 -100 100 0

*/