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
	const int N=1e5+10;
	int haku;
	int n;
	int a[N],b[N];
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read();
			for(int i=1;i<=n;++i) a[i]=read();
			sort(a+1,a+n+1);
			for(int i=1;i<=n;++i) b[i]=read();
			sort(b+1,b+n+1);
			for(int i=1;i<=n;++i) printf("%lld ",a[i]);
			puts("");
			for(int i=1;i<=n;++i) printf("%lld ",b[i]);
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

*/