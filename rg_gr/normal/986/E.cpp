// Problem: C. Prince's Problem
// Contest: Codeforces - Z Flip #define insert push_back(3)
// URL: https://codeforces.com/gym/376169/problem/C
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// Problem: B. Lynyrd Skynyrd
// Contest: Codeforces - Codeforces Round #549 (Div. 1)
// URL: https://codeforces.com/contest/1142/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
#include <map>
#include <vector>
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
const int mod=1000000007;
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
#define COMB
#ifdef COMB
#ifndef int
#define int long long
#endif
int fac[1000005],inv[1000005];
#endif
void initprog()
{
#ifdef COMB
	inv[0]=inv[1]=1;
	rg(10000)if(i>1)inv[i]=inv[mod%i]*(mod-mod/i)%mod;gr
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
std::vector<int>p[10000005];
// int p[10000005][6];

bool vis[10000005];
newe(100005);
arr a;
struct Q{
	int u,v,w,d;
}t[100005],s[400005];
int f[100005][22];
arr dep;
void dfs(int u,int fa)
{
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	for(int i=1;(1<<i)<=dep[u];i++)f[u][i]=f[f[u][i-1]][i-1];
	fe(u)if(v!=fa)dfs(v,u);gr
}
int LCA(int x,int y)
{
	if(dep[x]>dep[y]);else x^=y^=x^=y;
	// odp(x,y);
	// odp(dep[x],dep[y]);
	int d=dep[x]-dep[y];for(int i=20;i>=0;i--)if(d>>i&1)x=f[x][i];
	if(x==y)return x;
	for(int i=20;i>=0;i--)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	return f[x][0];
}
int big[10000005];
struct Que{
	int s,d,mul,exp;
	bool operator<(const Que&b)const{
		return s>b.s;
	}
};
struct Bit{
	int val,d,mul;
};
std::vector<Que>q1[100005];
std::vector<Bit>q2[100005];
int T[8888][33];
arr ans;
// void dfs2(int u,int g,int fa,int ig)
// 
int prim[10005],cc;
void dfs2(int u,int fa)
{
	// odp(u,g);fflush(stdout);
	#define e E
	for(int _=1;_<=cc;_++)
	{
		int g=prim[_];
		// odl(g);
		int va=a[u],e=0;while(va%g==0)va/=g,e++;
		// if(g==2)odp(u,e);
		// T[_][e]++;
		for(int i=1;i<=e;i++)T[_][i]+=i;
		for(int i=e+1;i<=(g==2?23:(g==3?14:10));i++)T[_][i]+=e;
		// odp(_,e);
		// odl(q1[u].size());
		while(!q1[u].empty())
		{
			auto GG=*q1[u].rbegin();
			// odl(-GG.s);
			if(GG.s==g)
			{
				int pw=T[_][GG.exp],mu=1;
				// for(int j=1,t=g;t<=10000000;j++,t*=g)
				// {
					// pw+=T[_][j]*min(j,GG.exp);
				// }
				// printf("%d ")
				// assert(me(g,inv[g])==1);
				// if(g==2)printf("%d %d %d\n",u,pw,GG.mul);
				if(GG.mul==1)mle(ans[GG.d],qp(g,pw));
				else mle(ans[GG.d],qp(inv[g],2*pw));
				// printf("%d ")
				// assert(g>0);
				q1[u].pop_back();
			}
			else break;
		}
	}
	#undef e
	fe(u)
	if(v==fa)continue;
	dfs2(v,u);
	gr
	for(int _=1;_<=cc;_++)
	{
		int g=prim[_];
		int va=a[u],e=0;while(va%g==0)va/=g,e++;
		for(int i=1;i<=e;i++)T[_][i]-=i;
		for(int i=e+1;i<=(g==2?23:(g==3?14:10));i++)T[_][i]-=e;
	}
}
	// // odp(u,g);fflush(stdout);
	// #define e E
	// int va=a[u],e=0;while(va%g==0)va/=g,e++;
	// T[e]++;
	// while(!q1[u].empty())
	// {
		// auto GG=*q1[u].rbegin();
		// if(GG.s==g)
		// {
			// int pw=0,mu=1;
			// for(int j=1,t=g;t<=10000000;j++,t*=g)
			// {
				// pw+=T[j]*min(j,GG.exp);
			// }
			// if(GG.mul==1)mle(ans[GG.d],qp(g,pw));
			// else mle(ans[GG.d],qp(ig,2*pw));
			// q1[u].pop_back();
		// }
		// else break;
	// }
	// #undef e
	// fe(u)
	// if(v==fa)continue;
	// dfs2(v,g,u,ig);
	// gr
	// T[E]--;
// }
std::map<int,int>mp;
void dfs3(int u,int fa)
{
	if(big[a[u]]>1)mp[big[a[u]]]++;
	for(auto s:q2[u])
	{
		if(s.mul==1)mle(ans[s.d],qp(s.val,mp[s.val]));
		else mle(ans[s.d],qp(s.val,mp[s.val]*(mod*2-4))%(mod-1));
	}
	fe(u)
	if(v==fa)continue;
	dfs3(v,u);
	gr
	if(big[a[u]]>1)mp[big[a[u]]]--;
}
bool I[10000005];
signed main()
{
	initprog();
	int n=read();
	rg(n-1)
	int u=read(),v=read();addedge(u,v,1),addedge(v,u,1);
	gr
	dfs(1,0);
	rg(n)vis[a[i]=read()]=1;gr
	int q=read();
	// odl(q);
	// return 0;
	rg(q)
	int u=read(),v=read(),w=read();
	vis[w]=1;
	t[i]=(Q){u,v,w,i};
	gr
	// return 0;
	for(int i=2;i<=4444;i++)
	{
		if(I[i])continue;
		// odl(i);
		prim[++cc]=i;
		for(int j=i*2;j<=4444;j+=i)
			I[j]=1;
	}
	// return 0;
	// for(int i=2;i*i<=10000000;i++)
	// {
		// if(I[i])continue;
		// // odl(i);fflush(stdout);
		// // I[i]=1;
		// // if(p[i][0])continue;
		// for(int j=i;j<=10000000;j+=i){I[j]=1;if(vis[j])
		// // p[0][0]++,p[j][0]++;
		// p[j].emplace_back(i);}
		// I[i]=0;
// 			
	// }
	rg(10000000)
	if(vis[i]==0)continue;
	int s=i;
	rg_(j,cc)if(s%prim[j]==0)p[i].push_back(prim[j]);gr
	for(auto g:p[i])while(s%g==0)s/=g;
	if(s>1)big[i]=s;
	gr
	rg(q)ans[i]=1;gr
	rg(q)
	int u=t[i].u,v=t[i].v,w=t[i].w;
	// u,v,lca(u,v),fa(lca(u,v));
	for(auto t:p[w])
	{
		// odp(w,t);
		int e=0,fdq=w;while(fdq%t==0)fdq/=t,e++;
		q1[u].push_back((Que){t,i,1,e});
		q1[v].push_back((Que){t,i,1,e});
		// printf("%d %d %d\n",u,v,LCA(u,v));
		q1[LCA(u,v)].push_back((Que){t,i,-1,e});
		// q1[f[LCA(u,v)][0]].push_back((Que){t,i,-1,e});
	}
	if(big[w])
	{
		q2[u].push_back((Bit){big[w],i,1});
		q2[v].push_back((Bit){big[w],i,1});
		q2[LCA(u,v)].push_back((Bit){big[w],i,-1});
		// q2[f[LCA(u,v)][0]].push_back((Bit){big[w],i,-1});
	}
	assert(ans[i]);
	mle(ans[i],(std::__gcd(a[LCA(u,v)],w)));
	gr
	rg(n)std::sort(q1[i].begin(),q1[i].end());gr
	// for(int i=2;i*i<=10000000;i++)
	// rg_(f,cc)
	// int i=prim[f];if(i*i>10000000)break;
		// // if(p[i].size()!=1||p[i][0]!=i)continue;
		// if(I[i])continue;
		// odl(i);fflush(stdout);
		// memset(T,0,sizeof(T));
		// dfs2(1,i,0,qp(i,mod-2));
	// }
	// return 0;
	dfs2(1,0);
	dfs3(1,0);
	rg(q)odl(ans[i]);gr
	return 0;
	
	return 0;
}