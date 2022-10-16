// Problem: CF515C Drazil and Factorial
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF515C
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
#define rg(x) for(int i=1;i<=(x);i++){
#define rg_(i,x) for(int i=1;i<=(x);i++){
#define gr }
#define rrg(x) for(int i=0;i<(x);i++)
#define rdln(a) a[i]=read();
#define rdln0(a,x) rrg(x) rdln(a) gr
#define rdln1(a,x) rg(x) rdln(a) gr
//#define int long long
#define newe(n) struct Edge{int v,w,nxt;}e[n*2+5];\
typedef int arr[n+5];\
arr h;\
int cnt=1;\
inline void addedge(int u,int v,int w){e[cnt]=(Edge){v,w,h[u]};h[u]=cnt++;}
#define mgs int fa[1<<22],sz[1<<22],t[1<<22];\
inline int f(int x){return x==fa[x]?x:fa[x]=f(fa[x]);}\
inline int u(int x,int y)\
{\
	int fx=f(x),fy=f(y);\
	if(fx==fy)return 0;\
	if(sz[fx]>sz[fy])fx^=fy^=fx^=fy;\
	fa[fx]=fy,sz[fy]+=sz[fx];\
	return 1;\
}
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
	while(c<48||c>57)c=getchar();
	return c&15;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
int c2,c3,c5,c7;
signed main()
{
	int n=read();
	rg(n)int x=re1d();
	if(x==0);else if(x==1);
	else if(x==2)c2++;
	else if(x==3)c2++,c3++;
	else if(x==4)++++++c2,++c3;
	else if(x==5)++++++c2,++c3,++c5;
	else if(x==6)++++++++c2,++++c3,++c5;
	else if(x==7)++++++++c2,++++c3,++c5,++c7;
	else if(x==8)++++++++++++++c2,++++c3,++c5,++c7;
	else if(x==9)++++++++++++++c2,++++++++c3,++c5,++c7;gr
	while(c7--)putchar('7'),c2--,c2--,c2--,c2--,c3--,c3--,c5--;
	while(c5--)putchar('5'),c2--,c2--,c2--,c3--;
	while(c3--)putchar('3'),c2--;
	while(c2--)putchar('2');
	return 0;
}