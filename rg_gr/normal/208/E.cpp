//  /

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
#define nullptr NULL
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
struct Node
{
	Node *lc,*rc;
	int sum;
	Node(){lc=rc=NULL,sum=0;}
	Node(int x):sum(x){}
}*root[1000005],*rot[1000005];
inline void maintain(Node *&o,int l,int r)
{
	if(l==r)return;
	o->sum=0;
	if(o->lc)o->sum+=o->lc->sum;
	if(o->rc)o->sum+=o->rc->sum;
}
Node* merge(Node *&a,Node *b,int l,int r)
{
	if(a==nullptr)return a=b;
	if(b==nullptr)return a;
	if(l==r)
	{
		a->sum+=b->sum;
		return a;
	}
	int m=l+r>>1;
	a->lc=merge(a->lc,b->lc,l,m);
	a->rc=merge(a->rc,b->rc,m+1,r);
	maintain(a,l,r);
	return a;
}
void insert(Node *&o,int l,int r,int p,int v)
{
	if(o==nullptr)o=new Node();
	if(l==r)
	{
		o->sum+=v;
		return;
	}
	int m=l+r>>1;
	if(p<=m)insert(o->lc,l,m,p,v);
	else insert(o->rc,m+1,r,p,v);
	maintain(o,l,r);
}
newe(1000005);
int pigstd=100000;
int fa[1000005][22],dep[1000005],sz[1000005];
void dfs(int u,int fa_)
{
	dep[u]=dep[fa_]+1;
	fa[u][0]=fa_;sz[u]=1;
	for(int i=1;(1<<i)<=dep[u];i++)fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=h[u];i;i=e[i].nxt)if(e[i].v!=fa_)dfs(e[i].v,u),sz[u]+=sz[e[i].v];
}
// void cpy(Node *&o,Node *p)
// {
	// if(p==nullptr)return;
	// if(o==nullptr)o=new Node();
	// o->sum=p->sum;
	// cpy(o->lc,p->lc);
	// cpy(o->rc,p->rc);
// }
#include <vector>
std::vector<int> v[1000005];
int query(Node *o,int l,int r,int L,int R)
{
	if(o==nullptr)return 0;
	if(L<=l&&r<=R)return o->sum;
	int m=l+r>>1;
	int s=0;
	if(L<=m)s+=query(o->lc,l,m,L,R);
	if(m<R)s+=query(o->rc,m+1,r,L,R);
	return s;
}
inline int getfa(int a,int d)
{
	for(int i=0;i<22;i++)if((d>>i)&1)a=fa[a][i];
	return a;
}
int k[1000005],ans[1000005];
void pigstd_AK_IOI(int u,int fa)
{
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa)continue;
		pigstd_AK_IOI(v,u);
		merge(root[u],root[v],1,pigstd);
	}
	if(u==1)return;
	for(auto i:v[u])
	{
		int K=k[i];
		ans[i]=query(root[u],1,pigstd,dep[u]+K,dep[u]+K);
	}
//	cpy(rot[u],root[u]);
}
signed main()
{
	int n=read();pigstd=n+1;
	rg(n)int x=read();addedge(x+1,i+1,1);gr
	n++;int m=read();
	dfs(1,0);
	rg(n)insert(root[i],1,n,dep[i],1);gr
	rg(m)
	int a=read()+1;k[i]=read();
	a=getfa(a,k[i]);
	v[a].push_back(i);gr
	pigstd_AK_IOI(1,1);
	rg(m)odb(max(ans[i]-1,0));gr
	return 0;
}