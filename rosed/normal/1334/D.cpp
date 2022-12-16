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
	const int N=1e5+10,inf=1<<30;
	int haku,n,l,r,pos;
	int a[N],s[N];
	inline void print(int x,int y,int f,int w)
	{
		
		if(w>r) return;
		if(w==r&&r==n*(n-1)+1)
		{
			printf("1");
			return;
		}
		if(f) printf("%lld ",x);
		else printf("%lld ",y);
		if(w==s[x]) print(x+1,x+2,1,w+1);
		else if(f==0) print(x,y+1,1,w+1);
		else print(x,y,0,w+1);
	}
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read(),l=read(),r=read();pos=n;
			for(int i=1;i<=n;++i)
			{
				a[i]=(n-i)*2;
				s[i]=s[i-1]+a[i];
				if(s[i]>=l&&pos==n) pos=i;
			}
			if(pos==n)
			{
				puts("1");
				continue;
			}
			int ll=l-s[pos-1];
			print(pos,pos+(ll+1)/2,ll&1,l);
			puts("");
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
3
4 1 13
5 1 21

*/