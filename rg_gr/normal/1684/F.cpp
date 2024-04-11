// Problem: F. Diverse Segments
// Contest: Codeforces - Codeforces Round #792 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1684/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// Problem: B. Lynyrd Skynyrd
// Contest: Codeforces - Codeforces Round #549 (Div. 1)
// URL: https://codeforces.com/contest/1142/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//  - ~/

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
#ifndef ONLINE_JUDGE
#define DEBUG
#endif
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <assert.h>
#include <set>
#define nln puts("")
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
#define rrg(x) for(int i=0;i<(x);i++){
#define rdln(a) a[i]=read();
#define rdln0(a,x) rrg(x) rdln(a) gr
#define rdln1(a,x) rg(x) rdln(a) gr
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
#ifdef DEBUG
template<typename T>
void debug(T x){}
template<>
void debug<int>(int x){od(x);}
template<>
void debug<const int>(const int x){od(x);}
template<>
void debug<long long>(long long x){old(x);}
template<>
void debug<const long long>(const long long x){old(x);}
template<>
void debug<char>(char x){putchar(x);}
template<>
void debug<const char>(const char x){putchar(x);}
template<>
void debug<double>(double x){printf("%.12lf",x);}
template<typename T,typename... qwq>
void debug(T x,qwq ...args)
{
	debug(x);
	debug(args...);
}
#define dflush fflush
#else
#define dflush(...) 0
template<typename T,typename... qwq>
void debug(T x,qwq ...args)
{
	
}
#endif

//#define int long long
const int mod=998244353;
#ifdef int 
#define inf 0x3f3f3f3f3f3f3f3fll
#else 
#define inf 0x3f3f3f3f
#endif
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
//#define SEGTTTTT
#ifdef SEGTTTTT
#define cmlSEGMIN
#define cmlSEGMAX
#define cmlSEGSUM
class SegTreeAl{
#ifdef cmlSEGMIN
	int minn[1000005<<2];
#endif
#ifdef cmlSEGMAX
	int maxn[1000005<<2];
#endif
#ifdef cmlSEGSUM
	int sum[1000005<<2];
#endif
	int tag[1000005<<2];
#ifdef cmlSEGSUM
	void pushdown(int o,int l,int r)
#else 
	void pushdown(int o)
#endif
	{
		int&t=tag[o];
#ifdef cmlSEGMIN
		minn[o<<1]+=t;
		minn[o<<1|1]+=t;
#endif
#ifdef cmlSEGMAX
		maxn[o<<1]+=t;
		maxn[o<<1|1]+=t;
#endif
#ifdef cmlSEGSUM
		int m=l+r>>1;
		sum[o<<1]+=t*(m-l+1);
		sum[o<<1|1]+=t*(r-m);
#endif
		tag[o<<1]+=t;
		tag[o<<1|1]+=t;
		t=0;
	}
	void add(int o,int l,int r,int L,int R,int v)
	{
		if(L<=l&&r<=R)
		{
#ifdef cmlSEGMAX
			maxn[o]+=v;
#endif
#ifdef cmlSEGMIN
			minn[o]+=v;
#endif
#ifdef cmlSEGSUM
			sum[o]+=v*(r-l+1);
#endif
			tag[o]+=v;
			return;
		}
		int m=l+r>>1;
#ifdef cmlSEGSUM
		pushdown(o,l,r);
#else
		pushdown(o);
#endif
		if(L<=m)add(o<<1,l,m,L,R,v);
		if(m<R)add(o<<1|1,m+1,r,L,R,v);
#ifdef cmlSEGMAX
		maxn[o]=max(maxn[o<<1],maxn[o<<1|1]);
#endif
#ifdef cmlSEGMIN
		minn[o]=min(minn[o<<1],minn[o<<1|1]);
#endif
#ifdef cmlSEGSUM
		sum[o]=sum[o<<1]+sum[o<<1|1];
#endif
	}
#ifdef cmlSEGMIN
	int qmin(int o,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R)
		{
			return minn[o];
		}
		int m=l+r>>1,res=inf;
#ifdef cmlSEGSUM
		pushdown(o,l,r);
#else
		pushdown(o);
#endif
		if(L<=m)res=min(res,qmin(o<<1,l,m,L,R));
		if(m<R)res=min(res,qmin(o<<1|1,m+1,r,L,R));
		return res;
	}
#endif

#ifdef cmlSEGMAX
	int qmax(int o,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R)
		{
			return maxn[o];
		}
		int m=l+r>>1,res=-inf;
