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
	const int N=5e5+10,mod=998244353;
	int T,n;
	int a[N];
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read();
			for(int i=1;i<=n;++i) a[i]=read();
			sort(a+1,a+n+1); 
			printf("%lld\n",a[n]-a[1]);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*


*/