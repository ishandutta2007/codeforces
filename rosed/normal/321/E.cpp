#include<bits/stdc++.h>
using namespace std;
namespace red{
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define y1 qwq 
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=4010;
	int n,m,ret;
	int a[N][N],s[N][N];
	int f[N],g[N];
	inline int getare(int x,int y)
	{
		return (s[y][y]-s[x][y]-s[y][x]+s[x][x])>>1;
	}
	inline void solve(int l,int r,int tl,int tr)
	{
		if(l>r) return;
		int mid=(l+r)>>1,k=0,p=min(mid,tr);
		for(int i=tl;i<=p;++i)
		{
			if(i>=mid) break;
			if(g[i]+getare(i,mid)<f[mid])
			{
				f[mid]=g[i]+getare(i,mid);
				k=i;
			}
		}
		solve(l,mid-1,tl,k);
		solve(mid+1,r,k,tr);
	}
	inline void main()
	{
		n=read(),m=read();
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				a[i][j]=read();
				s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
			}
			g[i]=getare(0,i);
		}
		while(--m)
		{
			memset(f,0x3f,sizeof(f));
			solve(1,n,1,n);
			swap(f,g);
		}
		printf("%d\n",g[n]);
	}
}
signed main()
{
	red::main();
	return 0;
}