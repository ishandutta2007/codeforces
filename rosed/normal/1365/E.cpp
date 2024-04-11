#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) (i&(-i))
	inline int read()
	{
		int x=0;char f=1,ch;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=510;
	int n,ans;
	int a[N];
	inline void dfs(int x,int y,int s)
	{
		if(y==3||x>n)
		{
			ans=max(ans,s);
			return;
		}
		dfs(x+1,y+1,s|a[x]);
		dfs(x+1,y,s);
	}
	inline void main()
	{
		n=read();
		for(int i=1;i<=n;++i) a[i]=read();
		dfs(1,0,0);
		printf("%lld\n",ans);
	}
}
signed main()
{
	red::main();
	return 0;
}