#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long 
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
	inline int read()
	{
		int x=0;char ch,f=0;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=1,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	const int N=3e5+10,mod=998244353;
	int T,n,ans,sum;
	int a[N];
	inline void check(int l,int r)
	{
		sum=0;
		double d=1.0*(a[r]-a[l])/(r-l),st=a[l]-d*(l-1);
		for(int i=1;i<=n;++i)
		{
			if(fabs(a[i]-st)>eps) ++sum;
			st+=d;
		}
		ans=min(ans,sum);
	}
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read();ans=n;
			if(n<=2) ans=0;
			for(int i=1;i<=n;++i) a[i]=read();
			for(int l=1;l<=n;++l)
			{
				for(int r=l+1;r<=n;++r)
				{
					check(l,r);
				}
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