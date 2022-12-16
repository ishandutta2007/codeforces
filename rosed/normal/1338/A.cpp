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
	int haku;
	int n,ans,ret,maxn;
	int a[N];
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read();ans=maxn=ret=0;
			for(int i=1;i<=n;++i) a[i]=read();
			maxn=a[1];
			for(int i=2;i<=n;++i)
			{
				ans=max(ans,maxn-a[i]);
				maxn=max(maxn,a[i]);
			}
			while(ans)
			{
				ans>>=1;
				++ret;
			}
			printf("%lld\n",ret);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}