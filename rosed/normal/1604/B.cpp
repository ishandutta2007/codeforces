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
	int T,n;
	int a[N];
	bool flag;
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read();flag=0;
			for(int i=1;i<=n;++i)
			{
				a[i]=read();
				if(a[i]<=a[i-1]) flag=1;
			}
			if(n%2==0) flag=1;
			puts(flag?"YES":"NO");
		}
	}
}
signed main()
{
	red::main();
	return 0;
}