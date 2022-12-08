#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>
#define all(a) a.begin(),a.end()
#define HEAP(...) priority_queue<__VA_ARGS__ >
#define heap(...) priority_queue<__VA_ARGS__,vector<__VA_ARGS__ >,greater<__VA_ARGS__ > > 
#define pii pair<int,int> 
#define pb push_back
#define mp make_pair
#define debuge cerr<<"isok"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define dprintf(...) fprintf(stderr,__VA_ARGS__)
#define SS second
#define FF first
#define ls (k<<1)
#define rs (k<<1|1)
#define clr(a,x) memset(a,x,sizeof(a))
#define cpy(a,x) memcpy(a,x,sizeof(a))
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define SZ(x) ((int)x.size())
using namespace std;
template<class T> inline void gmin(T &x,const T &y){x=x>y?y:x;}
template<class T> inline void gmax(T &x,const T &y){x=x<y?y:x;}
template<class T> inline bool Gmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T> inline bool Gmax(T &x,const T &y){return x<y?x=y,1:0;}
const int BufferSize=1<<16;
char buffer[BufferSize],*Bufferhead,*Buffertail;
bool Terminal;
inline char Getchar(){
	if(Bufferhead==Buffertail){
		int l=fread(buffer,1,BufferSize,stdin);
		if(!l){Terminal=1;return 0;}
		Buffertail=(Bufferhead=buffer)+l;
	}
	return *Bufferhead++;
}
template<class T>inline bool read(T &x){
	x=0;char c=Getchar(),rev=0;
	while(c<'0'||c>'9'){rev|=c=='-';c=Getchar();if(Terminal)return 0;}
	while(c>='0'&&c<='9') x=x*10+c-'0',c=Getchar();
	if(c=='.'){
		c=Getchar();double t=0.1;
		while(c>='0'&&c<='9') x=x+(c-'0')*t,c=Getchar(),t=t/10;
	}
	x=rev?-x:x;
	return 1;
}
template<class T1,class T2> inline bool read(T1 &x,T2 &y){return read(x)&read(y);}
template<class T1,class T2,class T3> inline bool read(T1 &x,T2 &y,T3 &z){return read(x)&read(y)&read(z);}
template<class T1,class T2,class T3,class T4> inline bool read(T1 &x,T2 &y,T3 &z,T4 &w){return read(x)&read(y)&read(z)&read(w);}
inline bool reads(char *x){
	char c=Getchar();
	while(c<33||c>126){c=Getchar();if(Terminal)return 0;}
	while(c>=33&&c<=126) (*x++)=c,c=Getchar();
	*x=0;return 1;
}
template<class T>inline void print(T x,const char c='\n'){
	if(!x){putchar('0');putchar(c);return;}
	if(x<0) putchar('-'),x=-x;
	int m=0,a[20];
	while(x) a[m++]=x%10,x/=10;
	while(m--) putchar(a[m]+'0');
	putchar(c);
}
//--------------------------------head---------------------------------------------

const int inf=0x3f3f3f3f;
const int N=100005,M=100005,mod=1e9+7,B=199;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

int n,m,a[N],q[N],num[N],bnd[N],fa[N],top[N],h[N];
int ans,sum[N/B+5],now[N];
short c[N/B+5][N<<1];
vi g[N];

int ss[N];
inline void add(int x,int y){
	while(x<=n) ss[x]+=y,x+=x&-x;
}
inline int get(int x){
	int ans=0;
	while(x) ans+=ss[x],x-=x&-x;
	return ans;
}
inline int calc(int x){return get(bnd[x])-get(num[x]);}

inline void dfs1(int x){
	static int si[N];si[x]=1;
	for(int y:g[x]){
		dfs1(y);
		si[x]+=si[y];
		if(si[y]>si[h[x]]) h[x]=y;
	}
}
inline void dfs2(int x){
	static int cnt=1;
	int xx=num[x];
	if(h[x]){
		int y=h[x],yy;
		yy=num[y]=++cnt;
		top[yy]=top[xx];fa[yy]=xx;
		dfs2(y);
	}
	for(int y:g[x])
		if(y!=h[x]){
			int yy;yy=num[y]=++cnt;
			top[yy]=yy;fa[yy]=xx;
			dfs2(y);
		}
	bnd[x]=cnt;
}

