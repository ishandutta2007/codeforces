// Problem: E. Group Photo
// Contest: Codeforces - Contest 2050 and Codeforces Round #718 (Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/1517/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// Problem: B. Lynyrd Skynyrd
// Contest: Codeforces - Codeforces Round #549 (Div. 1)
// URL: https://codeforces.com/contest/1142/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
#define od(x) printf("%lld",x)
#define odb(x) printf("%lld ",x)
#define odl(x) printf("%lld\n",x)
#define odp(x,y) printf("%lld %lld\n",x,y)
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
#define inf 0x3f3f3f3f3f3f3f3f3fll
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
		int m=(l+r+inf+inf>>1)-inf;
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
		int m=(l+r+inf+inf>>1)-inf;
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
		int m=(l+r+inf+inf>>1)-inf,res=inf;
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
		int m=(l+r+inf+inf>>1)-inf,res=-inf;
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
		int m=(l+r+inf+inf>>1)-inf,res=0;
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
int a[1000005],p[1000005],q[1000005],g[1000005];
int Ld,Rd;
// struct DS{
// struct Node{
    // Node *lc,*rc;
    // signed sum;
    // Node(){lc=rc=NULL;sum=0;}
// }*root[200005];
// void maintain(Node *&o)
// {
    // o->sum=0;
    // if(o->lc)o->sum+=o->lc->sum;
    // if(o->rc)o->sum+=o->rc->sum;
// }
// #define sum(x) (x?x->sum:0)
// #define lc(x) (x?x->lc:0)
// #define rc(x) (x?x->rc:0)
// void add(Node *&o,Node *p,int l,int r,int q)
// {
	// // printf("%lld %lld %lld mid %lld\n",l,r,q,(l+r+inf+inf>>1)-inf);
    // if(o==nullptr)o=new Node();
    // if(l==r)
    // {
        // o->sum=sum(p)+1;
        // // oldl(l);
        // return;
    // }
    // int m=(l+r+inf+inf>>1)-inf;
    // if(q<=m)add(o->lc,lc(p),l,m,q),o->rc=rc(p);
    // else add(o->rc,rc(p),m+1,r,q),o->lc=lc(p);
    // maintain(o);
// }
// int query(Node *o,Node *p,int l,int r,int L,int R=inf)
// {
    // // printf("%lld %lld %lld (%lld %lld)\n",l,r,k,sum(o),sum(p));
    // if(L<=l&&r<=R)return sum(p)-sum(o);
    // int m=(l+r+inf+inf>>1)-inf,res=0;
    // if(L<=m)res+=query(lc(o),lc(p),l,m,L,R);
    // if(m<R)res+=query(rc(o),rc(p),m+1,r,L,R);
    // return res;
// }
// void kill(Node *&x)
// {
	// // if(!x)return ;
	// // if(lc(x))kill(x->lc);
	// // if(rc(x))kill(x->rc);
	// // delete x;
	// x=NULL;
// }
// void clear()
// {
	// root[0]=0;
	// for(int i=1;;i++)if(root[i])kill(root[i]);else break;
// }
// }t1,t2;
int s(int l,int r)
{
	int val=q[r]-q[l-1];
	if(l&1)return val;
	return -val;
}

