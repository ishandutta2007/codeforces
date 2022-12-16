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
	const int N=3e5+10;
	int T,n,m,ans;
	int num[4];
	int node[4][N];
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read(),m=read();ans=0;
			for(int k=0;k<4;++k)
			{
				num[k]=read();
				for(int i=1;i<=num[k];++i) node[k][i]=read();
				if(k<2) ans=max(ans,(node[k][num[k]]-node[k][1])*m);
				else ans=max(ans,(node[k][num[k]]-node[k][1])*n);
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