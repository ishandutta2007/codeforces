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
	const int N=1e5+10;
	int T;
	int l,r;
	inline void main()
	{
		T=read();
		while(T--)
		{
			l=read(),r=read();
			int a=(r+1)/2;
			if(a>=l) printf("%lld\n",a-1);
			else printf("%lld\n",r%l); 
		} 
	}
}
signed main()
{
	red::main();
	return 0;
}
//90 103 99 83 102 70 86 70 99 71