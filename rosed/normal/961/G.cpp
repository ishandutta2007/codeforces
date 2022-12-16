#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=2e5+10,p=1e9+7;
	int n,k,ans,sum;
	int inv[N],fac[N],ifac[N];
	inline void init(int n)
	{
		inv[1]=1;
  		for(int i=2;i<=n;++i) inv[i]=(-(p/i)*inv[p%i]%p+p)%p;
  		fac[0]=ifac[0]=1;
		for(int i=1;i<=n;++i) fac[i]=fac[i-1]*i%p,ifac[i]=ifac[i-1]*inv[i]%p;
	}
	inline int fast(int x,int k)
	{
		if(k<0) return 1;
		int ret=1;
		while(k)
		{
			if(k&1) ret=ret*x%p;
			x=x*x%p;
			k>>=1;
		}
		return ret;
	}
	inline int C(int n,int m)
	{
		if(n<m) return 0;
		return fac[n]*ifac[m]%p*ifac[n-m]%p;
	}
	inline void main()
	{
		n=read(),k=read();
		init(k);
		for(int i=1;i<=n;++i) sum=(sum+read())%p;
		for(int tmp,i=0;i<k;++i)
		{
			tmp=fast(k-i,n-2)*ifac[i]%p*ifac[k-i-1]%p*(k-i+n-1)%p;
			if(i&1) tmp=-tmp;
			ans=(ans+tmp+p)%p;
		}
		printf("%lld\n",ans*sum%p);
	}
}
signed main()
{
	red::main();
	return 0;
}