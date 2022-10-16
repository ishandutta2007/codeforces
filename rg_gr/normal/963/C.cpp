// Problem: C. Cutting Rectangle
// Contest: Codeforces - Tinkoff Internship Warmup Round 2018 and Codeforces Round #475 (Div. 1)
// URL: https://codeforces.com/contest/963/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
#ifndef ONLINE_JUDGE
#define DEBUG
#endif
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <assert.h>
#include <vector>
#include <set>
#include <map>
#include <stack>
//#include <zak>
#include <math.h>
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

#define int long long
const int mod=998244353;
#ifdef int 
#define inf 0x3f3f3f3f3f3f3f3fll
#else 
#define inf 0x3f3f3f3f
#endif
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
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
#ifdef cmlSEGMAX
		maxn[o]=max(maxn[o<<1],maxn[o<<1|1]);
#endif
#ifdef cmlSEGMIN
		minn[o]=min(minn[o<<1],minn[o<<1|1]);
#endif
#ifdef cmlSEGSUM
		sum[o]=sum[o<<1]+sum[o<<1|1];
#endif
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
#ifdef cmlSEGMAX
		maxn[o]=max(maxn[o<<1],maxn[o<<1|1]);
#endif
#ifdef cmlSEGMIN
		minn[o]=min(minn[o<<1],minn[o<<1|1]);
#endif
#ifdef cmlSEGSUM
		sum[o]=sum[o<<1]+sum[o<<1|1];
#endif
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
#ifdef cmlSEGMAX
		maxn[o]=max(maxn[o<<1],maxn[o<<1|1]);
#endif
#ifdef cmlSEGMIN
		minn[o]=min(minn[o<<1],minn[o<<1|1]);
#endif
#ifdef cmlSEGSUM
		sum[o]=sum[o<<1]+sum[o<<1|1];
#endif
		return res;
	}
#endif
};
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
int a[200005],b[200005],C[200005];
int x[200005],y[200005];
std::vector<std::pair<int,int>>r[200005],c[200005];
std::set<__int128>s;
int n=read();
int cc=0;
int vr[200005],vc[200005];
int nr[200005],nc[200005];
int sa,sb;
int P;
int CNT=0;
int test(int v)
{
	// printf("test %d\n",v);
	std::queue<int>q;
	++cc;
	if(CNT==0&&cc>=666)return s.insert(-cc),0;
	++CNT;
	q.push(a[P]);nr[a[P]]=v,vr[a[P]]=cc;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		// odl(u);
		if(u>0)
		{
			for(auto [v,cnt]:r[u])
			{
				if(vc[v]!=cc)
				{
					vc[v]=cc;
					if(cnt%nr[u]==0)nc[v]=cnt/nr[u],q.push(-v);
					else return 0;
				}
				else if(nc[v]!=cnt/nr[u])return 0;
			}
		}
		else
		{
			for(auto [v,cnt]:c[-u])
			{
				if(vr[v]!=cc)
				{
					vr[v]=cc;
					if(cnt%nc[-u]==0)nr[v]=cnt/nc[-u],q.push(v);
					else return 0;
				}
				else if(nr[v]!=cnt/nc[-u])return 0;
			}
		}
	}
	__int128 ans=0;
	rg(sa)if(vr[i]!=cc)return 0;gr
	rg(sb)if(vc[i]!=cc)return 0;gr
	rg(sa)ans+=(__int128)nr[i]*x[i];gr
	--CNT;
	s.insert(ans);
	// odl((signed)ans);
	return 1;
}
__int128 gcd(__int128 a,__int128 b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}
struct frac{
	__int128 a,b;
	void fix()
	{
		__int128 g=gcd(a,b);
		a/=g,b/=g;
	}
	bool operator==(const frac&c)
	{
		return a==c.a&&b==c.b;
	}
	bool operator!=(const frac&c)
	{
		return a!=c.a||b!=c.b;
	}
	frac operator*(frac c)
	{
		a*=c.a,b*=c.b;
		fix();
		if(b>1e12||a>1e18){puts("0");exit(0);}
		return *this;
	}
	frac operator/(frac c)
	{
		a*=c.b,b*=c.a;
		fix();
		if(b>1e12||a>1e12){puts("0");exit(0);}
		return *this;
	}
};
frac nR[200005],nC[200005];
#define nr nR
#define nc nC
int test()
{
	// printf("test %d\n",v);
	std::queue<int>q;
	++cc;
	q.push(a[P]);nR[a[P]]=(frac){1,1},vr[a[P]]=cc;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		// odl(u);
		if(u>0)
		{
			for(auto [v,cntt]:r[u])
			{
				frac cnt=(frac){cntt,1};
				if(vc[v]!=cc)
				{
					vc[v]=cc;
					nc[v]=cnt/nr[u],q.push(-v);
				}
				else if(nc[v]!=cnt/nr[u])return 0;
			}
		}
		else
		{
			for(auto [v,cntt]:c[-u])
			{
				frac cnt=(frac){cntt,1};
				if(vr[v]!=cc)
				{
					vr[v]=cc;
					nr[v]=cnt/nc[-u],q.push(v);
				}
				else if(nr[v]!=cnt/nc[-u])return 0;
			}
		}
	}
	// __int128 ans=0;
	rg(sa)if(vr[i]!=cc)return 0;gr
	rg(sb)if(vc[i]!=cc)return 0;gr
	// s.insert(ans);
	// odl((signed)ans);
	return 1;
}
__int128 lcm(__int128 a,__int128 b){return a/gcd(a,b)*b;}
signed main()
{
	initprog();
	rg(n)a[i]=read(),b[i]=read(),C[i]=read();
	x[i]=a[i],y[i]=b[i];gr
	std::sort(x+1,x+1+n);sa=std::unique(x+1,x+1+n)-x-1;
	std::sort(y+1,y+1+n);sb=std::unique(y+1,y+1+n)-y-1;
	rg(n)a[i]=std::lower_bound(x+1,x+1+sa,a[i])-x;gr
	rg(n)b[i]=std::lower_bound(y+1,y+1+sb,b[i])-y;gr
	// rg(n)odp(x[i],y[i]);gr
	rg(n)r[a[i]].push_back({b[i],C[i]}),c[b[i]].push_back({a[i],C[i]});gr
	P=std::min_element(C+1,C+1+n)-C;
	if(!test())return puts("0"),0;
	int L=1,G=0,ans=0;
	// a/bx is int
	rg(sa)L=lcm(L,nr[i].b);if(L>1e12)return puts("0"),0;gr
	rg(sb)if(nc[i].b!=1)return puts("0"),0;
	G=gcd(G,nc[i].a);
	gr
	// odp(L,G);
	// puts("");	rg(sa)odp((signed)nr[i].a,(signed)nr[i].b);gr puts("");
	// puts("");	rg(sb)odp((signed)nc[i].a,(signed)nc[i].b);gr puts("");
	for(int i=1;i*i<=C[P];i++)
	{
		#define test2(x) if(((x)%(L)==0)&&(G)%(x)==0)ans++;
		if(C[P]%i==0){test2(i);if(i*i!=C[P])test2(C[P]/i);}
	}
	odl(ans);
	// odl(s.size());
	return 0;
}