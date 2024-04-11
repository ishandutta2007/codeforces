#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>
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
#define timeck()  dprintf("Case #%d solved, time = %d ms\n",argv,(int)(clock()*1000/CLOCKS_PER_SEC))
using namespace std;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
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

struct node{int u,v,w;}p[N];
int n,m,cnt,c[N],fa[N],num[N],bnd[N],dp[N],dep[N],f[N][20];
vi g[N],con[N];

inline void add(int x,int y){
	while(x<=n) c[x]+=y,x+=x&-x;
}
inline int get(int x){
	int ans=0;
	while(x) ans+=c[x],x-=x&-x;
	return ans;
}
void predfs(int x,int f=0){
	num[x]=++cnt;
//	dprintf("%d %d\n",x,cnt);
	fa[cnt]=num[f];dep[cnt]=dep[num[f]]+1;
	for(int y:g[x])
		predfs(y,x);
	bnd[num[x]]=cnt;
}
inline int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=0,t=dep[x]-dep[y];i<20;i++)
		if(t&(1<<i)) x=f[x][i];
	if(x==y) return x;
	for(int i=19;~i;i--)
		if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}

int Main(int argv){
	read(n);read(m);
	for(int i=2;i<=n;i++){
		int x;read(x);
		g[x].pb(i);
	}
	predfs(1);
	for(int i=1;i<=n;i++)
		f[i][0]=fa[i];
	for(int j=1;j<20;j++)
		for(int i=1;i<=n;i++)
			f[i][j]=f[f[i][j-1]][j-1];
	for(int i=1;i<=m;i++){
		read(p[i].u,p[i].v,p[i].w);
		p[i].u=num[p[i].u];p[i].v=num[p[i].v];
		con[lca(p[i].u,p[i].v)].pb(i);
	}
	for(int i=1;i<=n;i++){
		g[i].clear();
		if(i>1) g[fa[i]].pb(i);
	}
//	for(int i=1;i<=n;i++) printf("%d ",fa[i]);puts("");
	for(int x=n;x;x--){
		int sum=0;
		for(int y:g[x]) sum+=dp[y];
		for(int y:g[x]) add(y,-dp[y]),add(bnd[y]+1,dp[y]);
		dp[x]=sum;
		for(int i:con[x]){
			int u=p[i].u,v=p[i].v;
			gmax(dp[x],get(u)+get(v)+p[i].w+sum);
		}
		add(x,sum);add(bnd[x]+1,-sum);
	}
	debug(get(4));
	print(dp[1]);
#ifdef rqgao2014
	timeck();
#endif
	return 0;
}
void clear(){

}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	int T=1;
	for(int i=1;i<=T;i++)
		Main(i),clear();
	return 0;
}