#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
	inline int read()
	{
		int x=0;char ch,f=0;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=1,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	const int N=3e5+10,mod=1e9+7;
	int T,n,sum2,sum4,ans;
	int a[N],pw[51];
	int fac[N],inv[N];
	int bit[51],suf[51];
	inline int fast(int x,int k)
	{
		int ret=1;
		while(k)
		{
			if(k&1) ret=ret*x%mod;
			x=x*x%mod;
			k>>=1;
 		}
 		return ret;
	}
	inline int C(int n,int m)
	{
		if(n<m) return 0;
		return fac[n]*inv[m]%mod*inv[n-m]%mod;
	}
	inline void main()
	{
		n=read();ans=fast(2,n)-1;
		fac[0]=inv[0]=pw[0]=1;
		for(int i=1;i<=50;++i) pw[i]=pw[i-1]*2;
		for(int i=1;i<=n;++i) fac[i]=fac[i-1]*i%mod;
		inv[n]=fast(fac[n],mod-2);
		for(int i=n-1;i;--i) inv[i]=inv[i+1]*(i+1)%mod;
		for(int i=1;i<=n;++i)
		{
			a[i]=read();int x=0;
	//		if((a[i]&1)==0) --ans;
			while((a[i]&1)==0) a[i]>>=1,++x;
			++bit[x];
		}
//		for(int i=1;i<=n;++i)
//		{
//			for(int j=i+1;j<=n;++j)
//			{
//				int x=(1+a[i])*a[i]/2+(1+a[j])*a[j]/2;
//				if(x%__gcd(a[i],a[j])!=0) --ans;
//			}
//		}
		for(int i=50;i;--i) suf[i]=suf[i+1]+bit[i];
		for(int i=1;i<50;++i)
		{
			if(!bit[i]) continue;
			int x=0;
			for(int k=1;k<=bit[i];k+=2)
			{
				x=(x+C(bit[i],k))%mod;
			}
			ans-=x*fast(2,suf[i+1])%mod;
			ans=(ans+mod)%mod;
		}
		ans=(ans+mod)%mod;
		printf("%lld\n",ans);
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
5
1 1 2 4 8

*/