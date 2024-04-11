#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
	inline int read()
	{
		int x=0;char ch,f=0;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=1,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	const int N=3e5+10;
	int T,n;
	int a[N],b[N];
	inline bool check(int x)
	{
		int sum=0;
		for(int i=1;i<=n;++i)
		{
			if(b[i]<sum) continue;
			if(a[i]>=x-sum-1) ++sum;
		}
		return sum>=x;
	}
	inline void main()
	{
		T=read();	
		while(T--)
		{
			n=read();
			for(int i=1;i<=n;++i)
			{
				a[i]=read(),b[i]=read();
			}
			int l=1,r=n;
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
1
2
0 0
0 1

*/