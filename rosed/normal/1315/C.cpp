#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();} 
		return f?x:-x;
	}
	const int N=1e5+10,mod=1e9+7;
	int haku;
	int n;
	int b[N],a[N];
	bool q[500];
	bool f;
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read();
			for(int i=1;i<=n;++i) b[i]=read();
			memset(q,0,sizeof(q));
			f=0;
			for(int i=1;i<=n;++i)
			{
				a[i*2-1]=b[i];
				q[b[i]]=1;
			}
			for(int i=1;i<=n;++i)
			{
				a[i*2]=a[i*2-1]+1;
				while(q[a[i*2]]) ++a[i*2];
				if(a[i*2]>2*n)
				{
					f=1;break;
				} 
				q[a[i*2]]=1;
			}
			if(f)
			{
				puts("-1");
				continue;
			}
			for(int i=1;i<=n*2;++i) printf("%lld ",a[i]);
			puts("");
		}
	}
}
signed main()
{
	red::main();
	return 0;
}