inline void change(int x,int b){
	x--;
	c[x/B][now[x]+n]--;
	now[x]=b-sum[x/B];
//	assert(now[x]>=-n&&now[x]<=n);
	c[x/B][now[x]+n]++;
}
inline void add1(int l,int r){
	l--;r--;
	int lx=l/B,rx=r/B;
	if(lx==rx){
		for(int i=l;i<=r;i++){
			c[lx][now[i]+n]--;
			now[i]++;c[lx][now[i]+n]++;
//			assert(now[i]>=-n&&now[i]<=n);
			if(sum[lx]+now[i]==0) ans--;
		}
		return;
	}
	if(l==lx*B) lx--;
	if(r==(rx+1)*B-1) rx++;
//	debuge;
	for(int i=l,en=(lx+1)*B;i<en;i++){
		c[lx][now[i]+n]--;
		now[i]++;c[lx][now[i]+n]++;
//		assert(now[i]>=-n&&now[i]<=n);
		if(sum[lx]+now[i]==0) ans--;
	}
	for(int i=rx*B;i<=r;i++){
		c[rx][now[i]+n]--;
		now[i]++;c[rx][now[i]+n]++;
//		assert(now[i]>=-n&&now[i]<=n);
		if(sum[rx]+now[i]==0) ans--;
	}
	for(int i=lx+1;i<rx;i++){
		sum[i]++;
		ans-=c[i][-sum[i]+n];
	}
}
inline void del1(int l,int r){
	l--;r--;
	int lx=l/B,rx=r/B;
	if(lx==rx){
		for(int i=l;i<=r;i++){
			c[lx][now[i]+n]--;
			now[i]--;c[lx][now[i]+n]++;
//			assert(now[i]>=-n&&now[i]<=n);
			if(sum[lx]+now[i]==-1) ans++;
		}
		return;
	}
	if(l==lx*B) lx--;
	if(r==(rx+1)*B-1) rx++;
	for(int i=l,en=(lx+1)*B;i<en;i++){
		c[lx][now[i]+n]--;
		now[i]--;c[lx][now[i]+n]++;
//		assert(now[i]>=-n&&now[i]<=n);
		if(sum[lx]+now[i]==-1) ans++;
	}
	for(int i=rx*B;i<=r;i++){
		c[rx][now[i]+n]--;
		now[i]--;c[rx][now[i]+n]++;
//		assert(now[i]>=-n&&now[i]<=n);
		if(sum[rx]+now[i]==-1) ans++;
	}
	for(int i=lx+1;i<rx;i++){
		ans+=c[i][-sum[i]+n];
		sum[i]--;
	}
}

int main(){
#ifdef rqgao2014
	assert(freopen("input.txt","r",stdin));
//	freopen("output.txt","w",stdout);
#endif
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++){
		int x;scanf("%d",&x);
		g[x].pb(i);
	}
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%d",&q[i]);
	dfs1(1);
	num[1]=top[1]=1;fa[1]=0;dfs2(1);
	for(int i=1;i<=n;i++){
		int x=num[i]-1;now[x]=a[i];
		c[x/B][now[x]+n]++;
	}
	for(int i=1;i<=m;i++){
		int x=abs(q[i]);
		if(q[i]>0){
			if(a[x]<calc(x)) ans--;
			add(num[x],1);
			change(num[x],n-calc(x));
			x=fa[num[x]];
			while(x){
				del1(top[x],x);
				x=fa[top[x]];
			}
		}
		else{
			change(num[x],a[x]-calc(x));
			if(a[x]<calc(x)) ans++;
			add(num[x],-1);
			x=fa[num[x]];
			while(x){
				add1(top[x],x);
				x=fa[top[x]];
			}
		}
		printf("%d ",ans);
	}puts("");
	return 0;
}