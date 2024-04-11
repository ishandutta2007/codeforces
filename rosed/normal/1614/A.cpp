#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-12)
	inline int read()
	{
		int x=0;char ch,f=0;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=1,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	const int N=3e5+10,mod=998244353;
	int T,n,l,r,m,ans;
	int a[N];
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read(),l=read(),r=read(),m=read();ans=0;
			for(int i=1;i<=n;++i) a[i]=read();
			sort(a+1,a+n+1);
			for(int i=1;i<=n;++i)
			{
				if(a[i]<l||a[i]>r) continue;
				if(a[i]<=m) m-=a[i],++ans;
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