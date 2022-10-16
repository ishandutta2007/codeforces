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
#define int long long
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
}e[800005];
int h[400005],cnt=1;
inline void addedge(int u,int v)
{
	e[cnt]=(Edge){v,h[u]};
	h[u]=cnt++;
}
int dfn[400005],c,d[400005],qaq[400005];
void dfs(int u,int fa)
{
	dfn[u]=++c;d[u]=d[fa]^1;
	for(int i=h[u];i;i=e[i].nxt)if(e[i].v!=fa)dfs(e[i].v,u);
	qaq[u]=c;
}
int qwq[400005];
int n;
int s[800005*2],S[800005*2];
inline void pushdown(int o,int l,int r)
{
	if(l==r||s[o]==0)return;
	s[o<<1]=s[o<<1|1]=s[o];
	s[o]=0;
}
/*inline void maintain(int o,int l,int r)
{
	if(l==r)
	{
		S[o]=s[o];
		s[o]=0;
		break;
	}
	S[o]=S[o<<1]|S[o<<1|1];
}*/
inline void update(int o,int l,int r)
{
	if(s[o])S[o]=s[o];
}
void set(int o,int l,int r,int L,int R,int v)
{
	if(L<=l&&r<=R)
	{
		s[o]=v;
		S[o]=v;
		return;
	}
	int m=l+r>>1;
	if(s[o])pushdown(o,l,r);
	if(L<=m)set(o<<1,l,m,L,R,v);else update(o<<1,l,m);
	if(m<R)set(o<<1|1,m+1,r,L,R,v);else update(o<<1|1,m+1,r);
	S[o]=S[o<<1]|S[o<<1|1];
}
int ccc(int o,int l,int r,int L,int R)
{
	if(s[o])return s[o];
	if(L<=l&&r<=R)return S[o];
	int q=0;
	int m=l+r>>1;
	if(L<=m)q|=ccc(o<<1,l,m,L,R);
	if(m<R)q|=ccc(o<<1|1,m+1,r,L,R);
	return q;
}
inline int __bulitin_popcount(int x)
{
	int q=0;
	while(x)q+=x&1,x>>=1;
	return q;
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
	for(int i=1;i<=n;i++)set(1,1,n,dfn[i],dfn[i],1ll<<qwq[i]);//,odp(dfn[i],qaq[i]);
	while(m--)
	{
		int op=read();
		if(op==2)
		{
			int i=read();
			oldl(__bulitin_popcount(ccc(1,1,n,dfn[i],qaq[i])));
		}
		else
		{
			int i=read(),v=read();
			set(1,1,n,dfn[i],qaq[i],1ll<<v);
		}
	}
	return 0;
}