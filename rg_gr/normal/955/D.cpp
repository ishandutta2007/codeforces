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
    while(c<48||c>49)c=getchar();
    return c&1;
}
#define int long long
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
#undef int
int k;
struct SAM{
	int ch[1000005][26],lnk[1000005],len[1000005],lst=1,cc=1,id=0;
	// int sz[1000005];
	int endpos[1000005],tmpend[1000005];
	newe(1000005);
	void clear()
	{
		//zenmezhemeduodongxia ?
		rg(cc)rg_(j,26)ch[i][j-1]=0;gr gr
		rg(cc)lnk[i]=len[i]=endpos[i]=h[i]=0;gr
		cnt=1;
		lst=cc=1,id=0;
	}
	void insert(int c)
	{
		len[++cc]=len[lst]+1;//sz[cc]=1;
		endpos[cc]=++id;
		tmpend[cc]=id;
		if(id<k)endpos[cc]=0x3f3f3f3f;
		int p=lst;lst=cc;
		while(p&&ch[p][c]==0)ch[p][c]=cc,p=lnk[p];
		if(p==0)lnk[cc]=1;
		else
		{
			int x=ch[p][c];
			if(len[p]+1==len[x])lnk[cc]=x;
			else
			{
				int q=cc;++cc;
				lnk[cc]=lnk[x];
				lnk[x]=lnk[q]=cc;
				len[cc]=len[p]+1;
				memcpy(ch[cc],ch[x],sizeof(ch[cc]));
				while(p&&ch[p][c]==x)ch[p][c]=cc,p=lnk[p];
			}
		}
	}
	long long ans;
	void build()
	{
		rg(cc)addedge(lnk[i],i,0);gr
	}
	void dfs(int u)
	{
		if(!endpos[u])endpos[u]=0x3f3f3f3f;
		if(!tmpend[u])tmpend[u]=0x3f3f3f3f;
		fe(u)dfs(v),endpos[u]=min(endpos[u],endpos[v]);gr
		// if(sz[u]>1)ans=max(ans,1ll*sz[u]*len[u]);
	}
}sam;
char a[1000005],b[1000005];
int ans0[1000005],ans1[1000005];
signed main()
{
	int n=read(),m=read();k=read();
	// if(n==500000&&m==500000)
	scanf("%s%s",a+1,b+1);//int n=strlen(a+1);
	rg(n)sam.insert(a[i]-97);gr
	sam.build();sam.dfs(1);//oldl(sam.ans);
	int o=1;
	rg(min(m,k))
	o=sam.ch[o][b[i]-97];
	if(o==0)break;
	ans0[i]=sam.endpos[o];
	gr
	// rg(m)odb(ans0[i]);gr puts("");
	if(ans0[m])
	{
		int pos=max(sam.tmpend[o],k);
		if(pos+k<=n)
		{
			puts("Yes");
			odp(pos-k+1,pos+1);
			return 0;
		}
	}
	sam.clear();
	std::reverse(a+1,a+1+n);
	std::reverse(b+1,b+1+m);
	rg(n)sam.insert(a[i]-97);gr
	
	sam.build();sam.dfs(1);//oldl(sam.ans);
	o=1;
	rg(min(m,k))
	o=sam.ch[o][b[i]-97];
	if(o==0)break;
	ans1[m-i+1]=n-sam.endpos[o]+1;
	gr

	if(ans0[m])
	{
		int pos=min(n-sam.tmpend[o]+1,n-k+1);
		if(pos+k-1<=n&&pos>=k+1)
		{
			puts("Yes");
			odp(pos-k,pos);
			return 0;
		}
	}
	// rg(m)odb(ans1[i]);gr
	sam.clear();
	// if(ans0[m]&&ans0[m]+k<=n)
	// {
		// puts("Yes");
		// odp(ans0[m]-k+1,ans0[m]+1);
		// return 0;
	// }
	// if(ans1[1]&&ans1[1]+k-1<=n)
	// {
		// puts("Yes");
		// odp(ans1[1]-k,ans1[1]);
		// return 0;
	// }
	rg(m-1)if(ans0[i]&&ans0[i]<ans1[i+1]&&i+k>=m&&i<=k)
	{
		puts("Yes");//odl(i);
		// odl(i);
		odp(ans0[i]-k+1,ans1[i+1]);
		return 0;
	}gr 
	puts("No");
	return 0;
}