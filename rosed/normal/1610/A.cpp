#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
	inline int read()
	{
		int x=0;char ch,f=0;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=1,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	const int N=3e5+10;
	int T,n,m;
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read(),m=read();
			if(n==1&&m==1) puts("0");
			else if(n==1||m==1) puts("1");
			else puts("2");
		}
	}
}
signed main()
{
	red::main();
	return 0;
}