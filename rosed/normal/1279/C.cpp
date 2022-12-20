#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
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
	int n,m,ret,bot;
	int a[N],pos[N];
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read(),m=read();
			ret=bot=0;
			for(int i=1;i<=n;++i) a[i]=read(),pos[a[i]]=i-1;
			for(int x,i=1;i<=m;++i)
			{
				x=read();
				if(pos[x]<bot) ++ret;
				else ret+=((pos[x]-i+1)<<1|1),bot=pos[x];
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