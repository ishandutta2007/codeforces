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
#include <assert.h>
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
//#define int long long
#define newe(n) struct Edge{int v,w,nxt;}e[2*n+5];\
typedef int arr[n+5];\
arr h;\
int cnt=1;\
inline void addedge(int u,int v,int w){e[cnt]=(Edge){v,w,h[u]};h[u]=cnt++;}
#define mgs int fa[1<<22],sz[1<<22];\
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
    while(c<'A'||c>'Z')c=getchar();
    return c=='R'?0:(c=='G'?1:(c=='Y'?2:3));
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
#define su b
int a[505][505],b[4][505][505];//,c[10][10][505][505],lg[505];
int pre[255][505][505];
inline int sum(int a,int l,int r,int L,int R)
{
	if(l>L)l^=L^=l^=L;
	if(r>R)r^=R^=r^=R;
	l--,r--,L--,R--;
	return su[a][L][R]-su[a][l][R]-su[a][L][r]+su[a][l][r];
}
inline int sum2(int a,int l,int r,int L,int R)
{
	if(l>L)l^=L^=l^=L;
	if(r>R)r^=R^=r^=R;
	l--,r--;
	return pre[a][L][R]-pre[a][l][R]-pre[a][L][r]+pre[a][l][r];
}
signed main()
{
	int n=read(),m=read();
	int q=read();
	rg(n)rg_(j,m)a[i][j]=re1d();gr gr
	rg(n)rg_(j,m)rg_(k,4)b[k-1][i][j]=b[k-1][i][j-1]+b[k-1][i-1][j]-b[k-1][i-1][j-1]+(a[i][j]==k-1);gr gr gr
	rg(n)rg_(j,m)int s=0;rg_(x,n)
	if(i+x+x-1>n||j+x+x-1>m)continue;
	if(sum(0,i,j,i+x,j+x)==x*x&&sum(1,i,j+x,i+x,j+x+x)==x*x&&sum(2,i+x,j,i+x+x,j+x)==x*x&&sum(3,i+x,j+x,i+x+x,j+x+x)==x*x)s=x;
	gr 
	pre[s][i][j]=1;
	gr gr
	rg_(k,250)rg(n)rg_(j,m)pre[k][i][j]+=pre[k][i-1][j]+pre[k][i][j-1]-pre[k][i-1][j-1];gr gr gr
	rg(q)int l=read(),u=read(),r=read(),d=read();
	for(int i=250;i>=1;i--)
	{
		if(l+i+i-1<=r&&u+i+i-1<=d&&sum2(i,l,u,r-i-i+1,d-i-i+1))
		{
			odl(i*i*4);
			goto w;
		}
	}
	puts("0");w:;gr
	// rg_(j,9)rg_(k,n)for(int l=1;l+(1<<j)-1<=m;l++)c[0][j][k][l]=max(c[0][j-1][k][l],c[0][j-1][k][l+(1<<j-1)]);gr gr
	// rg_(i,9)for(int k=1;k+(1<<i)-1<=n;k++)rg_(l,m)c[i][0][k][l]=max(c[i-1][0][k][l],c[i-1][0][k+(1<<i-1)][l]);gr gr
	// rg(9)rg_(j,9)for(int k=1;k+(1<<i)-1<=n;k++)for(int l=1;l+(1<<j)-1<=m;l++)
	// c[i][j][k][l]=max(c[i-1][j][k][l],c[i-1][j][k+(1<<i-1)][l]);gr gr
	// rg(n)rg_(j,m)odb(c[0][0][i][j]);gr puts("");gr puts("");
	// rg(q)int l=read(),u=read(),r=read(),d=read();
	// for(int i=n;i>=0;i--)if(check(l,u,r-i-i+1,d-i-i+1)>=i){odl(i*i*4);break;}
	// gr
	return 0;
}