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
	int T,n;
	int a[N],b[N];
	inline bool check(int x)
	{
		for(int i=1;i<=n;++i) b[i]=a[i];
		for(int i=n;i>=3;--i)
		{
			if(b[i]<x) return 0;
			int tmp=min(a[i]/3,(b[i]-x)/3);
			b[i]-=3*tmp;
			b[i-1]+=tmp;b[i-2]+=2*tmp;
		}
		for(int i=1;i<=n;++i) if(b[i]<x) return 0;
		return 1;
	}
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read();
			int l=1,r=0;
			for(int i=1;i<=n;++i) a[i]=read(),r=max(r,a[i]);
			while(l<=r)
			{
				if(check(mid)) l=mid+1;
				else r=mid-1;
			}
			printf("%lld\n",l-1);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
4
1 2 10 100
1 58 38 16

*/