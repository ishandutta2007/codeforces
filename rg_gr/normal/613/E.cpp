// Problem: E. Puzzle Lover
// Contest: Codeforces - Codeforces Round #339 (Div. 1)
// URL: https://codeforces.com/problemset/problem/613/E
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
char a[2][2005],c[2005];
int h[2][2005],H[2005],p[2005];
int r[2][2005],R[2005],f[2][2005];
int n,m;
const int mod=1000000007;
const int Q=171;
void inithash(char* a,int* h,int n)
{
	rg(n)h[i]=h[i-1]*Q+a[i]-96,h[i]%=mod;gr
}
void initRhash(char* a,int* h,int n)
{
	rg(n)h[i]=h[i-1]*Q+a[n-i+1]-96,h[i]%=mod;gr
}
int hsh(int* x,int l,int r_)
{
	if(x==R||x==r[0]||x==r[1])
	{
		int t=n;
		if(x==R)t=m;
		int L=l,R=r_;
		l=t-R+1,r_=t-L+1;
	}
	return (x[r_]-x[l-1]*p[r_-l+1]%mod+mod)%mod;
}
// int rhsh(int* x,int l,int r)
// {
// 	
	// return (x[r]-x[l]*p[r-l]%mod+mod)%mod;
// }
int ans=0;
void solve()
{
	memset(f,0,sizeof(f));
	f[0][0]=f[1][0]=1;
	rg(n)
	for(int j=m;j>=1;j--)
	{
		f[0][j]=f[1][j]=0;
		if(j>=1&&a[0][i]==c[j])f[0][j]=(f[0][j]+f[0][j-1])%mod;
		if(j>=1&&a[1][i]==c[j])f[1][j]=(f[1][j]+f[1][j-1])%mod;
		if(j>=2&&a[0][i]==c[j]&&a[1][i]==c[j-1])f[0][j]=(f[0][j]+f[1][j-2])%mod;
		if(j>=2&&a[1][i]==c[j]&&a[0][i]==c[j-1])f[1][j]=(f[1][j]+f[0][j-2])%mod;
	}
	ans=(ans+f[0][m]+f[1][m])%mod;
	for(int j=i-1;j>=1;j--)
	{
		if(i+i-j-j>=m)break;
		if(hsh(r[0],j,i)==hsh(H,1,i-j+1)&&
		hsh(h[1],j,i)==hsh(H,i-j+2,i+i-j-j+2))
			f[1][i+i-j-j+2]++;//odp(1,i+i-j-j+2);
	}
	for(int j=i-1;j>=1;j--)
	{
		if(i+i-j-j>=m)break;
		if(hsh(r[1],j,i)==hsh(H,1,i-j+1)&&
		hsh(h[0],j,i)==hsh(H,i-j+2,i+i-j-j+2))
			f[0][i+i-j-j+2]++;//odp(0,i+i-j-j+2);
	}
	for(int j=i+2;j<=n;j++)
	{
		if(j+j-i-i>=m)break;
		if(hsh(h[0],i+1,j)==hsh(H,m-j-j+i+i+1,m-j+i)&&hsh(r[1],i+1,j)==hsh(H,m-j+i+1,m))ans=(ans+f[0][m-j-j+i+i])%mod,debug(i,' ',-j,'\n');
	}
	for(int j=i+2;j<=n;j++)
	{
		if(j+j-i-i>=m)break;
		if(hsh(h[1],i+1,j)==hsh(H,m-j-j+i+i+1,m-j+i)&&hsh(r[0],i+1,j)==hsh(H,m-j+i+1,m))ans=(ans+f[1][m-j-j+i+i])%mod,debug(i,' ',j,'\n');
	}
	gr
}
signed main()
{
	scanf("%s%s%s",a[0]+1,a[1]+1,c+1);
	n=strlen(a[0]+1);
	m=strlen(c+1);
	if(m==1)
	{
		int d=c[1];rg(n)ans+=(a[0][i]==d)+(a[1][i]==d);gr
		odl(ans);
		return 0;
	}else if(m==2)
	{
		rg(n)if(a[0][i]==c[1]&&a[1][i]==c[2])ans++;gr
		rg(n)if(a[0][i]==c[2]&&a[1][i]==c[1])ans++;gr
		for(int t=0;t<2;t++)
		{
			rg(n-1)ans+=(a[t][i]==c[1]&&a[t][i+1]==c[2])+(a[t][i+1]==c[1]&&a[t][i]==c[2]);gr
		}
		odl(ans);
		return 0;
	}
	// std::reverse(c+1,c+1+m);
	inithash(a[0],h[0],n);
	inithash(a[1],h[1],n);
	inithash(c,H,m);
	initRhash(a[0],r[0],n);
	initRhash(a[1],r[1],n);
	initRhash(c,R,n);
	p[0]=1;rg(n)p[i]=p[i-1]*Q%mod;gr
	// oldp(hsh(h[0],1,2),hsh(r[1],1,2));
	solve();
	int A=hsh(H,1,m>>1),B=hsh(H,m+2>>1,m);
	for(int l=1,r1=m>>1;r1<=n;l++,r1++)
	{
		if(hsh(r[0],l,r1)==A&&hsh(h[1],l,r1)==B)ans=(ans+1)%mod;
		if(hsh(r[1],l,r1)==A&&hsh(h[0],l,r1)==B)ans=(ans+1)%mod;
		if(hsh(h[0],l,r1)==A&&hsh(r[1],l,r1)==B)ans=(ans+1)%mod;
		if(hsh(h[1],l,r1)==A&&hsh(r[0],l,r1)==B)ans=(ans+1)%mod;
	}
	rg(m>>1)c[i]^=c[m-i+1]^=c[i]^=c[m-i+1];gr
	inithash(c,H,m);
	initRhash(c,R,n);
	solve();
	oldl(ans);
	return 0;
}