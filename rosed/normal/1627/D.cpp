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
	const int N=1e6+10,mod=998244353;
	int T;
	int n,ans;
	int a[N],pos[N];
	bool vis[N];
	inline void main()
	{
		n=read();
		for(int i=1;i<=n;++i) a[i]=read(),vis[a[i]]=1;
		for(int i=1e6;i;--i)
		{
			if(vis[i]) continue;
			int g=0;
			for(int j=i*2;j<=1e6;j+=i)
			{
				if(vis[j]) g=__gcd(g,j);
			}
			if(g==i) {vis[i]=1;++ans;}
		}
		printf("%lld\n",ans);
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
6 36 72

*/