#ifdef cmlSEGSUM
		pushdown(o,l,r);
#else
		pushdown(o);
#endif
		if(L<=m)res=max(res,qmax(o<<1,l,m,L,R));
		if(m<R)res=max(res,qmax(o<<1|1,m+1,r,L,R));
		return res;
	}
#endif

#ifdef cmlSEGSUM
	int qsum(int o,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R)
		{
			return sum[o];
		}
		int m=l+r>>1,res=0;
#ifdef cmlSEGSUM
		pushdown(o,l,r);
#else
		pushdown(o);
#endif
		if(L<=m)res+=qsum(o<<1,l,m,L,R);
		if(m<R)res+=qsum(o<<1|1,m+1,r,L,R);
		return res;
	}
#endif
};
#endif
#define newe(n) struct Edge{int v,w,nxt;}e[2*n+5];\
typedef int arr[n+5];\
arr h;\
int cnt=1;\
inline void addedge(int u,int v,int w){e[cnt]=(Edge){v,w,h[u]};h[u]=cnt++;}\
struct node{\
	int u,d;\
	bool operator<(const node&b)const{return d>b.d;}\
};\
void dij(int s,int *d,int N)\
{\
	memset(d,0x3f,sizeof(int)*(N+3));\
	d[s]=0;std::priority_queue<node>q;q.push((node){s,0});\
	while(!q.empty())\
	{\
		int u=q.top().u,D=q.top().d;q.pop();if(D!=d[u])continue;\
		for(int i=h[u];i;i=e[i].nxt){int v=e[i].v,w=e[i].w;\
		if(d[u]+w<d[v])d[v]=d[u]+w,q.push((node){v,d[v]});\
		}\
	}\
}
#define mgs int fa[1<<22],sz[1<<22];\
inline int f(int x){return x==fa[x]?x:fa[x]=f(fa[x]);}\
inline int uf(int x,int y)\
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
#ifdef cmlBIT
struct BIT{int a[1<<20|1],n;
void add(int x,int p){while(x<=n)a[x]+=p,x+=x&-x;}
int operator[](int x){int res=0;while(x)res+=a[x],x-=x&-x;return res;}
int operator()(int l,int r){return (*this)[r]-(*this)[l-1];}};
#endif
int rnv[1000005];
// #define COMB
#ifdef COMB
#ifndef int
#define int long long
#endif
int fac[1000005],inv[1000005];
#endif
void initprog()
{
#ifdef COMB
	fac[0]=inv[0]=inv[1]=1;
	rg(1000000)fac[i]=fac[i-1]*i%mod;gr
	rg(1000000)if(i>1)inv[i]=inv[mod%i]*(mod-mod/i)%mod;gr
	rg(1000000)rnv[i]=inv[i];gr
	rg(1000000)inv[i]=inv[i]*inv[i-1]%mod;gr
#endif
}
#ifdef COMB
int C(int n,int m)
{
	if(n==m||m==0)return 1;
	if(n<m)return 0;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
#endif
inline int qp(int a,int b){int c=1;while(b){if(b&1)c=c*a%mod;a=a*a%mod;b>>=1;}return c;}
inline int mae(int &a,int b){a+=b;if(a>=mod)a-=mod;return a;}
inline int mde(int &a,int b){a+=mod-b;if(a>=mod)a-=mod;return a;}
inline int mle(int &a,int b){a=a*b%mod;return a;}
inline int mve(int &a,int b){a=a*qp(b,mod-2)%mod;return a;}
inline int mxe(int &a,int b){return a=a>b?a:b;}
inline int mne(int &a,int b){return a=a<b?a:b;}
inline int ae(int a,int b){int c=a+b;return c>=mod?c-mod:c;}
inline int de(int a,int b){return ae(a,mod-b);}
inline int me(int a,int b){return a*b%mod;}
inline int mive(int &a,int b){a=a*rnv[b]%mod;return a;}
inline int ive(int a,int b){return a*rnv[b]%mod;}
inline int ve(int a,int b){return a*qp(b,mod-2)%mod;}
#ifdef cmlST
struct STmin{
	int a[21][1000005],n;
	void init(int N,int *b)
	{
		n=N;
		rg(n)a[0][i]=b[i];gr
		rg(20)rg_(j,n-(1<<i)+1)a[i][j]=min(a[i-1][j],a[i-1][j+(1<<i-1)]);gr gr
	}
	int q(int l,int r)
	{
		int d=std::__lg(r-l+1);
		return min(a[d][l],a[d][r-(1<<d)+1]);
	}
};
struct STmax{
	int a[21][1000005],n;
	void init(int N,int *b)
	{
		n=N;
		rg(n)a[0][i]=b[i];gr
		rg(20)rg_(j,n-(1<<i)+1)a[i][j]=max(a[i-1][j],a[i-1][j+(1<<i-1)]);gr gr
	}
	int q(int l,int r)
	{
		int d=std::__lg(r-l+1);
		return max(a[d][l],a[d][r-(1<<d)+1]);
	}
};
#endif
#ifdef cmlSAM
struct SAM{
	int ch[1000005][26],lnk[1000005],len[1000005],lst=1,cc=1;
	int sz[1000005];
	void insert(int c)
	{
		len[++cc]=len[lst]+1;sz[cc]=1;
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
	newe(1000005);
	long long ans;
	void build()
	{
		rg(cc)addedge(lnk[i],i,0);gr
	}
	void dfs(int u)
	{
		fe(u)dfs(v),sz[u]+=sz[v];gr
		if(sz[u]>1)ans=max(ans,1ll*sz[u]*len[u]);
	}
}t;
#endif
#define suf nxt
int a[1000005],b[1000005],o[1000005],pre[1000005],nxt[1000005],n;
struct SegTreeAl{
	std::set<int>s[800005];
	void set(int o,int l,int r,int p,int v)
	{
		if(l==r)
		{
			// minn[o]=min(minn[o],v);
			s[o].insert(v);
			return;
		}
		int m=l+r>>1;
		if(p<=m)set(o<<1,l,m,p,v);
		else set(o<<1|1,m+1,r,p,v);
		s[o].insert(v);
		// minn[o]=min(minn[o<<1],minn[o<<1|1]);
	}
	void sset(int o,int l,int r,int p,int v)
	{
		if(p>=1&&p<=n)set(o,l,r,p,v);
	}
	int qmin(int o,int l,int r,int L,int R,int P)
	{
		if(L<=l&&r<=R)
		{
			// return minn[o];
			auto p=s[o].lower_bound(P);
			if(p==s[o].end())return 0x3f3f3f3f;
			return *p;
		}
		int m=l+r>>1,res=inf;
		// pushdown(o);
		if(L<=m)res=min(res,qmin(o<<1,l,m,L,R,P));
		if(m<R)res=min(res,qmin(o<<1|1,m+1,r,L,R,P));
		return res;
	}
	int qmax(int o,int l,int r,int L,int R,int P)
	{
		if(L<=l&&r<=R)
		{
			// return minn[o];
			auto p=s[o].upper_bound(P);
			if(p==s[o].begin())return -0x3f3f3f3f;
			--p;
			return *p;
		}
		int m=l+r>>1,res=-inf;
		// pushdown(o);
		if(L<=m)res=max(res,qmax(o<<1,l,m,L,R,P));
		if(m<R)res=max(res,qmax(o<<1|1,m+1,r,L,R,P));
		return res;
	}
	int Qmn(int l,int r,int P)
	{
		if(l>r)return 0x3f3f3f3f;
		return qmin(1,1,n,l,r,P);
	}
	int Qmx(int l,int r,int P)
	{
		if(l>r)return -0x3f3f3f3f;
		return qmax(1,1,n,l,r,P);
	}
	void build(int o,int l,int r)
	{
		s[o].clear();
		if(l==r)return;
		int m=l+r>>1;
		build(o<<1,l,m);
		build(o<<1|1,m+1,r);
	}
};
int mn[1000005],mx[1000005];
struct SegTreeA2l{
	// std::set<int>s[800005];
	int mx[1000005],mn[1000005];
	void set(int o,int l,int r,int L,int R,int v)
	{
		if(L<=l&&r<=R)
		{
			mn[o]=min(mn[o],v);
			mx[o]=max(mx[o],v);
			// s[o].insert(v);
			return;
		}
		int m=l+r>>1;
		if(L<=m)set(o<<1,l,m,L,R,v);
		if(m<R)set(o<<1|1,m+1,r,L,R,v);
		// s[o].insert(v);
		// minn[o]=min(minn[o<<1],minn[o<<1|1]);
	}
	void build2(int o,int l,int r)
	{
		// s[o].clear();
		// mx[o]=-inf,mn[o]=inf;
		if(l==r)
		{
			::mn[l]=mn[o];
			::mx[l]=mx[o];
			return;
		}
		mx[o<<1]=max(mx[o],mx[o<<1]);
		mn[o<<1]=min(mn[o],mn[o<<1]);
		mx[o<<1|1]=max(mx[o],mx[o<<1|1]);
		mn[o<<1|1]=min(mn[o],mn[o<<1|1]);
		int m=l+r>>1;
		build2(o<<1,l,m);
		build2(o<<1|1,m+1,r);
	}
	void build(int o,int l,int r)
	{
		// s[o].clear();
		mx[o]=-inf,mn[o]=inf;
		if(l==r)return;
		int m=l+r>>1;
		build(o<<1,l,m);
		build(o<<1|1,m+1,r);
	}
}s;
std::set<int>g[233333];
int r[1000005];
int ls[1000005],rs[1000005];
#include <vector> 
std::vector<int>ss[1000005];
signed main()
{
	initprog();
	int T=read();rg(T)
	n=read();
	int m=read();
	rg(n)a[i]=b[i]=read();gr
	std::sort(b+1,b+1+n);int sl=std::unique(b+1,b+1+n)-b-1;
	rg(n)a[i]=std::lower_bound(b+1,b+1+sl,a[i])-b;gr
	rg(n)o[i]=pre[i]=0,nxt[i]=n+1;gr
	rg(n)pre[i]=o[a[i]],o[a[i]]=i;gr
	rg(n)o[i]=0;gr
	for(int i=n;i>=1;i--)suf[i]=o[a[i]],o[a[i]]=i;
	rg(n)g[i].clear();gr
	rg(n)g[a[i]].insert(i);gr
	// mn.build(1,1,n);mx.build(1,1,n);
	s.build(1,1,n); 
	// rg(n)odp(pre[i],suf[i]);gr
	// rg(n)mn.sset(1,1,n,pre[i],i);gr
	// rg(n)mx.sset(1,1,n,suf[i],i);gr
	// int l=n+1,r=0;
	rg(m)
	int L=read(),R=read();
	// continue;
	// mne(l,mn.Qmn(L,R,L));
	// mxe(r,mx.Qmx(L,R,R));
	// int nl=mn.Qmn(L,R,L);
	// int nr=mx.Qmx(L,R,R);
	// if(L<=nl&&nl<=R)mne(l,nl);
	// if(L<=nr&&nr<=R)mxe(r,nr);
	s.set(1,1,n,L,R,L);
	s.set(1,1,n,L,R,R);
	// if(L<=nl&&nl<=R)mne(l,nr);
	// if(L<=nr&&nr<=R)mxe(r,nl);
	gr
	// odp(l,r);
	s.build2(1,1,n);
	 // rg(n)odp(mn[i],mx[i]);gr puts("");
	int gl=0,pp=0;
	rg(n)r[i]=0;
	auto p=g[a[i]].upper_bound(mx[i]);
	if(p==g[a[i]].begin());else r[i]=*--p;
	if(r[i]==i)r[i]=0;
	if(r[i])++pp,ls[pp]=i,rs[pp]=r[i];
	auto p3=g[a[i]].lower_bound(mn[i]);
	if(p3==g[a[i]].end())continue;
	int p2=*p3;
	if(p2!=i)
	{
		++pp;
		ls[pp]=p2;
		rs[pp]=i;
	}
	gr
	// rg(n)odb(r[i]);gr puts("");
	int mnL=n+1,mxR=0,mxl=0,ans=inf,cr,fr=inf;
	rg(pp)mne(mnL,ls[i]);mxe(mxl,ls[i]);mne(mxR,ls[i]);gr
//	std::vector<int>ss(n+1);
rg(n)ss[i].clear();gr
	rg(pp)ss[ls[i]].push_back(rs[i]);gr
	cr=mxl;
	// rg(pp)odp(ls[i],rs[i]);gr
	// odb(mxl),odp(mnL,fr);
	rg(n)
	if(i<mnL||i>fr)continue;
	ans=min(ans,cr-i+1);
//	printf("?");odp(i,cr);
	// if(r[i])cr
	for(auto r:ss[i])
	{
		cr=max(cr,r);
		fr=min(fr,r);
	}
//	cr=max(cr,r[i]);
//	if(r[i])fr=min(fr,r[i]);
	gr
	if(pp==0)puts("0");else odl(ans);
	// odl(max(r-l+1,0));
	// puts("");
	gr
	return 0;
}
/*
1
7 4
2 2 2 7 8 2 2
4 4
4 4
5 5
1 1
*/