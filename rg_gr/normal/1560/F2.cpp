// Problem: F2. Nearest Beautiful Number (hard version)
// Contest: Codeforces - Codeforces Round #739 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1560/F2
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
int u[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000ll};
int w[]={0,0,0,0,0,0,0,0,0,0};
inline int get(int n,int q)
{
	return n%u[q+1]/u[q];
}
inline void modify(int &n,int q,int x)
{
	n-=u[q]*get(n,q);
	n+=u[q]*x;
}
int prefiX(int p,int q,int n,int k)
{
	--p;--q;
	//hou p wei bao liu
	rrg(10)w[i]=0;
	for(int i=p;i<=q;i++)w[get(n,i)]=1;
	int c=0;
	rrg(10)c+=w[i];
	if(p==0)return c<=k?n:0;
	int res=n;
	if(c+1<k)
	{
		for(int i=0;i<p-1;i++)modify(res,i,0);
		int t=get(res,p-1)+1;
		modify(res,p-1,t);
		return res;
	}
	if(c<k)
	{
		int t=get(res,p-1)+1;
		if(w[t])
		{
			for(int i=0;i<p-1;i++)modify(res,i,0);
			modify(res,p-1,t);
			return res;
		}
		else
		{
			w[t]=1;
			int val=0;
			for(int i=0;i<10;i++)
			{
				if(w[i])
				{
					val=i;
					break;
				}
			}
			for(int i=0;i<p-1;i++)modify(res,i,val);
			modify(res,p-1,t);
			return res;
		}
	}
	if(c>k)return 0;
	int val=-1;
	for(int i=get(n,p-1)+1;i<10;i++)
	{
		if(w[i])
		{
			val=i;
			break;
		}
	}
//	oldp(val,p);
	if(val==-1)return 0;
	modify(res,p-1,val);
	val=-1;
	for(int i=0;i<10;i++)
	{
		if(w[i])
		{
			val=i;
			break;
		}
	}
	if(val==-1)return 0;
	for(int i=0;i<p-1;i++)modify(res,i,val);
	
	return res;
}
signed main()
{
	int T=read();
	rg(T)int n=read(),k=read();
	if(k==1)
	{
		int q=1,tt=n;
		while(tt>9)tt/=10,q=q*10+1;
//		oldp(q,tt);
		if(q*tt>=n)oldl(q*tt);
		else oldl((tt+1)*q);
	}
	else
	{
		int q=0,tt=n,s=1;
		while(tt)tt/=10,q++,s*=10;
		for(int p=1;p<=q+1;p++)if(prefiX(p,q,n,k)){oldl(prefiX(p,q,n,k));break;}
	}gr
	return 0;
}