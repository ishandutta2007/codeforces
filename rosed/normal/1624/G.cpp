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
	int T,n,m,ans;
	struct edge
	{
		int x,y,v;
		bool g; 
	}a[N<<1];
	int head[N],cnt;
	int f[N];
	inline int find(int k){return f[k]==k?k:f[k]=find(f[k]);}
	inline bool merge(int x,int y)
	{
		x=find(x),y=find(y);
		if(x==y) return 0;
		f[x]=y;return 1;
	}
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read(),m=read();ans=0;
			for(int i=1;i<=m;++i)
			{
				a[i].x=read(),a[i].y=read(),a[i].v=read();
				a[i].g=0;
			}
			for(int t=29;~t;--t)
			{
				for(int i=1;i<=n;++i) f[i]=i;
				int tot=0;
				for(int i=1;i<=m;++i)
				{
					if(a[i].g==1||((a[i].v>>t)&1)) continue;
					tot+=merge(a[i].x,a[i].y);
				}
				if(tot==n-1)
				{
					for(int i=1;i<=m;++i) if((a[i].v>>t)&1) a[i].g=1;
				}
				else ans|=(1<<t);
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


*/