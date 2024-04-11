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
    while(c<'A'||c>'B')c=getchar();
    return c&1;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
newe(100005);
arr qv,cur,d;
int bfs(int s,int t)
{
    memset(qv,0,sizeof(qv));
    memset(d,0,sizeof(d));
    memcpy(cur,h,sizeof(cur));
    std::queue<int>q;
    q.push(s);
    qv[s]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        fe(u)if(!qv[v]&&e[i].w)qv[v]=1,d[v]=d[u]+1,q.push(v);gr
    }
    return qv[t];
}
int dfs(int u,int t,int flow)
{
    if(u==t||flow==0)return flow;
    int res=0;
    for(int& i=cur[u];i;i=e[i].nxt)
    {
        int v=e[i].v;
        if(d[u]+1!=d[v]||e[i].w==0)continue;
        int g=dfs(v,t,min(flow,e[i].w));
        e[i].w-=g;
        e[i^1].w+=g;
        res+=g;
        flow-=g;
        if(flow==0)return res;
        // if(!g)return res;
    }
    if(res==0)cur[u]=0;
    return res;
}
arr a,b,lst;
signed main()
{
    int n=read(),s=0,t=n+1;
    int ans=0;
    rg(n)a[i]=read();
    for(int j=1;j<=a[i];j++)if(lst[j]&&a[i]%j==0)addedge(i,lst[j],0x3f3f3f3f),addedge(lst[j],i,0);
    lst[a[i]]=i;
    gr
    rg(n)ans+=max(0,b[i]=read());
    if(b[i]>0)addedge(s,i,b[i]),addedge(i,s,0);
    else addedge(i,t,-b[i]),addedge(t,i,0);
    gr
    while(bfs(s,t))ans-=dfs(s,t,0x3f3f3f3f3f3f3f3fll);
    oldl(ans);
	return 0;
}

/*

*/