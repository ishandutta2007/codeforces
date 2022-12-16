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
	const int N=4e5+10;
	int T,n,ans; 
	int a[N],b[N];
	int pos[N];
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read();
			ans=1e9+7;
			for(int i=1;i<=n;++i) a[i]=read();
			for(int i=1;i<=n;++i) b[i]=read(),pos[b[i]]=i;
			for(int i=2*n-2;i>=2;i-=2) pos[i]=min(pos[i],pos[i+2]);
			//for(int i=4;i<=2*n;i+=2) pos[i]=min(pos[i-2],pos[i]);
			for(int x,i=1;i<=n;++i)
			{
				x=a[i]+1;
				ans=min(ans,i+pos[x]-2);
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