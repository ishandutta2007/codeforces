#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define fail return(void)puts("-1")
#define y1 qwq 
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=1e5+10;
	int n,m,l,r;
	int a[N];
	int suf[N],ans[N];
	inline void main()
	{
		n=read(),m=read();
		for(int i=1;i<=m;++i) a[i]=read();
		for(int i=m;i;--i) suf[i]=suf[i+1]+a[i];
		if(suf[1]<n||a[n]+m-1>n) fail;
		for(int i=1;i<=m;++i)
		{
			l=max(l+1,n-suf[i]+1);
			ans[i]=l;
			r=max(r,l+a[i]-1);
		}
		if(r!=n) fail;
		for(int i=1;i<=m;++i)
		{
			printf("%lld ",ans[i]);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
5 5
1 2 3 1 1

*/