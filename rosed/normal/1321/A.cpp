#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
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
	int n,m,ret;
	int a[N],b[N];
	int flag;
	inline void main()
	{
		n=read();
		for(int i=1;i<=n;++i) a[i]=read();
		for(int i=1;i<=n;++i) b[i]=read();
		for(int i=1;i<=n;++i)
		{
			if(!a[i]&&b[i]) ++ret;
			if(a[i]&&!b[i]) ++flag;
		}
		if(!flag) {puts("-1");return;}
		++ret;
		ret=(ret-1)/flag+1;
		printf("%lld\n",ret);
	}
}
signed main()
{
	red::main();
	return 0;
}