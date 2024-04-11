// Problem: G. Switch and Flip
// Contest: Codeforces - Codeforces Global Round 13
// URL: https://codeforces.com/problemset/problem/1491/G
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
#ifndef ONLINE_JUDGE
#define DEBUG
#endif
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <assert.h>
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
template<typename T>
void print(T x){}
template<>
void print<int>(int x){od(x);}
template<>
void print<const int>(const int x){od(x);}
template<>
void print<long long>(long long x){old(x);}
template<>
void print<const long long>(const long long x){old(x);}
template<>
void print<char>(char x){putchar(x);}
template<>
void print<const char>(const char x){putchar(x);}
template<>
void print<double>(double x){printf("%.12lf",x);}
template<typename T,typename... qwq>
void print(T x,qwq ...args)
{
	print(x);
	print(args...);
}
#ifdef DEBUG
template<typename T>
void debug(T x){}
template<>
void debug<int>(int x){od(x);}
template<>
void debug<const int>(const int x){od(x);}
template<>
void debug<long long>(long long x){old(x);}
template<>
void debug<const long long>(const long long x){old(x);}
template<>
void debug<char>(char x){putchar(x);}
template<>
void debug<const char>(const char x){putchar(x);}
template<>
void debug<double>(double x){printf("%.12lf",x);}
template<typename T,typename... qwq>
void debug(T x,qwq ...args)
{
	debug(x);
	debug(args...);
}
#define dflush fflush
#else
#define dflush(...) 0
template<typename T,typename... qwq>
void debug(T x,qwq ...args)
{
	
}
#endif
//#define int long long
#define newe(n) struct Edge{int v,w,nxt;}e[2*n+5];\
typedef int arr[n+5];\
arr h;\
int cnt=1;\
inline void addedge(int u,int v,int w){e[cnt]=(Edge){v,w,h[u]};h[u]=cnt++;}
#define mgs int fa[1<<22],sz[1<<22];\
inline int f(int x){return x==fa[x]?x:fa[x]=f(fa[x]);}\
inline int uf(int x,int y)\
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
typedef int arr[1000005];
arr a,x,y,ox,oy;int dd;
void op(int c,int b){if(c==b)return;dd++;ox[dd]=c,oy[dd]=b;a[c]^=a[b]^=a[c]^=a[b];}
arr tmp,vis,G;
#include <time.h>
int pre=0,sz=0;
signed main()
{
	int n=read(),cc=0;
	rg(n)a[i]=read();gr
	srand(time(0));
	// rg(n)a[i]=i;gr
	// std::random_shuffle(a+1,a+1+n);
	// rg(n)odb(a[i]);gr puts("");
	int p=0;
	start:;
	// rg(n)odb(a[i]);gr puts("");
	int s=0;
	rg(n)if(a[i]==i||vis[i]){if(!vis[i])s++;continue;}
	s++;
	if(a[a[i]]==i)
	{
		++cc;
		x[cc]=i;
		y[cc]=a[i];
		vis[i]=vis[a[i]]=1;
		// a[a[i]]=a[i];
		// a[i]=i;
		continue;
	}
	// if(p==0)p=i;
	// else 
	// {
		// if(a[i]==p||a[p]==i)continue;
		// op(p,i);
		// while(a[i]!=i)op(i,a[i]);
		// p=0;
	// }
	int qwq=0,qaq=i;do{
		// tmp[++qwq]=qaq;
		vis[qaq]=1;
		qaq=a[qaq];
		qwq++;
	}while(qaq!=i);
	// odl(s);
	// if(qaq==3)
	// {
// 		
	// }
	// else
	if(pre)
	{
		// op(tmp[1],tmp[3]);
		if(sz==qwq&&sz==2)
		{
			assert(0);
			// int b=a[pre];
			// int d=a[i];
			// int a=pre;
			// int c=i;
					// op(b,c);
				// op(c,a);
			// op(b,d);
		// op(b,c);
	// pre=0;
			continue;
		}
		op(pre,i);
	// rg(n)odb(a[i]);gr puts("");
		while(a[i]!=pre)op(i,a[i]);
		while(a[pre]!=i)op(pre,a[pre]);
		op(pre,i);
		pre=0;
	}else pre=i,sz=qwq;
	// rg(n)odb(a[i]);gr puts("");
	gr
	
	if(s==1&&pre&&n>3)
	{int i=pre;
		int qwq=0,qaq=i;do{
			tmp[++qwq]=qaq;
			// vis[qaq]=1;
			qaq=a[qaq];
		}while(qaq!=i);
		// puts("?");
		op(tmp[1],tmp[2]);
		op(tmp[3],tmp[2]);
		op(tmp[1],tmp[3]);
		int d=tmp[2];
		while(a[d]!=d)op(d,a[d]);
		goto qwq_;
		// op(1,2);pre=0;
		// rg(n)vis[i]=0;gr
		// goto start;
	}
	if(pre)
	{
		int i=pre;
		int qwq=0,qaq=i;do{
			tmp[++qwq]=qaq;
			// vis[qaq]=1;
			qaq=a[qaq];
		}while(qaq!=i);
		if(qwq==2)
		{
			int t=a[i];
			int a=i,b=t,c=1;while(c==a||c==b)c++;
			op(a,c);
			op(b,c);
			op(a,c);
		}
		else if(qwq==3)
		{
			if(cc&1)
			{
				int A=x[cc],B=y[cc],C=tmp[1],D=tmp[2],E=tmp[3];
				op(B,C);
				op(B,D);
				op(B,E);
				op(A,C);
				op(B,C);
				
				cc--;
			}else{
			int t=tmp[2];tmp[2]=tmp[3];tmp[3]=t;
			op(tmp[1],tmp[2]);
			op(tmp[1],tmp[3]);
			op(tmp[3],tmp[2]);
			op(tmp[1],tmp[2]);}
		}
		else
		{
			for(int i=1;i+1<=cc;i+=2)
			{
				int a=x[i],b=y[i],c=x[i+1],d=y[i+1];
				op(b,c);
				op(c,a);
				op(b,d);
				op(b,c);
			}
			if(cc&1)
			{
				// int a=x[cc],b=y[cc],c=1;
				// while(c==a||c==b)c++;
				// op(a,c);
				// op(b,c);
				// op(a,c);
				rg(qwq)op(x[cc],tmp[i]);gr
				op(y[cc],tmp[1]);
				op(x[cc],tmp[1]);
				cc=0;
				goto out;
			}
			cc=0;
			// op(tmp[1],tmp[2]);
			rg(qwq)G[i]=tmp[i];gr
			std::sort(G+1,G+1+qwq);
			G[qwq+1]=n+1;
			int pos;
			rg(qwq+1)if(G[i]-G[i-1]>1)pos=G[i]-1;gr
			op(pos,tmp[1]);
			// op(pre,i);
			while(a[pos]!=pos)op(pos,a[pos]);
		}
	}
	out:;
	for(int i=1;i+1<=cc;i+=2)
	{
		int a=x[i],b=y[i],c=x[i+1],d=y[i+1];
		op(b,c);
		op(c,a);
		op(b,d);
		op(b,c);
	}
	if(cc&1)
	{
		int a=x[cc],b=y[cc],c=1;while(c==a||c==b)c++;
		op(a,c);
		op(b,c);
		op(a,c);
	}
	// rg(n)odb(a[i]);gr puts("");
	qwq_:;
	odl(dd);
	rg(dd)odp(ox[i],oy[i]);gr
	return 0;
}