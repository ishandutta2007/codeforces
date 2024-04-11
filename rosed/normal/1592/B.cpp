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
	const int N=5e5+10;
	int T,n,dx;
	int a[N],b[N];
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read(),dx=read();
			for(int i=1;i<=n;++i) a[i]=b[i]=read();
			sort(b+1,b+n+1);
			if(dx<=n/2) puts("YES");
			else
			{
				bool flag=0;
				int tot=dx*2-n;
				int len=(n-tot)/2;
				for(int i=len+1;i<=n-len;++i)
				{
					if(a[i]!=b[i]) flag=1;
				}
				puts(flag?"NO":"YES");
			}
		}
	}
}
signed main()
{
	red::main();
	return 0;
}