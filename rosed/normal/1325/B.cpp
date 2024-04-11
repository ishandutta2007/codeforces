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
	const int N=4e5+10;
	int haku;
	int a[N],f[N],pre[N];
	int n,m,ans;
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read();ans=0;
			for(int i=1;i<=n;++i) a[i]=read();
			sort(a+1,a+n+1);
			f[0]=0;
			for(int i=1;i<=n;++i)
			{
				if(a[i]!=a[i-1]) pre[i]=i-1;
				else pre[i]=pre[i-1];
				f[i]=f[pre[i]]+1;
				ans=max(ans,f[i]);
			}
			printf("%lld\n",ans);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}