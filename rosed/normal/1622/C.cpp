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
	int T,n,k,ret;
	int a[N],sum,suf[N];
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read(),k=read();sum=0;
			for(int i=1;i<=n;++i) a[i]=read(),sum+=a[i];
			ret=sum-k;
			if(sum<=k)
			{
				puts("0");
				continue;
			}
			sort(a+1,a+n+1);
			suf[n]=a[n];
			for(int i=n-1;i;--i) suf[i]=suf[i+1]+a[i];
			for(int ans,tot,d,i=2;i<=n;++i)
			{
				ans=d=n-i+1;
				tot=sum-(suf[i]-a[1]*d);
				int cf=ceil(1.0*(tot-k)/(d+1));
				cf=max(cf,0ll);
				ret=min(ret,ans+cf);
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
/*

*/