int solve(int pos,int n,int val,int endpos)
{
	if(endpos<pos)return 0;
	int ret=0;
	if(pos&1)
	{
		int t=val+q[pos-1]-p[n];
		// ret=t1.query(t1.root[pos],t1.root[endpos],Ld,Rd,t+1);
		if(endpos+pos&1);else endpos--;
		int l=pos+1>>1,r=endpos>>1,ans=l-1,s=l;
		// odb(pos);odp(pos,endpos);odp(l,r);
		while(l<=r)
		{
			int m=l+r>>1;
			int i=m*2;
			if(t+1<=q[i]-p[i])ans=m,l=m+1;
			else r=m-1;
		}
		int d=0;
		ret=ans-s+1;
		//t+1<=q[i]-p[i]<=inf;
	}
	else
	{
		int t=val-q[pos-1]-p[n];
		// for(int i=pos+1;i<=endpos;i+=2)if(t<-q[i]-p[i])ret++;
		// ret=t2.query(t2.root[pos],t2.root[endpos],Ld,Rd,t+1);
		if(endpos+pos&1);else endpos--;
		int l=pos+1>>1,r=endpos-1>>1,ans=l-1,s=l;
		// odb(pos);odp(pos,endpos);
		while(l<=r)
		{
			int m=l+r>>1;
			int i=m*2+1;
			if(t+1<=-q[i]-p[i])ans=m,l=m+1;
			else r=m-1;
		}
		ret=ans-s+1;
		int d=0;
		for(int i=pos+1;i<=endpos;i+=2)if(t<-q[i]-p[i])d=i;
		// odp(ans*2+2,d);
// 		
		// if(d!=ret)
		// {
			// printf("query %lld %lld %lld %lld\n",pos,n,val,endpos);
			// odl(t);
			// // odl(g[4]);
			// odp(d,ret);
			// exit(0);
		// }
		//t<-q[i]-p[i]
	}
	// for(signed i=pos+1;i<=endpos;i+=2)
		// if(s(pos,i)+p[n]-p[i]>val)ret++;
	return ret;
}
#define ONLINE_JUDGE
signed main()
{
	initprog();
	int T=read();rg(T)
	int n=read();rg(n)a[i]=read();p[i]=p[i-1]+a[i],q[i]=q[i-1]+((i&1)?a[i]:-a[i]);Rd+=a[i]*2;gr
	// Rd=n*1e9;
	Ld=-Rd-1;
	rg(n)g[i]=q[i]-p[i];gr
	// t1.clear();
	// t2.clear();
	// rg(n)odl(g[i]);gr puts("");
	// rg(n)t1.add(t1.root[i],t1.root[i-1],Ld,Rd,((i^1)&1)?g[i]:-Rd);gr
	// rg(n)t2.add(t2.root[i],t2.root[i-1],Ld,Rd,((i^0)&1)?-p[i]-q[i]:-Rd);gr
//	if(i==32){rg(n)odb(a[i]);gr return 0;}
	
#ifdef ONLINE_JUDGE
#define printf(...) 0
#endif
	int ans=0;
	// start with .
	// [.] [!] {{.}}
	for(int i=1;i<=n;i++)if(p[i]<p[n]-p[i])ans++;
	for(int i=1;i<=n-1;i++)if(p[i]+a[n]<p[n]-p[i]-a[n])ans++;
	if(n>2&&p[n-2]+a[n]<a[n-1])ans--,odl(-1);
	// [.] !.
	oldl(ans%998244353);
	// [.] 
	0;
	oldl(ans%998244353);
	// [.] [ !. ] {!}  
	for(int i=1;i+2<=n;i++)
	{
		ans+=solve(i+1,n,p[i],n);
	}
	oldl(ans%998244353);
	for(int i=1;i+2<=n;i++)
	{
		ans+=solve(i+1,n-1,p[i]+a[n],n-3);
	}
	oldl(ans%998244353);
	// start with !
	// [!] {.}
	for(int i=1;i<=n;i++)if(p[i]>p[n]-p[i])ans++;
	oldl(ans%998244353);
	// ! [.] { !. } {!}
	for(int i=2;i+2<=n;i++)
	{
		ans+=solve(i+1,n,p[i]-p[1]-p[1],n-1);
	}
	for(int i=2;i+2<=n-1;i++)
	{
		ans+=solve(i+1,n-1,p[i]-p[1]-p[1]+a[n],n-2);
	}
	oldl(ans%998244353);
	
	for(int i=2;i<n;i++)if(p[i]-p[1]<p[n]-p[i]+p[1])ans++;
	oldl(ans%998244353);	
	for(int i=2;i<n-1;i++)
		if(a[n]+p[i]-a[1]<p[n-1]-p[i]+a[1])ans++;
#undef printf
//	if(T<=10)
	oldl(ans%998244353);
	// start with .
	// [.] [!] {{.}}
	// [.] [ !. ] {!}  
	// [.] [ !. ] [!] .
	
	// start with !
	// [!] {.}
	// ! [.] [ !. ] [!] {{.}}
	// ! [.] [!]
	// ! [.] [!] .
	gr
	return 0;
}
/*




































....!!!!
...!!!!!
..!!!!!!
...!!!!.
..!!!!!.
.!!!!!!.
.!!!!!!!
...!.!.!
...!.!!!
..!.!.!!
..!.!!!.
..!.!!!!
.!.!.!.!
.!.!.!!.
.!.!.!!!
.!.!!!!.
.!.!!!!!

!..!.!.!
!..!.!!.
!..!.!!!
!.!.!.!!
!.!.!!!.
!.!.!!!!

!..!!!!.
!.!!!!!.

!!!!!...
!!!!!!..
!!!!!!!.
!!!!!!!!

!....!!!
!...!!!!
!..!!!!!
!.!!!!!!
*/