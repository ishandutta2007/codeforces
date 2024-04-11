// Problem: F. And Yet Another Bracket Sequence
// Contest: Codeforces - VK Cup 2015 - Round 1
// URL: https://codeforces.com/problemset/problem/524/F
// Memory Limit: 256 MB
// Time Limit: 5000 ms
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
// #define int long long
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
char a[2000005];
struct dqstz_orz{
int minn[4000005],tag[4000005];
void pushdown(int o)
{
	int&t=tag[o];
	minn[o<<1]+=t;
	minn[o<<1|1]+=t;
	tag[o<<1]+=t;
	tag[o<<1|1]+=t;
	t=0;
}
void add(int o,int l,int r,int L,int R,int v)
{
	// for(int i=L;i<=R;i++)minn[i]+=v;
	if(L<=l&&r<=R)
	{
		minn[o]+=v;
		tag[o]+=v;
		return;
	}
	int m=l+r>>1;
	pushdown(o);
	if(L<=m)add(o<<1,l,m,L,R,v);
	if(m<R)add(o<<1|1,m+1,r,L,R,v);
	minn[o]=min(minn[o<<1],minn[o<<1|1]);
}
void set(int o,int l,int r,int L,int v)
{
	// for(int i=L;i<=R;i++)minn[i]+=v;
	if(l==r)
	{
		minn[o]=v;
		return;
	}
	int m=l+r>>1;
	pushdown(o);
	if(L<=m)set(o<<1,l,m,L,v);
	else set(o<<1|1,m+1,r,L,v);
	minn[o]=min(minn[o<<1],minn[o<<1|1]);
}
int que(int o,int l,int r,int L,int R)
{
	// int res=minn[L];
	// for(int i=L;i<=R;i++)res=min(res,minn[i]);
	// return res;
	if(L<=l&&r<=R)
	{
		return minn[o];
	}
	int m=l+r>>1,res=0x3f3f3f3f;
	pushdown(o);
	if(L<=m)res=min(res,que(o<<1,l,m,L,R));
	if(m<R)res=min(res,que(o<<1|1,m+1,r,L,R));
	minn[o]=min(minn[o<<1],minn[o<<1|1]);
	return res;
}}A,B;
typedef int arr[2000005];
arr t,sa;
int *r,*f,*qwq;
// arr r,f,qwq;
arr b;
int SA(int n,int *a)
{
	r=new int[2000005];
	f=new int[2000005];
//	read();
	// scanf("%s",a+1);
	int m=2;
	rg(n)a[i+n]=a[i];gr
	n+=n;
	rg(n)r[i]=a[i],f[i]=i;gr
	rg(n)t[r[i]]++;gr
	rg(m)t[i]+=t[i-1];gr
	rg(n)sa[t[r[f[n-i+1]]]--]=f[n-i+1];gr
	for(int k=1;k<=n;k<<=1)
	{
		int cc=0;
		rg(k)f[++cc]=i+n-k;gr
		rg(n)if(sa[i]>k)f[++cc]=sa[i]-k;gr
		memset(t,0,sizeof(t));
		rg(n)t[r[i]]++;gr
		rg(m)t[i]+=t[i-1];gr
		rg(n)sa[t[r[f[n-i+1]]]--]=f[n-i+1];gr
		qwq=r;r=f;f=qwq;
		r[sa[1]]=1;cc=1;
		rg(n)if(i==1)continue;
		r[sa[i]]=(f[sa[i]]==f[sa[i-1]]&&f[sa[i]+k]==f[sa[i-1]+k])?cc:++cc;
		gr if(cc==n)break;m=cc;
	}
	// rg(n)odb(sa[i]);gr
	// delete[] r;delete[] f;
	return 0;
}
signed main()
{
	scanf("%s",a+1);int n=strlen(a+1);
	int g=0;
	rg(n)if(a[i]=='(')b[i]=1;else b[i]=2;gr
	rg(n)a[i]=(a[i]=='(')?1:-1;gr
	SA(n,b);
	// rg(n)odb(r[i]);gr puts("");
	rg(n)A.add(1,1,n,i,n,a[i]);gr
	rg(n)g+=a[i];gr
	int ans=1e18,pos=0,Igon=0,Ogon=0;
	rg(n)
	int R=n-i+1,d=a[R];
	A.add(1,1,n,1,n,d);
	A.set(1,1,n,R,d);
	int s=A.que(1,1,n,1,n);
	if(s>=0)
	{
		int qwq=(g>0?g:-g);
		// ans=min(ans,);
		// assert(s==g);
		if(qwq<ans)ans=qwq,pos=R,Igon=0,Ogon=g;
		else if(qwq==ans&&r[R]<r[pos])pos=R,Igon=0,Ogon=g;
	}
	else
	{
		g+=-s;
		int qwq=(g>0?g:-g)-s;
		// ans=min(ans,);
		if(qwq<ans)ans=qwq,pos=R,Igon=-s,Ogon=qwq+s;
		else if(qwq==ans&&r[R]<r[pos])pos=R,Igon=-s,Ogon=qwq+s;
		g-=-s;
	}
	// B.add(1,1,n,)
	gr
	// oldl(ans);
	// oldl(pos);
	// oldp(Igon,Ogon);
	// assert(Igon+Ogon==ans);
	a[0]=a[n];
	rg(Igon)putchar('(');gr
	rg(n)putchar(a[(pos+i-1)%n]==1?'(':')');gr
	rg(Ogon)putchar(')');gr
	delete[] r;delete[] f;
	return 0;
}