#include<bits/stdc++.h>
using namespace std;
namespace red{
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
	const int N=1e5+10;
	int T,n,num;
	int a[N];
	inline void dfs(int now,int s,int pre)
	{
		if(now==2*n+1)
		{
			for(int i=1;i<=2*n;++i)
			{
				putchar(a[i]?'(':')');
			}
			puts("");
			++num;
			return;
		} 
		if(num>=n) return;
		if(pre>0) {a[now]=0;dfs(now+1,s,pre-1);}
		if(s<n){a[now]=1;dfs(now+1,s+1,pre+1);}
	}
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read();num=0;
			dfs(1,0,0);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}