// Problem: C. Propagating tree
// Contest: Codeforces - Codeforces Round #225 (Div. 1)
// URL: https://codeforces.com/problemset/problem/383/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <stdio.h>
#include <string.h> 
#include <algorithm>
#include <queue>
#define od(x) printf("%d",x)
#define odb(x) printf("%d ",x)
#define odl(x) printf("%d\n",x)
#define odp(x,y) printf("%d %d\n",x,y)
#define ol(x) puts("")
#define old(x) printf("%lld",x)
#define oldb(x) printf("%lld ",x)
#define oldl(x) printf("%lld\n",x)
#define oldp(x,y) printf("%lld %lld\n",x,y)
//#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
inline int re1d()
{
	char c=getchar();
	while(c<48||c>49)c=getchar();
	return c&1;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
struct Edge{
	int v,nxt;
}e[400005];
int h[200005],cnt=1;
inline void addedge(int u,int v)
{
	e[cnt]=(Edge){v,h[u]};
	h[u]=cnt++;
}
int dfn[200005],c,d[200005],qaq[200005];
void dfs(int u,int fa)
{
	dfn[u]=++c;d[u]=d[fa]^1;
	for(int i=h[u];i;i=e[i].nxt)if(e[i].v!=fa)dfs(e[i].v,u);
	qaq[u]=c;
}
inline int lowbit(int x){return x&(-x);}
int a[2][2000005],qwq[200005];
int n;
inline void add(int q,int w,int g)
{
//	odb(n),odb(q),odp(w,g);
//	if(w==0)return;
	while(w<=n)a[q][w]+=g,w+=lowbit(w);
}
inline int add(int q,int w)
{
//	odp(q,w);
	int res=0;
	while(w)res+=a[q][w],w-=lowbit(w);
	return res;
}
signed main()
{
	n=read();
	int m=read();
	for(int i=1;i<=n;i++)qwq[i]=read();
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		addedge(x,y);
		addedge(y,x);
	}
	dfs(1,0);
	while(m--)
	{
		int op=read();
		if(op==2)
		{
			int x=read();
			odl(qwq[x]+add(d[x],dfn[x]));
		}
		else
		{
			int u=read(),v=read();
			add(d[u],qaq[u]+1,-v);
			add(d[u],dfn[u],v);
			add(d[u]^1,qaq[u]+1,v);
			add(d[u]^1,dfn[u],-v);
		}
	}
	return 0;
}