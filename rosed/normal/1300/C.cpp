#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define eps (1e-6)
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
	const int N=1e5+10;
	int n;
	int a[N];
	int id[N],num;
	bool b[N];
	inline void main()
	{
		n=read();
		for(int i=1;i<=n;++i) a[i]=read();
		for(int k=29;~k;--k)
		{
			int tmp=1<<k;
			int t=0;
			for(int i=1;i<=n;++i)
			{
				if(b[i]) continue;
				if((tmp&a[i])==tmp)
				{
					if(!t) t=i;
					else t=-1;
				}
			}
			if(t==-1||t==0) continue;
			id[++num]=t;
			b[t]=1;
		}
		for(int i=1;i<=num;++i) printf("%lld ",a[id[i]]);
		for(int i=1;i<=n;++i) if(!b[i]) printf("%lld ",a[i]);
	}
}
signed main()
{

	red::main();
	return 0;
}