#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define eps (1e-6)
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
	const int N=2e5+10;
	int haku;
	int n,ret;
	int a[N];
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read();
			for(int i=1;i<=n*2;++i) a[i]=read();
			sort(a+1,a+n*2+1);
			ret=1e9+7;
			for(int i=1;i<=n;++i) ret=min(ret,a[n+1]-a[i]);
			for(int i=n+1;i<=2*n;++i) ret=min(ret,a[i]-a[n]);
			printf("%lld\n",ret);
		}
	}
}
signed main()
{

	red::main();
	return 0;
}