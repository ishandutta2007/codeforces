#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define eps (1e-8)
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=1e6+10,p=998244353;
	int n,k,ret;
	int a[N],s[N];
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
	inline void main()
	{
		n=read();
		for(int sum,ki,x,i=1;i<=n;++i)
		{
			sum=read(),ki=fast(sum,p-2);
			for(int j=1;j<=sum;++j)
			{
				x=read();
				a[x]=(a[x]+ki)%p,++s[x];
			}
		}
		for(int i=1;i<=1e6;++i)
		{
			if(s[i])
			{
				ret=(ret+a[i]*fast(n,p-2)%p*fast(n,p-2)%p*s[i]%p)%p;
			}
		}
		printf("%lld\n",ret);
	}
}
signed main()
{
	red::main();
return 0;
}