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
#define int long long
#define newe(n) struct Edge{int v,w,nxt;}e[2*n+5];\
typedef int arr[n+5];\
arr h;\
int cnt=1;\
inline void addedge(int u,int v,int w){e[cnt]=(Edge){v,w,h[u]};h[u]=cnt++;\
}
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
    while(c<48||c>49)c=getchar();
    return c&1;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
const int G=300005;
struct BIT{
    int a[300005];
    void add(int x,int p)
    {
        while(x<=G)a[x]+=p,x+=x&-x;
    }
    int operator[](int x){int res=0;while(x>0)res+=a[x],x-=x&-x;return res;}
    int operator()(int l,int r){return (*this)[r]-(*this)[l-1];}
}t1,t2,t3;
signed main()
{
    int n=read();
    // pre % x
    int ans=0;
    rg(n)int x=read();//odl(x);
    // rg(10)odb(t2[i]);gr puts("");
    for(int l=0,r=x-1;l<=G;l+=x,r+=x,r=min(r,G))ans+=t2(l,r)-l*t1(l,r);//printf("%d %d %d %d\n",l,r,t2(l,r),t1(l,r));
    t2.add(x,x);//t2.add(x+1,-x);
    t1.add(x,1);//t1.add(x+1,-1);
    ans+=(i-1)*x-t3[x];
    for(int l=0,r=x-1;l<=G;l+=x,r+=x,r=min(r,(G)))t3.add(max(l,1),l/x*x),t3.add(r+1,-l/x*x);
    oldb(ans);
    gr
    return 0;
}
/*
 ______      _    __    __      _
/_____ \    | |  / /    \ \    / /
     / /    | | / /      \ \  / /
    / /     | |/ /        \ \/ /
   / /      |   /          \  /
  / /       |   \          |  |
 / /        | |\ \         |  |
/ /_____    | | \ \        |  |
\______/    |_|  \_\       |__|

   AAAA     KK    KK
  AA  AA    KK  KK
 AA    AA   KKKK
 AAAAAAAA   KKK
 AA    AA   KKKK
 AA    AA   KK  KK
 AA    AA   KK    KK

IIIIIII     OOO      IIIIIII
   I       O   O        I
   I      O     O       I
   I     O       O      I
   I     O       O      I
   I      O     O       I
   I       O   O        I
IIIIIII     OOO      IIIIIII

*/