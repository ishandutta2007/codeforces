#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define eps (1e-8)
	inline int read()
	{
		int x=0;char ch,f=0;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=1,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	const int N=3e5+10;
	int T,n,t1,t2,ans;
	int a[N];
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read();ans=n-2;
			for(int i=1;i<=n;++i) a[i]=read();
			a[n+1]=3e18;
			for(int i=1;i<=n;++i)
			{
				int k=i,sum=1;
				if(a[i]==a[i-1]) continue;
				while(k<=n)
				{
					int t=lower_bound(a+k+1,a+n+2,2*a[k]-a[i])-a;
					if(t<=n) k=t,++sum;
					else break;
				}
				ans=min(ans,n-sum);
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
/*
1
8
6 10 56026534 405137099 550504063 784959015 802926648 967281024

*/