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
#define rg__(i,x) for(int i=0;i<=(x);i++){
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
int cnt=2;\
inline void addedge(int u,int v,int w){e[cnt]=(Edge){v,w,h[u]};h[u]=cnt++;}//if(w)odb(u),odp(v,w);}
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
    while(c<'A'||c>'B')c=getchar();
    return c&1;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
newe(100005);
// int n,m;
arr dis,vis,cur;
int bfs(int s,int t)
{
    std::queue<int>q;
    // rg(2005)dis[i-1]=0;gr
    // rg(2005)vis[i-1]=0;gr
    memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));
    q.push(s);vis[s]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();cur[u]=h[u];
        if(u==t)return 1;
        fe(u)if(e[i].w==0||vis[v])continue;
        vis[v]=1,dis[v]=dis[u]+1,q.push(v);gr
    }
    return 0;
}
int dfs(int u,int t,int flow)
{
    if(u==t||flow==0)return flow;
    int res=0;
    for(int i=cur[u];i;cur[u]=i=e[i].nxt){int v=e[i].v;
    if(e[i].w==0||dis[u]+1!=dis[v])continue;
    int x=dfs(v,t,min(flow,e[i].w));
    flow-=x;
    e[i].w-=x;
    e[i^1].w+=x;
    res+=x;
    if(flow==0)return res;
    gr
    if(res==0)cur[u]=0;
    return res;
}
int flow(int s,int t)
{
    int ans=0;
    while(bfs(s,t))ans+=dfs(s,t,0x3f3f3f3f3f3f3f3fll);
    // oldl(ans);
    return ans;
}
int fa[200005],fb[200005];
int la[10005],lb[10005];
namespace qwq{
    newe(200005);
    arr sz;
    void dfs(int u,int fa)
    {
        sz[u]=1;
        fe(u)if(v!=fa)dfs(v,u),sz[u]+=sz[v];gr
    }
}
signed main()
{
    int leaf=read();
    int n=read();
    rg(n-1)fa[i+1]=read();gr
    rg(leaf)la[i]=read();gr
    int m=read();
    rg(m-1)fb[i+1]=read();gr
    rg(leaf)lb[i]=read();gr
    rg(n)if(i>1)addedge(0,i,1),addedge(i,0,0);gr
    rg(m)if(i>1)addedge(i+n,n+m+1,1),addedge(n+m+1,i+n,0);gr
    // rg(n)addedge
    // rg(n-1)qwq::addedge(fa[i+1],i+1,1);gr
    // qwq::dfs(1,1);
    // rg(n)addedge(1,i,qwq::sz[i]);addedge(i,1,0);gr
    // memset(qwq::h,0,sizeof(qwq::h));qwq::cnt=1;
    // rg(m-1)qwq::addedge(fb[i+1],i+1,1);gr
    // qwq::dfs(1,1);
    // rg(m)addedge(i+n,n+1,qwq::sz[i]);addedge(n+1,i+n,0);gr
    rg(leaf)addedge(la[i],lb[i]+n,0x3f3f3f3f),addedge(lb[i]+n,la[i],0);gr
    rg(n-1)addedge(fa[i+1],i+1,0x3f3f3f3f),addedge(i+1,fa[i+1],0);gr
    rg(m-1)addedge(fb[i+1]+n,i+1+n,0),addedge(n+i+1,fb[i+1]+n,0x3f3f3f3f);gr
    oldl(n+m-2-flow(0,n+m+1));
	return 0;;
}

/*
3
6
4 1 1 4 2
6 5 3
4
1 1 1
3 4 2

--

0
6
6
4
5
6
1
5
5
1
*/