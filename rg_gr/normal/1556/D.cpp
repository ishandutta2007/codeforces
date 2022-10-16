// Problem: D. Take a Guess
// Contest: Codeforces - Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1556/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//  - /

/*
+
++
+++
++++
+++++
++++++
+++++++
++++++++
+++++++++
++++++++++
+++++++++++
++++++++++++
+++++++++++++
++++++++++++++
+++++++++++++++
++++++++++++++++
+++++++++++++++++
++++++++++++++++++
+ +++++++++++++++++
+  ++++++++++++++ ++
+   +++++++++++++  ++
+    ++++++++++++   ++
+     +++++++++++    ++
+      ++++++++++     ++
+       +++++++++      ++
+        ++++++++       ++
+         +++++++++++++++++
+          +++++++++++++++++
+           ++++++++++++++
+            +++++++++++
+             ++++++++
+              +++++
+               ++
+               +
+               +
+              ++
+             +++
+            ++++
+           +++++
+           +++++
+           +++++
+           +++++
+     +     +++++
+    +++    +++++
+   ++ ++   +++++
+  ++   ++  +++++
+ ++  +  ++ +++++
+++  +++  +++++++
++  ++ ++  ++++++
 
 
 ++++++++      +++++++++++     +++      +++        ++++++++        ++++++++
+++++++++     +++++++++++++    +++      +++       +++    +++      +++    +++
+++          +++   +++   +++   +++      +++      +++   ++++++    +++      +++
+++          +++   +++   +++   +++      +++      +++ +++  +++           +++
+++          +++   +++   +++   +++ ++   +++ ++   ++++++   +++         +++
+++++++++    +++   +++   +++   +++ ++   +++ ++    +++    +++        +++    ++
 ++++++++    +++   +++   +++   +++++    +++++      ++++++++       +++++++++++
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <set>
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
#define fe(u) for(int i=h[u];i;i=e[i].nxt){int v=e[i].v;
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
    while(c<48||c>49)c=getchar();
    return c&1;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
int a[10005],o[10005],res[10005];
int tag[10005];
signed main()
{
	int n=read(),k=read();
	rg(n)if(i>1)
	{
		printf("and 1 %lld\n",i);fflush(stdout);a[i]=read();
		printf("or 1 %lld\n",i);fflush(stdout);o[i]=read();
	}gr
	printf("and 2 3\n");fflush(stdout);int A=read();
	printf("or 2 3\n");fflush(stdout);int D=read();
	res[1]=(a[2]+o[2]+a[3]+o[3]+A+D)>>1;
	res[1]-=A+D;
	rg(n)if(i>1)res[i]=a[i]+o[i]-res[1];gr
/*	rg(n-1)printf("and %lld %lld\n",i,i+1);fflush(stdout);a[i]=read();gr
	rg(n-1)printf("or %lld %lld\n",i,i+1);fflush(stdout);o[i]=read();gr
	rg_(k,31)int j=k-1;
	memset(tag,0,sizeof(tag));
	rg(n-1)
	int A=(a[i]>>j)&1,D=(o[i]>>j)&1;
	if(A==1&&D==1)tag[i]=tag[i+1]=1;
	else if(A==0&&D==0)tag[i]=tag[i+1]=2;
	else if(tag[i])tag[i+1]=3^tag[i];
	gr
//	rg(n)odp(a[i],o[i]);gr puts("");
	int x;
	if(tag[n])goto suc;
	//nothing happend;;;
	printf("and 1 3\n");fflush(stdout);
	x=read();if(x==0)x=2;
	rg(n)tag[i]=x;x^=3;gr
	goto nxt;
	suc:;
	for(int i=n-1;i>=1;i--)if(tag[i]==0)tag[i]=3^tag[i+1];
	nxt:;
	rg(n)if(tag[i]==1)res[i]|=1ll<<j;gr
	gr*/
	std::sort(res+1,res+1+n);
//	rg(n)odb(res[i]);gr
	printf("finish ");oldl(res[k]);
	fflush(stdout);
	return 0;
}