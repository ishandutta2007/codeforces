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
const int N=200005,M=100005,mod=1e9+7;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

int n,m,num[N],bnd[N];
int p[N<<2],cnt[N<<2],flag[N<<2];
vi g[N],son[N];
map<int,bool> vis[N];

inline void add(int k,int b){p[k]+=b;flag[k]+=b;}
inline void push(int k){
	if(!flag[k]) return;
	add(ls,flag[k]);add(rs,flag[k]);
	flag[k]=0;
}
inline void add(int l,int r,int x,int y,int k,int b){
	if(x<=l&&r<=y){add(k,b);return;}
	push(k);int mid=l+r>>1;
	if(x<=mid) add(l,mid,x,y,ls,b);
	if(y>mid) add(mid+1,r,x,y,rs,b);
	p[k]=max(p[ls],p[rs]);
	cnt[k]=(p[ls]==p[k]?cnt[ls]:0)+(p[rs]==p[k]?cnt[rs]:0);	
}
inline void build(int l,int r,int k){
	cnt[k]=r-l+1;
	if(l==r) return;
	int mid=l+r>>1;
	build(l,mid,ls);build(mid+1,r,rs);
}

inline void dfs(int x,int F=0){
	static int ti;
	num[x]=++ti;
	for(int y:g[x])
		if(y!=F) dfs(y,x),son[x].pb(y);
	bnd[x]=ti;
}

inline int find(int x,int y){
	if(bnd[x]<num[y]) return 0;
	int l=0,r=SZ(son[x])-1;
	while(l<r){
		int mid=l+r>>1;
		if(num[y]<=bnd[son[x][mid]]) r=mid; else l=mid+1;
	}
	return son[x][r];
}

inline void calc(int x,int y,int c){
	if(num[x]>num[y]) swap(x,y);
	int t=find(x,y);
	add(1,n,num[y],bnd[y],1,c);
	if(!t){add(1,n,num[x],bnd[x],1,c);return;}
	if(num[t]>1) add(1,n,1,num[t]-1,1,c);
	if(bnd[t]<n) add(1,n,bnd[t]+1,n,1,c);
}

int main(){
#ifdef rqgao2014
	assert(freopen("input.txt","r",stdin));
#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].pb(y);g[y].pb(x);
	}
	dfs(1);build(1,n,1);
	for(int i=1,now=0;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		if(x>y) swap(x,y);
		if(!vis[x][y]) calc(x,y,1),now++; else calc(x,y,-1),now--;
		vis[x][y]^=1;
//		debug(p[1]);debug(now);
		printf("%d\n",p[1]==now?cnt[1]:0);
	}
	return 0;
}