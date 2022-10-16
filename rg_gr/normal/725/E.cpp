// Problem: E. Too Much Money
// Contest: Codeforces - Canada Cup 2016
// URL: https://codeforces.com/problemset/problem/725/E
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
#define int long long
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
int a[1000005],b[1000005],f[1000005],lst[1000005];
struct GodL{
	int sum[800005];
	void add(int o,int l,int r,int p,int v)
	{
		if(l==r)sum[o]+=v;
		else
		{
			int m=l+r>>1;
			if(p<=m)add(o<<1,l,m,p,v);
			else add(o<<1|1,m+1,r,p,v);
			sum[o]=sum[o<<1]+sum[o<<1|1];
		}
	}
	struct res{
		int a,b;
	};
	int query(int o,int l,int r,int K,int &s)
	{
		if(l==r)return l;
		int m=l+r>>1;
		if(sum[o<<1|1]>=K)return query(o<<1|1,m+1,r,K,s);
		s+=sum[o<<1|1],K-=sum[o<<1|1];
		return query(o<<1,l,m,K,s);
	}
	int suum(int o,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R)return sum[o];
		int m=l+r>>1,res=0;
		if(L<=m)res+=suum(o<<1,l,m,L,R);
		if(m<R)res+=suum(o<<1|1,m+1,r,L,R);
		return res;
	}
}t;
int T[1000005];
signed main()
{
	int c=read();int n=read();
	rg(n)a[i]=read();T[a[i]]++;gr
	rg(n)t.add(1,1,200000,a[i],a[i]);gr
	int ans=-1;
	for(int i=200000;i>=1;i--){
	// for(int i=62;i>=62;i--){
	int sum=0;
	t.add(1,1,200000,i,i);
	T[i]++;
	int C=c,cur=200000;
	while(C)
	{
		cur=min(cur,C);
		int l=1,r=cur+1,ans=-1;
		while(l<=r)
		{
			int m=l+r>>1;
			if(t.suum(1,1,200000,m,cur)<=C)ans=m-1,r=m-1;
			else l=m+1;
		}
		// odl(ans);
		if(ans==0)
		{
			if(t.suum(1,1,200000,ans+1,cur)<C)cur=-11;
			break;
		}
		// if(ans==1)break;
		C-=t.suum(1,1,200000,ans+1,cur);
		// ans--;
		if(ans==-1||T[ans]==0&&ans==cur)
		{
			cur=-11;
			break;
		}
		// if(ans>m)C%=ans;
		C%=ans;
		// odp(C,ans);
		// if(C==0)break;
		// if(ans>cur&&C)
		// {
			// cur=-11;
			// goto fail;
		// }
		cur=ans-1;
		// if(cur>C?)
	}
	// int r=t.query(1,1,200000,c,sum);
	// // odl(sum);
	// // assert(sum<=c);
	// if((c-sum)%(r-1)==0)ans=i;
	fail:;
	if(cur==-11)ans=i;
	t.add(1,1,200000,i,-i);
	T[i]--;
	gr
	// odl(ans);
	// std::sort(a+1,a+1+n);
	// b[0]=1;
	// a[1+n]=c+1;
	// rg(n)for(int j=a[i+1]-1;j>=a[i];j--)b[j]=b[j-a[i]],f[j]=i;
// 	
	// rg(12)odb(f[i]);gr puts("");
	// rg(12)odb(b[i]);gr puts("");
	// rg(12)odb(lst[i]);gr puts("");
	// puts("");
	// gr
	// lst[0]=-1;
	// rg(n)
	// if(b[i])lst[i]=lst[i-1];
	// else lst[i]=i;
	// gr
	// int ans=0x3f3f3f3f;
	// rg(12)odb(f[i]);gr puts("");
	// rg(12)odb(b[i]);gr puts("");
	// rg(12)odb(lst[i]);gr puts("");
	// while(c)
	// {
		// // (f[c],c)
		// int t=lst[c-f[c]];
		// if(t!=-1)ans=min(ans,c-t);
		// c-=f[c];
	// }
	if(ans==-1)puts("Greed is good");
	else odl(ans);
	return 0;
}