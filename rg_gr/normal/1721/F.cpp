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
#define newe(n) struct Edge{int v,w,nxt,d;}e[2*n+5];\
typedef int arr[n+5];\
arr h;\
int cnt=2;\
inline void addedge(int u,int v,int w,int d=0){e[cnt]=(Edge){v,w,h[u],d};h[u]=cnt++;}
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
newe(1000005);
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
int vis[1234567];
void dfs(int u)
{
	vis[u]=1;
	fe(u)if(!vis[v]&&e[i].w==1)dfs(v);gr
}
int st[1234567],cc;
signed main()
{
    int n=read(),m=read(),k=read(),q=read(),
    s=0,t=n+m+1;
    rg(k)int u=read(),v=read()+n;
    addedge(u,v,1,i),addedge(v,u,0,i);
    
    gr
    rg(n)addedge(s,i,1),addedge(i,s,0);gr
    rg(m)addedge(i+n,t,1),addedge(t,i+n,0);gr
    int ans=0;while(bfs(s,t))ans+=dfs(s,t,0x3f3f3f3f3f3f3f3f);
    // oldl(ans);
    rg_(u,n+m)
    if(u<=n);else continue;
    int l=0;fe(u)if(e[i].v==s&&e[i].w==1||e[i].v==t&&e[i].w==0)l=1;gr
    // odl(l);
    if(!l&&!vis[u])dfs(u);
    gr
    rg(n)vis[i]^=1;gr
    // rg(n+m)odb(vis[i]);gr puts("");
    rg(n+m)if(vis[i]==1)st[++cc]=i;gr
    // rg(cc)odb(st[i]);gr puts("");
    int sum=0;
    std::set<int>sd;
    rg_(u,n)fe(u)if(e[i].v>n&&e[i].w==0)sum+=e[i^1].d,sd.insert(e[i].d);gr gr
  // odl(sum);
  // return 0;
  cc=0;
    rg(q)
    int x=read();
    // odl(x);continue;
    if(x==1)
    {
    	int i=st[++cc];
    	odl(1);
    	odl(i<=n?i:n-i);
    	int u=i;
    	fe(u)
    	if(v==s||v==t)continue;
    	if(u>n&&e[i].w==1||u<=n&&e[i].w==0)
    		sum-=e[i].d,
    		sd.erase(e[i].d);
    	gr
    	oldl(sum);
    }
    else
    {
    	odl(ans-cc)
;
for(auto x:sd)odb(x);puts("");
    }
    // puts("===");
    fflush(stdout);
    gr
	return 0;
}

/*

*/