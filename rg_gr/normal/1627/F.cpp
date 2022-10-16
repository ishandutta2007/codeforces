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
    while(c<48||c>49)c=getchar();
    return c&1;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
struct qwq{
	int x,y,d;
	bool operator<(const qwq&b)const{return d>b.d;}
};
int g[505][505][4],G[505][505][4];
int d[505][505];
int fr[505][505];
#define U 0
#define D 1
#define L 2
#define R 3
signed main()
{
	int T=read();rg(T)
	int n=read(),k=read();
	for(int i=0;i<=k;i++)
		for(int j=0;j<=k;d[i][j]=0x3f3f3f3f,j++)
			for(int k=0;k<4;k++)
				g[i][j][k]=0;
	rg(n)
	int a=read(),b=read(),c=read(),d=read();
	if(a==c)
	{
		b=min(b,d);
		g[a-1][b][D]++;
		g[a][b][U]++;
	}else{
		a=min(a,c);
		g[a][b-1][R]++;
		g[a][b][L]++;
	}
	gr
	for(int i=0;i<=k;i++)
		for(int j=0;j<=k;j++)
			for(int K=0;K<4;K++)
				G[i][j][K]=
				g[i][j][K]+
				g[k-i][k-j][K^1]
				//,printf("%d %d %d : %d\n",i,j,K,G[i][j][K])
				;
	std::priority_queue<qwq>q;
	q.push((qwq){0,0,0});d[0][0]=0;
	while(!q.empty())
	{
		qwq p=q.top();q.pop();
		int x=p.x,y=p.y,ds=p.d,*t=G[x][y];
		if(x>0&&d[x-1][y]>ds+t[U])d[x-1][y]=ds+t[U],q.push((qwq){x-1,y,d[x-1][y]}),fr[x-1][y]='U';
		if(x<k&&d[x+1][y]>ds+t[D])d[x+1][y]=ds+t[D],q.push((qwq){x+1,y,d[x+1][y]}),fr[x+1][y]='D';
		if(y>0&&d[x][y-1]>ds+t[L])d[x][y-1]=ds+t[L],q.push((qwq){x,y-1,d[x][y-1]}),fr[x][y-1]='L';
		if(y<k&&d[x][y+1]>ds+t[R])d[x][y+1]=ds+t[R],q.push((qwq){x,y+1,d[x][y+1]}),fr[x][y+1]='R';
	}
	// for(int i=0;i<=k;i++,puts(""))
		// for(int j=0;j<=k;j++)odb(d[i][j]);
		// puts("");
	// for(int i=0;i<=k;i++,puts(""))
		// for(int j=0;j<=k;j++)putchar(fr[i][j]?fr[i][j]:' ');
	odl(n-d[k>>1][k>>1]);
	gr
	return 0;
}