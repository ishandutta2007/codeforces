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
#define int long long
#define newe(n) struct Edge{int v,w,nxt;}e[n*2+5];\
typedef int arr[n+5];\
arr h;\
int cnt=1;\
inline void addedge(int u,int v,int w){e[cnt]=(Edge){v,w,h[u]};h[u]=cnt++;}
#define mgs int fa[1<<22],sz[1<<22],t[1<<22];\
inline int pre(int x){return x==fa[x]?x:fa[x]=pre(fa[x]);}\
inline int u(int x,int y)\
{\
    int fx=pre(x),fy=pre(y);\
    if(fx==fy)return 0;\
    if(sz[fx]>sz[fy])fx^=fy^=fx^=fy;\
    fa[fx]=fy,sz[fy]+=sz[fx];\
    return 1;\
}
inline int read()
{
    int num=0,pre=1;char c=getchar();
    while(c<48||c>57){if(c=='-')pre=-1;c=getchar();}
    while(c>47&&c<58)num=num*10+(c^48),c=getchar();
    return num*pre;
}
inline int re1d()
{
    char c=getchar();
    while(c<48||c>49)c=getchar();
    return c&1;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
int a[1000005],pre[1000005];
struct cmll02_gun_chu_oi{
	int x,y,pre,suf,id;
	bool operator<(const cmll02_gun_chu_oi &b)const
	{
		if(x==b.x)return y<b.y;
		return x<b.x;
	}
}q[1000005];
int suf[1000005],c[1000005];
int mx[1000005],t[1000005],res[1000005],r[1000005];
inline void add(int x,int p,int n)
{
	while(x<=n)mx[x]=max(mx[x],p),x+=x&-x;
}
inline int que(int x)
{
	int res=0;
	while(x)res=max(res,mx[x]),x-=x&-x;
	return res;
}
#define _ memset(mx,0,sizeof(mx));
signed main()
{
	int n=read(),m=read();
	rg(n)a[i]=read();gr
	if(n==1){
	rg(m)int x=read(),y=read(),t=a[x];
	a[x]=y;int ans=0;
	memset(pre,0x3f,sizeof(int)*(n+3));pre[0]=-pre[0];
	rg(n)int p=std::lower_bound(pre+1,pre+1+n,a[i])-pre;
	ans=max(ans,p);
	pre[p]=min(pre[p],a[i]);gr
	oldl(ans);
	a[x]=t;gr gr
	else
	{
		rg(n)if(a[i]!=i)goto q2;gr
		rg(m)int x=read(),y=read();
		if(x==y)oldl(n);
		else if(x==n&&y>=n)oldl(n);
		else if(x==1&&y<=1)oldl(n);
		else oldl(n-1);gr
		return 0;
		q2:;
		rg(n)if(a[i]!=n-i+1)goto q3;gr
		rg(m)int x=read(),y=read();
		if(x==1)
		{
			if(y>=n-1)puts("1");
			else puts("2");
		}
		else if(x==n)
		{
			if(y>2)puts("2");
			else puts("1");
		}
		else
		{
			int d=a[x]-y;if(d<0)d=-d;
//			printf("?");odb(d);odp()
			if(d<=1)puts("1");
			else puts("2");
		}
		gr return 0;
		q3:;
		rg(n)c[i]=a[i];gr
		rg(m)q[i].x=read(),q[i].y=read();
		c[i+n]=q[i].y;gr
		std::sort(c+1,c+1+n+m);
		int l=std::unique(c+1,c+1+n+m)-c-1;
		rg(n)a[i]=std::lower_bound(c+1,c+1+l,a[i])-c;gr
		rg(m)q[i].y=std::lower_bound(c+1,c+1+l,q[i].y)-c;q[i].id=i;gr
		std::sort(q+1,q+1+m);
		rg(n)pre[i]=que(a[i]-1)+1,add(a[i],pre[i],l);gr _
		for(int i=n;i>=1;i--)suf[i]=que(l-a[i])+1,add(l-a[i]+1,suf[i],l);_
		int ans=0;rg(n)ans=max(ans,pre[i]+suf[i]-1);gr
		rg(n)if(pre[i]+suf[i]-1==ans)t[pre[i]]++;gr
		int cur=1;
		rg(m)while(cur<q[i].x)add(a[cur],pre[cur],l),cur++;
		q[i].pre=que(q[i].y-1);gr _ cur=n;
		for(int i=m;i>=1;i--){while(cur>q[i].x)add(l-a[cur]+1,suf[cur],l),cur--;
		q[i].suf=que(l-q[i].y);gr
//		rg(m)odp(q[i].pre,q[i].suf);gr
//		rg(n)odp(pre[i],suf[i]);gr odl(ans);
		rg(m)if(q[i].pre+q[i].suf==ans)res[i]=ans+1;gr
		rg(m)if(res[i]==0)if(q[i].pre+q[i].suf+1>=ans||t[pre[q[i].x]]!=1||
		pre[q[i].x]+suf[q[i].x]!=1+ans)res[i]=ans;else res[i]=ans-1;gr
		rg(m)r[q[i].id]=res[i];gr
		rg(m)oldl(r[i]);gr
	}
	return 0;
}