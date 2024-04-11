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
	const int N=3e5+10,p=998244353;
	int n,m,ret;
	int fac[N],inv[N];
	inline int fast(int x,int k)
	{
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
		return fac[n]*inv[n-m]%p*inv[m]%p;
	}
	inline void main()
	{
		n=read(),m=read();
		for(int i=fac[0]=1;i<=m;++i) fac[i]=fac[i-1]*i%p;
		inv[m]=fast(fac[m],p-2);
		for(int i=m-1;~i;--i) inv[i]=inv[i+1]*(i+1)%p;
		for(int i=2;i<n;++i)
		{
			(ret+=C(m,n-1)*C(n-2,i-1)%p*(i-1)%p)%=p;
		}
		printf("%lld\n",ret);
	}
}
signed main()
{
	red::main();
	return 0;
}