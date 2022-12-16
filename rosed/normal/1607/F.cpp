#include<bits/stdc++.h>
using namespace std;
namespace red{
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-12)
	inline int read()
	{
		int x=0;char ch,f=0;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=1,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	const int N=4e6+10,mod=998244353;
	int T,n,m,posx,posy,pos,maxn;
	char s[2010][2010];
	int rd[N],to[N],fa[N],dp[N];
	bool vis[N];
	queue<int> q;
	inline int id(int x,int y){return (x-1)*m+y;}
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read(),m=read();maxn=0;
			for(int i=1;i<=n*m;++i)
			{
				rd[i]=to[i]=0;
				fa[i]=i,dp[i]=1;
				vis[i]=0;
			}
			for(int i=1;i<=n;++i)
			{
				cin>>(s[i]+1);
			}
			for(int x=1;x<=n;++x)
			{
				for(int y=1;y<=m;++y)
				{
					int tx=x,ty=y;
					if(s[x][y]=='L') --ty;
					if(s[x][y]=='R') ++ty;
					if(s[x][y]=='U') --tx;
					if(s[x][y]=='D') ++tx;
					if(tx<1||ty<1||tx>n||ty>m) to[id(x,y)]=-1;
					else to[id(x,y)]=id(tx,ty),++rd[id(tx,ty)];
				}
			}
			for(int i=1;i<=n*m;++i)if(!rd[i]) q.push(i);
			while(!q.empty())
			{
				int now=q.front(); q.pop();
				if(dp[now]>maxn) maxn=dp[now],pos=fa[now];
				vis[now]=1;
				if(to[now]==-1) continue;
				if(dp[now]+1>dp[to[now]]) dp[to[now]]=dp[now]+1,fa[to[now]]=fa[now];
				if(!(--rd[to[now]])) q.push(to[now]);
			}
			for(int i=1;i<=n*m;++i)
			{
				if(vis[i]) continue;
				int now=to[i],s=0;
				vis[i]=1;
				while(now!=i) now=to[now],++s,vis[now]=1;
				if(dp[i]+s>maxn) maxn=dp[i]+s,pos=fa[i];
				now=to[i];
				while(now!=i)
				{
					if(dp[now]+s>maxn) maxn=dp[now]+s,pos=fa[now];
					now=to[now];
				}
			}
			posx=(pos-1)/m+1,posy=pos-(posx-1)*m;
			printf("%d %d %d\n",posx,posy,maxn);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
14
2 2
DL
RU

*/