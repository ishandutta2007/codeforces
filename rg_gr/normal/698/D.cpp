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
int n=read(),k=read();
int a[9],b[9];
int x[1000005],y[1000005];
int pre[9][1000005];
#include <vector>
#include <map>
int xx(int x,int y)
{
	int A=(x>0?1:(x<0?-1:0));
	int B=(y>0?1:(y<0?-1:0));
	if(A==-1&&B==1)return 3; if(A==0&&B==1)return 2; if(A==1&&B==1)return 1;
	if(A==-1&&B==0)return 4; if(A==0&&B==0)return 8; if(A==1&&B==0)return 0;
	if(A==-1&&B==-1)return 5; if(A==0&&B==-1)return 6; if(A==1&&B==-1)return 7;
}
struct G{
	int x,y;
	int id()const
	{
		return xx(x,y);
	}
	double dis;
	bool operator<(const G& b)const{
		if(id()!=b.id())return id()<b.id();
		return x*b.y<y*b.x;
	}
	int dist(){return x*x+y*y;}
};
struct comp{
	int id,dist;
	bool operator<(const comp &b)const{
		return dist<b.dist;
	}
};
std::map<G,std::vector<comp> >mp[8];
void preinit(int cx,int cy,int *go,std::map<G,std::vector<comp> >&mp)
{
	rg(k)
	G t=(G){x[i]-cx,y[i]-cy};
	mp[t].push_back((comp){i,t.dist()});
	gr
	for(auto x:mp)
	{
		auto& y=x.second;
		std::sort(y.begin(),y.end());
		int f=0;
		for(auto z:y)go[z.id]=f,f=z.id;
	}
	// rg(k)odb(go[i]);gr puts("");
}
int ans[1000005];
int d[1000005];
int qwqwq;
int solve(int *p,int n,int i,int P)
{
	if(n<=0)return -1;
	int j=i;
	int k=n;
	n--;
	while(pre[p[k]][j])
	{
		if(d[pre[p[k]][j]]==P)
		{
			j=pre[p[k]][j];
			continue;
		}
		n=solve(p,n,j=pre[p[k]][j],P);
		if(n==-1)return -1;
	}
	ans[i]=1;
	// rg(3)odb(p[i]);gr odb(k),odp(n,i);
	d[i]=P;
	return n;
}
// #include <assert.h>
signed main()
{
	rg(n)a[i]=read();b[i]=read();gr
	rg(k)x[i]=read();y[i]=read();gr
	rg(n)preinit(a[i],b[i],pre[i],mp[i]);gr
	int p[8]={0,1,2,3,4,5,6,7};do{
		rg(k)solve(p,n,i,++qwqwq);
		// puts("");
		// solve(p,n,i,0);
		// puts("\n");
		// rg(k)assert(d[i]==0);gr
		gr
	}while(std::next_permutation(p+1,p+1+n));
	// rg(k)odb(ans[i]);gr
	int s=0;rg(k)s+=ans[i];gr odl(s);
	return 0;
}