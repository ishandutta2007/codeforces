#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<set>
using namespace std;
namespace red{
#define y1 qwq
#define eps (1e-6)
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=3e5+10;
	int n,m;
	int son[N][2],tag[N],f[N],st[N];
	bool vis[3][N];
	inline void pushr(int x)
	{
		swap(son[x][0],son[x][1]);
		tag[x]^=1;
	}
	inline void pushdown(int x)
	{
		if(!tag[x]) return ;
		if(son[x][0]) pushr(son[x][0]);
		if(son[x][1]) pushr(son[x][1]);
		tag[x]=0;
	}
	inline bool nroot(int x)
	{
		return son[f[x]][0]==x||son[f[x]][1]==x;
	}
	inline int ident(int x)
	{
		return son[f[x]][1]==x;
	}
	inline void rotate(int x)
	{
		int y=f[x],z=f[y],k=son[y][1]==x,w=son[x][!k];
		if(nroot(y)) son[z][son[z][1]==y]=x;son[x][!k]=y;son[y][k]=w;
		if(w) f[w]=y;f[y]=x;f[x]=z;
	}
	inline void splay(int x)
	{
		int y=x,z=0;
		st[++z]=y;
		while(nroot(y)) st[++z]=y=f[y];
		while(z) pushdown(st[z--]);
		while(nroot(x))
		{
			y=f[x];
			if(nroot(y)) rotate(ident(x)==ident(y)?y:x);
			rotate(x);
		}
	}
	inline void access(int x)
	{
		for(int y=0;x;x=f[y=x])
			splay(x),son[x][1]=y;
	}
	inline void makeroot(int x)
	{
		access(x);splay(x);
		pushr(x);
	}
	inline int findroot(int x)
	{
		access(x);splay(x);
		while(son[x][0]) pushdown(x),x=son[x][0];
		splay(x);return x;
	}
	inline void split(int x,int y)
	{
		makeroot(x);
		access(y);splay(y);
	}
	inline void link(int x,int y)
	{
		makeroot(x);
		if(findroot(y)!=x) f[x]=y;
	}
	inline void cut(int x,int y)
	{
		makeroot(x);
		if(findroot(y)!=x||f[y]!=x||son[x][0]) return;
		f[y]=son[x][0]=0;
	}
	inline void main()
	{
		n=read(),m=read();
		for(int i=1;i<=n;++i)
		{
			if(i!=n) link(i,i+1);
			link(i,i+n);
		}
		for(int x,y,i=1;i<=m;++i)
		{
			x=read(),y=read();
			vis[x][y]^=1;
			if(vis[x][y])
			{
				if(x==1)
				{
					cut(y,y+n);
					if(y!=1)
					{
						cut(y-1,y);
						if(!vis[2][y-1]&&!vis[2][y])link(y+n-1,y+n);
					}
					if(y!=n)
					{
						cut(y,y+1);
						if(!vis[2][y]&&!vis[2][y+1])link(y+n,y+n+1);
					}
				}
				else
				{
					cut(y,y+n);
					if(y!=1)
					{
						cut(y+n-1,y+n);
						if(!vis[1][y-1]&&!vis[1][y])link(y-1,y);
					}
					if(y!=n)
					{
						cut(y+n,y+n+1);
						if(!vis[1][y]&&!vis[1][y+1])link(y,y+1);
					}
				}
			}
			else
			{
				if(x==1)
				{
					link(y,y+n);
					if(y!=1)
					{
						if(!vis[1][y-1]&&!vis[1][y])link(y-1,y);
					}
					if(y!=n)
					{
						if(!vis[1][y]&&!vis[1][y+1])link(y,y+1);
					}
				}
				else
				{
					link(y,y+n);
					if(y!=1)
					{
						if(!vis[2][y-1]&&!vis[2][y])link(y+n-1,y+n);
					}
					if(y!=n)
					{
						if(!vis[2][y]&&!vis[2][y+1])link(y+n,y+n+1);
					}
				}
			}
			makeroot(1);
			if(findroot(2*n)==1) puts("Yes");
			else puts("No");
		}
	}
}
signed main()
{
	red::main();
	return 0;
}