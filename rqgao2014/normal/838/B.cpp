#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>
#define HEAP(T) priority_queue<T>
#define heap(T) priority_queue<T,vector<T>,greater<T> > 
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
#define inf 0x3f3f3f3f
#define clr(a,x) memset(a,x,sizeof(a))
#define cpy(a,x) memcpy(a,x,sizeof(a))
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
using namespace std;

const int N=300005,M=100005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
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
	while(c<'0'||c>'9'){c=Getchar();rev|=c=='-';if(Terminal)return 0;}
	while(c>='0'&&c<='9') x=x*10+c-'0',c=Getchar();
	x=rev?-x:x;
	return 1;
}
inline bool reads(char *x){
	char c=Getchar();
	while(c<33||c>126){c=Getchar();if(Terminal)return 0;}
	while(c>=33&&c<=126) (*x++)=c,c=Getchar();
	*x=0;return 1;
}
template<class T>inline void print(T x,const char c){
	if(!x){putchar('0');putchar(c);return;}
	if(x<0) putchar('-'),x=-x;
	int m=0,a[20];
	while(x) a[m++]=x%10,x/=10;
	while(m--) putchar(a[m]+'0');
	putchar(c);
}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

int n,tot,fa[N],d[N],son[N],seq[N],num[N],bnd[N];
ll dep[N],tmp[N],p[N<<2],flag[N<<2];
vi g[N];

inline void dfs(int x,ll k=0){
	dep[x]=k;num[x]=++tot;
	for(auto j:g[x]) 
		dfs(j,k+fa[j]);
	bnd[num[x]]=tot;
}
inline void add(int k,ll b){p[k]+=b;flag[k]+=b;}
inline void push(int k){
	if(!flag[k]) return;
	add(ls,flag[k]);add(rs,flag[k]);
	flag[k]=0;
}
inline void add(int l,int r,int x,int y,ll b,int k=1){
	if(x<=l&&r<=y){add(k,b);return ;}
	push(k);
	int mid=l+r>>1;
	if(x<=mid) add(l,mid,x,y,b,ls);
	if(y>mid) add(mid+1,r,x,y,b,rs);
	p[k]=min(p[ls],p[rs]);
}
inline ll get(int l,int r,int x,int y,int k=1){
	if(x<=l&&r<=y) return p[k];
	push(k);
	int mid=l+r>>1;ll ans=1ll<<60;
	if(x<=mid) gmin(ans,get(l,mid,x,y,ls));
	if(y>mid) gmin(ans,get(mid+1,r,x,y,rs));
	return ans;
}
inline void build(int l,int r,int k=1){
	if(l==r){p[k]=dep[l]+d[l];return;}
	int mid=l+r>>1;
	build(l,mid,ls);build(mid+1,r,rs);
	p[k]=min(p[ls],p[rs]);
}
inline ll getdep(int u){return get(1,n,u,u)-d[u];}


int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int Q;
	read(n);read(Q);
	for(int i=1;i<n;i++){
		int x,y,z;read(x);read(y);read(z);
		g[x].pb(y);son[i]=y;fa[y]=z;
	}
	dfs(1);
	for(int i=1;i<=n;i++) tmp[i]=dep[i];
	for(int i=1;i<=n;i++) dep[num[i]]=tmp[i];
	for(int i=1;i<n;i++) son[i]=num[son[i]];
	for(int i=1;i<=n;i++) tmp[i]=fa[i];
	for(int i=1;i<=n;i++) fa[num[i]]=tmp[i];
	for(int i=1;i<n;i++){
		int x,y,z;read(x);read(y);read(z);
		d[num[x]]=z;seq[i]=num[x];
	}
//	debug(tot);
	build(1,n);
	while(Q--){
		int t,u,v,x,y;
		read(t);read(u);read(v);
		if(t==1){
			if(u>=n){
				u=seq[u-n+1];
				add(1,n,u,u,v-d[u]);
				d[u]=v;
			}
			else{
				u=son[u];
				add(1,n,u,bnd[u],v-fa[u]);
				fa[u]=v;
			}
		}
		else{
			u=num[u],v=num[v];
			if(v>=u&&v<=bnd[u])
				print(getdep(v)-getdep(u),'\n');
			else
				print(get(1,n,u,bnd[u])+getdep(v)-getdep(u),'\n');
		}
	}
	return 0;
}