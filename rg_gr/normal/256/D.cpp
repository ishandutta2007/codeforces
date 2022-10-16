// Problem: D. Liars and Serge
// Contest: Codeforces - Codeforces Round #156 (Div. 1)
// URL: https://codeforces.com/problemset/problem/256/D
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
#define rrg(x) for(int i=0;i<(x);i++)
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
const int mod=777777777;
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
int dp[257][257],s[257][257];
int c[257][257];
int t7[]={642497124,482164403,768209115,462063756,154906374,36099042,341766705,678182556,621882744,478771358,231881111,175889805,243630450,168908523,671961765,55761813,652682670,773939082,517628076,756201264,124604900,750976272,498253248,676047609,137170026,705610017,495032139,561797418,703097347,500815609,95984586,739707108,265613565,387099846,777331779,594676173,591219559,407997044,208947235,93337440,478908360,685013007,487033953,671903001,39521181,738490312,33785059,465470131,310453920,54648783,346831137,427694175,474743430,705296781,435828036,429824745,663532359,261388683,244690731,533997135,596108961,506813013,371892402,590145264,104733162,143420103,654339672,700348950,685038942,578826927,286484229,501639192,434962491,299270097,27702486,335375775,111746817,565603164,294926121,676063665,735862995,710035809,437011960,668528077,138765186,508213986,615036450,353784942,624827616,343900011,241289776,52410890,72018835,352406796,415705878,4802637,376367145,65589678,333633477,341834527,303717460,282387700,42951006,254706039,423048528,526429710,68131467,669954708,12787348,500636381,317959019,479433192,657133515,416259390,610216692,340129188,44594256,257373347,138718678,530767740,292922628,37220268,605295159,480722613,458170419,30540300,487159055,232966794,149150650,};;
int t8[]={507720408,412133651,386543325,139952108,289303402,102404925,317067177,396414708,80515854,663739304,317300809,228877044,493725043,715317967,490300965,315527373,743539734,488329191,553627998,533025234,242583957,706116537,614109258,645447222,523195911,492109128,722623041,111085128,766395126,654378921,691964847,496688157,399056049,654363234,102052314,191720088,473910948,259736526,332840025,388047555,665791056,627111387,139696515,441456687,443032569,283264821,771641703,452641455,511306362,117572859,127701891,721298331,176520078,357242229,611296308,696994956,405628839,429224274,465336054,695091546,689828796,574648641,351220905,507964023,675326610,517248963,453528621,220301928,494463186,681789969,339589656,44524053,417125457,339589404,747135963,341780733,734158215,396817281,21997836,5728464,147611205,456248898,714128667,377654949,3862068,128418948,589390074,304947090,11703825,228266073,127304142,429215724,361541124,521572968,468358191,341231688,65323503,613778508,15985323,291661029,410970006,591638112,349541550,89967528,224922159,361094166,584206074,640051812,324264456,652625388,693768537,11740617,309238398,211085469,194905872,639416484,110110707,296645895,748118511,131177718,511142751,775975599,421403409,475528473,434685258,1768977,80301375,708023862,569195676,56238084,632887668,88089750,631539342,396695565,38780154,695798271,469819224,439587099,69045921,682966116,112310856,64943298,534475872,40215357,389728458,286368453,736006257,501181650,54829908,603489402,338032656,512182818,627500097,462674016,3103092,157324491,43978329,596818971,259025598,9088632,91991781,577291428,211245489,429471231,142626330,172560633,510907446,444609585,758102058,375112647,744786693,276174402,19259856,233672418,745389414,225772848,23385663,324290610,519804558,120337812,402578568,360676008,450089262,551043738,337388940,512108856,28879011,690040638,106017282,558262341,99972432,608226003,612152037,42414435,776201013,39580443,518796945,494437752,583194366,723936555,415359657,309569589,751104774,166684527,249229170,353120823,130668327,753823584,580966092,561963717,543672234,393846327,586278000,327398400,278403867,156455586,363920382,190245195,290039148,547014447,466218648,146037150,585462906,666008595,691786683,374707494,622498779,231158277,685740951,115612245,681825249,545555745,551718468,277206615,640171035,757727334,195193908,658656684,457760646,225925875,505761984,18685233,506832921,112511021,396846646,290147622,113924623,669986155,336008070,63611061,238586775,119956662,616557739,772784623,334527774,410403148,51933421,};
signed main()
{
	initprog();
	int n=read(),m=read();
	if(n==128)return odl(t7[m]),0;
	if(n>=128)return odl(t8[m]),0;
	rg(n)c[i][i]=c[i][0]=c[0][0]=1;gr
	rg(n)rg_(j,i-1)c[i][j]=ae(c[i-1][j-1],c[i-1][j]);gr gr
	dp[0][0]=1;
	rg(n)
	if(0){
	}else{
		memset(s,0,sizeof(s));
		for(int k=0;k<=n;k++)
			for(int q=k;q<=n;q++)
				if(k!=i)
				{
					for(int t=n;t>=k;t--)
						mae(s[q][t],me(dp[q-k][t-k],c[q][k]));
				}
				else
				{
					for(int t=n;t>=0;t--)
						mae(s[q][t],me(dp[q-k][t],c[q][k]));
				}
				// for(int t=)
		memcpy(dp,s,sizeof(s));
	}
	// rg(n+1)debug(dp[i-1],",\n"[i==n+1]);gr
	gr
	oldl(dp[n][m]);
	return 0;
}