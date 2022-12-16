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
	const int N=110;
	int haku; 
	int n,m;
	struct point
	{
		int t,l,r;
		inline bool operator < (const point &v) const
		{
			return t<v.t;
		}
	}q[N];
	int sta,stb;
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read(),m=read();
			bool flag=0;
			for(int i=1;i<=n;++i)
			{
				q[i].t=read(),q[i].l=read(),q[i].r=read();
			}
			sort(q+1,q+n+1);
			sta=stb=m;
			for(int i=1;i<=n;++i)
			{
				int d=q[i].t-q[i-1].t;
				sta-=d,stb+=d;
				if(stb<q[i].l||sta>q[i].r)
				{
					flag=1;
					puts("NO");
					break;
				}
				sta=max(sta,q[i].l),stb=min(stb,q[i].r);
			}
			if(!flag) puts("YES");
		}
	}
}
signed main()
{
	red::main();
	return 0;
}