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
	const int N=1e6+10;
	int T,n,d,ans,num;
	int a[N],st[N*2],top;
	bool vis[N];
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read(),d=read();ans=0;bool flag=0;
			for(int i=0;i<n;++i) a[i]=read(),vis[i]=0;
			for(int x,i=0;i<n;++i)
			{
				if(vis[i]) continue;
				x=i;top=0;
				while(!vis[x])
				{
					st[++top]=a[x];
					vis[x]=1;
					x=(x+d)%n;
				}
				int pre=0,maxlen=0;
				for(int j=1;j<=top;++j) st[j+top]=st[j];
				for(int j=1;j<=top*2;++j)
				{
					if(st[j]) maxlen=max(maxlen,j-pre);
					else pre=j;
				}
				maxlen=min(top,maxlen);
				if(maxlen==top) flag=1;
				else ans=max(ans,maxlen);
			}
			if(flag) puts("-1");
			else printf("%lld\n",ans);
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
4 9 2
*.*.*...*
.*.*...*.
..*.*.*..
.....*...

*/