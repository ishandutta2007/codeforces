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
	const int N=2e5+10,p=998244353;
	int haku,n,ret;
	int a[N],c[N],sum,maxn,pos;
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read();maxn=pos=sum=0;
			for(int i=1;i<=n;++i)
			{
				a[i]=read();
				if(!c[a[i]]) ++sum;
				if(++c[a[i]]>maxn) maxn=c[a[i]],pos=a[i];
			}
			ret=max(min(sum-1,maxn),min(sum,maxn-1));
			printf("%lld\n",ret);
			for(int i=1;i<=n;++i) --c[a[i]];
		}
	}
}
signed main()
{
	red::main();
	return 0;
}