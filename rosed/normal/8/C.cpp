#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long 
#define y1 QwQ
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-6)
#define lowbit(i) ((i)&(-i))
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	int stx,sty;
	int n,ret,ans=1e9+7;
	struct node
	{
		int x,y;
	}a[50];
	inline int sqr(int x){return x*x;}
	inline int dis(int x,int y,int dx,int dy)
	{
		return sqr(x-dx)+sqr(y-dy);
	}
	int vis[50];
	int g[50];
	inline void dfs(int now)
	{
		if(ret>=ans) return;
		if(now>n)
		{
			ans=ret;
			for(int i=1;i<=n;++i) g[i]=vis[i];
			return;
		}
		if(vis[now]) {dfs(now+1);return;}
		for(int i=now+1;i<=n;++i)
		{
			if(!vis[i])
			{
				ret+=dis(a[now].x,a[now].y,a[i].x,a[i].y);
				vis[now]=i;
				vis[i]=now;
				dfs(now+1);
				ret-=dis(a[now].x,a[now].y,a[i].x,a[i].y);
				if(vis[now]!=i||vis[i]!=now) cout<<"!"<<endl;
				vis[now]=vis[i]=0;
			}
		}
		vis[now]=now;
		ret+=dis(a[now].x,a[now].y,stx,sty);
		dfs(now+1);
		vis[now]=0;
		ret-=dis(a[now].x,a[now].y,stx,sty);
	}
	inline void main()
	{
		stx=read(),sty=read();
		n=read();
		for(int i=1;i<=n;++i)
		{
			a[i].x=read(),a[i].y=read();
			ret+=dis(a[i].x,a[i].y,stx,sty);
		}
		dfs(1);
		printf("%lld\n",ans);
		printf("0 ");
		for(int i=1;i<=n;++i)
		{ 
			if(!g[i]) continue;
			if(g[i]==i)
			{
				printf("%lld 0 ",g[i]);
				g[i]=0;
			}
			else
			{
				printf("%lld %lld 0 ",i,g[i]);
				g[g[i]]=0;
				g[i]=0;
			}
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
7 -11
5
-1 7
-7 -11
12 -4
8 -6
-18 -8

922
0 1 0 2 4 0 3 0

*/