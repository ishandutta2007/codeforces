// Problem: CF662B Graph Coloring
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF662B
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
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
#define rg(x) for(int i=1;i<=(x);i++){
#define fe(u) for(int i=h[u];i;i=e[i].nxt){int v=e[i].v,w=e[i].w;
#define gr }
#define rrg(x) for(int i=0;i<(x);i++)
#define rdln(a) a[i]=read();
#define rdln0(a,x) rrg(x) rdln(a) gr
#define rdln1(a,x) rg(x) rdln(a) gr
#define int long long
#define newe(n) struct Edge{int v,w,nxt;}e[n*2+5];\
typedef int arr[n+5];\
arr h;\
int cnt=1;\
inline void addedge(int u,int v,int w){e[cnt]=(Edge){v,w,h[u]};h[u]=cnt++;}
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
	while(c<'A'||c>'Z')c=getchar();
	return c=='R';
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
newe(200005)
int ans[200005];
class cmll02{
	public:
	int fin=0;
int vis[200005];
int qwq[200005];
int wis[200005],y[200005];
void cpy_main(int u,int fa,int q)
{
	wis[u]=1;
	qwq[u]^=q;
	fe(u)(wis[v]==0)?cpy_main(v,u,q):(void)0;gr
}
int sz,ss;
void cpy_cnt(int u,int fa)
{
	y[u]=1;
	sz++;ss+=qwq[u];
	fe(u)(y[v]==0)?cpy_cnt(v,u):(void)0;gr
}
void cpy(int u,int fa)
{
	sz=ss=0;
	cpy_cnt(u,fa);
	if(ss>sz-ss)cpy_main(u,fa,1);
	else cpy_main(u,fa,0);
}
int dfs(int u,int fa,int c)
{
	qwq[u]=2;vis[u]=1;
	int c1=0,c0=0;
	fe(u)if(vis[v])if(qwq[v]==(c^1^w))c1++;else c0++;gr
	int rs=0;
	if(c1==c0&&c0==0)
	{
		qwq[u]=0;
		fe(u)(vis[v]==0)&&(rs+=dfs(v,u,c));gr
		return rs;
	}
	if(c1&&c0)return 1919810;
	if(c0)qwq[u]=0;else qwq[u]=1,rs=1;
	fe(u)(vis[v]==0)&&(rs+=dfs(v,u,c));gr
	return rs;
}}cmll[2];
inline void solve(int n)
{
	int q0=(cmll[0].dfs(n,0,0)),q1=(cmll[1].dfs(n,0,1));
	cmll[0].cpy(n,0);
	cmll[1].cpy(n,0);
//	odp(q0,q1);
	cmll[0].fin+=q0;
	cmll[1].fin+=q1;
	if(min(q1,q0)>=1919810){puts("-1");exit(0);};
//	if(q0<q1)cmll[0].cpy(n,0);else cmll[1].cpy(n,1);
}
signed main()
{
	int n=read(),m=read();
	rg(m)int u=read(),v=read(),w=re1d();addedge(u,v,w);addedge(v,u,w);gr
	rg(n)if(!cmll[0].vis[i]&&!cmll[1].vis[i])solve(i);gr
	int q0=cmll[0].fin,q1=cmll[1].fin;
	if(min(q0,q1)>=1919810)return puts("-1")&0;
	q0=0,q1=0;
	rg(n)q0+=cmll[0].qwq[i];gr
	rg(n)q1+=cmll[1].qwq[i];gr
	if(cmll[0].fin>=1919810)q0=1919810;
	if(cmll[1].fin>=1919810)q1=1919810;
//	oldp(q0,q1);//
	if(q0<q1)
	{
		odl(q0);
		rg(n)cmll[0].qwq[i]&&odb(i);gr
	}
	else
	{
		odl(q1);
		rg(n)cmll[1].qwq[i]&&odb(i);gr
	}
	return 0;
}