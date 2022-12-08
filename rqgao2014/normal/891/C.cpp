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
const int N=500005,M=100005,mod=1e9+7;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

struct node{int x,y,z;}p[N<<1];
int n,m,Q,tot,num[N],bnd[N],dep[N],f[N][20],mx[N][20];
int u[N],v[N],w[N],fa[N];
vector<pii> g[N];

inline void dfs(int x,int F=0){
	num[x]=++tot;
	for(auto i:g[x]){
		int y=i.FF;
		if(y==F)  continue;
		dep[y]=dep[x]+1;f[y][0]=x;mx[y][0]=i.SS;
		dfs(y,x);
	}
	bnd[x]=tot;
}
inline bool cmp(node &a,node &b){return a.z<b.z;}
inline bool cmp2(int &a,int &b){return num[a]<num[b];}
inline int find(int x){return fa[x]==x?x:(fa[x]=find(fa[x]));}
inline int lca(int x,int y){
	if(dep[x]>dep[y]) swap(x,y);
	for(int i=0,t=dep[y]-dep[x];i<20;i++)
		if(t&(1<<i)) y=f[y][i];
	if(x==y) return x;
	for(int i=19;~i;i--)
		if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}
inline int getmx(int x,int y){
	if(dep[x]>dep[y]) swap(x,y);
	int ans=0;
	for(int i=19;~i;i--)
		if(dep[f[y][i]]>=dep[x]) gmax(ans,mx[y][i]),y=f[y][i];
	return ans;
}
inline void solve(){
	static int a[N<<1],dad[N];
	int k,tot=0,isok=1;ll ans=0;read(k);
	for(int j=1;j<=k;j++){
		int x;read(x);
		a[++tot]=u[x];a[++tot]=v[x];
		if(find(u[x])==find(v[x])) isok=0;
		fa[find(u[x])]=find(v[x]);
		ans+=w[x];
	}
	if(!isok){puts("NO");goto clear;}
//	debug(ans);
	sort(a+1,a+tot+1,cmp2);
	tot=unique(a+1,a+tot+1)-a-1;
	for(int i=1,ttot=tot;i<ttot;i++)
		a[++tot]=lca(a[i],a[i+1]);
	sort(a+1,a+tot+1,cmp2);
	tot=unique(a+1,a+tot+1)-a-1;
//	for(int i=1;i<=tot;i++) dprintf("%d ",a[i]);puts("");
	for(int i=2,j=1;i<=tot;i++){
		while(j&&num[a[i]]>bnd[a[j]])j=dad[j];
		p[i-1]=(node){a[i],a[j],getmx(a[i],a[j])};
		dad[i]=j;j=i;
//		dprintf("%d %d %d\n",a[i],a[j],getmx(a[i],a[j]));
	}
	sort(p+1,p+tot,cmp);
	for(int i=1;i<tot;i++)
		if(find(p[i].x)!=find(p[i].y)){
			fa[find(p[i].x)]=find(p[i].y);
			g[p[i].x].pb(mp(p[i].y,p[i].z));
			g[p[i].y].pb(mp(p[i].x,p[i].z));
		}
		else ans-=p[i].z;
//	debug(ans);
	puts(ans?"NO":"YES");
	clear:
	for(int i=1;i<=tot;i++) fa[a[i]]=a[i];
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	read(n,m);
	for(int i=1;i<=m;i++){
		int x,y,z;read(x,y,z);
		p[i]=(node){x,y,z};
		u[i]=x,v[i]=y,w[i]=z;
	}
	sort(p+1,p+m+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
		if(find(p[i].x)!=find(p[i].y)){
			fa[find(p[i].x)]=find(p[i].y);
			g[p[i].x].pb(mp(p[i].y,p[i].z));
			g[p[i].y].pb(mp(p[i].x,p[i].z));
//			dprintf("%d %d %d\n",p[i].x,p[i].y,p[i].z);
		}
	dep[1]=100,dfs(1);
	for(int j=1;j<20;j++)
		for(int i=1;i<=n;i++)
			f[i][j]=f[f[i][j-1]][j-1],mx[i][j]=max(mx[i][j-1],mx[f[i][j-1]][j-1]);
	read(Q);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=Q;i++) solve();
	return 0;
}