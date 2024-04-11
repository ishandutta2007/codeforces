#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
	inline int read()
	{
		int x=0;char f=0,ch;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=1,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	const int N=3e5+10,mod=998244353;
	int T,n,sum,ans;
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read();ans=sum=0;
			for(int x,i=1;i<=n;++i)
			{
				x=read();
				++sum;
				int t=x-sum;
				if(t<0) t=0;
				ans+=t;
				sum+=t;
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
4
1 3 1 3

*/