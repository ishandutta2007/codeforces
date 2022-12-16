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
	const int N=1e6+10;
	int T,n,m,ans;
	int a,b,c,d;
	inline void main()
	{
		T=read();
		while(T--)
		{
			c=read(),d=read();
			
			if(!c&&!d) puts("0");
			else if(c==d) puts("1");
			else if(abs(c-d)%2==1) puts("-1");
			else puts("2");
		}
	}
}
signed main()
{
	red::main();
	return 0;
}