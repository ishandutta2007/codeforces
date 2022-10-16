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
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
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
#define forall(x) for(int i=0;i<=(x);i++){
#define rg_(i,x) for(int i=1;i<=(x);i++){
#define fe(u) for(int i=h[u];i;i=e[i].nxt){int v=e[i].v;
#define gr }
#define rrg(x) for(int i=0;i<(x);i++)
#define rdln(a) a[i]=read();
#define rdln0(a,x) rrg(x) rdln(a) gr
#define rdln1(a,x) rg(x) rdln(a) gr
#include <bitset>
// #define int long long
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
    return c;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
struct pair{
    int x,y;
    bool operator<(const pair &b)const{
        return x==b.x?y<b.y:x<b.x;
    }
};
struct GodL{
    int maxn[4000005],minn[4000005],addv[4000005];
    void pushdown(int o,int l,int r)
    {
        int &x=addv[o];
        maxn[o<<1]+=x;
        maxn[o<<1|1]+=x;
        minn[o<<1]+=x;
        minn[o<<1|1]+=x;
        addv[o<<1]+=x;
        addv[o<<1|1]+=x;
        x=0;
    }
    void maintain(int o,int l,int r)
    {
        maxn[o]=max(maxn[o<<1],maxn[o<<1|1])+addv[o];
        minn[o]=min(minn[o<<1],minn[o<<1|1])+addv[o];
    }
    void add(int o,int l,int r,int L,int R,int v)
    {
        if(L<=l&&r<=R)
        {
            maxn[o]+=v;
            minn[o]+=v;
            addv[o]+=v;
            return;
        }
        int m=l+r>>1;
        pushdown(o,l,r);
        if(L<=m)add(o<<1,l,m,L,R,v);
        if(m<R)add(o<<1|1,m+1,r,L,R,v);
        maintain(o,l,r);
    }
}t;
char a[1000005];
int g[1000005];
signed main()
{
    int n=read(),sum=0;
    scanf("%s",a+1);
    int l=1,r=1;
    rg(n)
    if(a[i]=='L')r=max(r-1,1);
    else if(a[i]=='R')r++;
    else
    {
        int d=0;
        if(a[i]=='(')
        {
            d=1;
        }
        else if(a[i]==')')
        {
            d=-1;
        }
        else 
        {
            
        }
        t.add(1,1,n,r,n,d-g[r]);
        // printf("debug %d %d\n",r,d-g[r]);
        sum+=d-g[r];
        g[r]=d;
        // odp(sum,d);
    }
    // odb(sum);//odp(l,r);
    // odb(t.minn[1]);
    // odp(l,r);
    if(sum||t.minn[1])odb(-1);else odb(t.maxn[1]);
    gr
	return 0;
}
/*

# $$
*/