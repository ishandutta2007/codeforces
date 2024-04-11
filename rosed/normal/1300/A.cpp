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
	const int N=110;
	int haku;
	int n,sum,ret;
	int a[N];
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read();
			ret=sum=0;
			for(int i=1;i<=n;++i)
			{
				a[i]=read();
				if(!a[i]) ++a[i],++ret;
				sum+=a[i];
			}
			if(!sum) ++ret;
			printf("%lld\n",ret);
		}
	}
}
signed main()
{

	red::main();
	return 0;
}