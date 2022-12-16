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
	const int N=524292,p=998244353;
	int n,t1,t2,ans;
	int fac[N],ifac[N],inv[N],pos[N];
	int f[N],g[N];
	inline void init(int n)
	{
		inv[1]=1;
  		for(int i=2;i<=n;++i) inv[i]=(-(p/i)*inv[p%i]%p+p)%p;
  		fac[0]=ifac[0]=1;
		for(int i=1;i<=n;++i) fac[i]=fac[i-1]*i%p,ifac[i]=ifac[i-1]*inv[i]%p;
	}
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
	inline void ntt(int limit,int *a,int inv)
	{
		for(int i=1;i<limit;++i)
			if(i<pos[i]) swap(a[i],a[pos[i]]);
		for(int mid=1;mid<limit;mid<<=1)
		{
			int Wn=fast(3,(p-1)/(mid<<1));
			for(int r=mid<<1,j=0;j<limit;j+=r)
			{
				int w=1;
				for(int k=0;k<mid;++k,w=w*Wn%p)
				{
					int x=a[j+k],y=w*a[j+k+mid]%p;
					a[j+k]=(x+y)%p;
					a[j+k+mid]=(x-y+p)%p;
				}
			}
		}
		if(inv) return;
		inv=fast(limit,p-2);reverse(a+1,a+limit);
		for(int i=0;i<limit;++i) a[i]=a[i]*inv%p;
	}
	inline void offset(int *f,int n,int c,int *g)
	{
		static int a[N],b[N];
		int limit=1,len=0;
		while(limit<=n*2) limit<<=1,++len;
		for(int i=1;i<limit;++i) pos[i]=(pos[i>>1]>>1)|((i&1)<<(len-1));
		for(int i=0;i<=n;++i) a[i]=fac[i]*f[i]%p;
		int tmp=1;
		for(int i=0;i<=n;++i,tmp=tmp*c%p) b[n-i]=tmp*ifac[i]%p;
		for(int i=n+1;i<limit;++i) a[i]=b[i]=0;
		ntt(limit,a,1);ntt(limit,b,1);
		for(int i=0;i<limit;++i) a[i]=a[i]*b[i]%p;
		ntt(limit,a,0);
		for(int i=0;i<=n;++i) g[i]=a[i+n]*ifac[i]%p;
	}
	inline void solve(int *f,int n)
	{
		if(n==0) return(void)(f[0]=1);
		static int a[N],b[N];
		int m=n>>1;
		solve(f,m);
		offset(f,m,m,a);
		int limit=1,len=0;
		while(limit<=n) limit<<=1,++len;
		for(int i=1;i<limit;++i) pos[i]=(pos[i>>1]>>1)|((i&1)<<(len-1));
		for(int i=0;i<=m;++i) b[i]=f[i];
		for(int i=m+1;i<limit;++i) a[i]=b[i]=0;
		ntt(limit,a,1);ntt(limit,b,1);
		for(int i=0;i<limit;++i) a[i]=a[i]*b[i]%p;
		ntt(limit,a,0);
		if(n&1)//(x+n-1)
		{
			for(int i=0;i<=n;++i)
				f[i]=((i?a[i-1]:0)+(n-1)*a[i])%p;
		}
		else
		{
			for(int i=0;i<=n;++i)
				f[i]=a[i];
		}
	}
	inline int C(int n,int m)
	{
		if(n<m) return 0;
		return fac[n]*ifac[m]%p*ifac[n-m]%p;
	}
	inline void main()
	{
		n=read()-1,t1=read()-1,t2=read()-1;
		init(n<<1);
		solve(f,n);
		ans=(f[t1+t2]+p)%p;
		ans=ans*C(t1+t2,t1)%p;
		printf("%lld\n",ans);
	}
}
signed main()
{
	red::main();
	return 0;
}