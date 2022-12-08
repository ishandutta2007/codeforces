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
const int N=1000005,M=100005,mod=1e9+7;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

char s[N];
int n,tot,cnt=1,last=1,a[N][26],fa[N],mx[N],pos[N],ri[N],to[N];
int f[N][20],dep[N],num[N],bnd[N],dp[N],p[N<<2];
bool vis[N];
vi g[N];
vector<pii> ins[N];
inline void extend(int i,int c){
	int p=last,np=++cnt;last=np;
	pos[np]=ri[np]=i;mx[np]=mx[p]+1;to[i]=np;
	while(p&&!a[p][c]) a[p][c]=np,p=fa[p];
	if(!p){fa[np]=1;return;}
	int q=a[p][c];
	if(mx[p]+1==mx[q]){fa[np]=q;return;}
	int nq=++cnt;
	cpy(a[nq],a[q]);fa[nq]=fa[q];ri[nq]=ri[q];
	pos[nq]=0;mx[nq]=mx[p]+1;fa[q]=fa[np]=nq;
	while(p&&a[p][c]==q) a[p][c]=nq,p=fa[p];
}
inline void dfs(int x,int L=0){
	static int ti;
	num[x]=++ti;
	for(int y:g[x])
		dep[y]=dep[x]+1,f[y][0]=x,dfs(y);
	bnd[x]=ti;
}
inline void build(){
	for(int i=2;i<=cnt;i++)
		g[fa[i]].pb(i);
	dfs(1);
}
inline int up(int x,int L){
	x=to[x];
	for(int i=19;~i;i--)
		if(mx[f[x][i]]>=L) x=f[x][i];
	return x;
}
inline void make(int x,int ti){
	while(x!=1&&!vis[x]){
		if(ti-mx[x]-1>0) ins[ti-mx[x]-1].pb(mp(x,mx[x]));
		vis[x]=1;x=fa[x];
	}
}
inline void change(int l,int r,int x,int y,int k,int b){
	if(x<=l&&r<=y){gmax(p[k],b);return;}
	int mid=l+r>>1;
	if(x<=mid) change(l,mid,x,y,ls,b);
	if(y>mid) change(mid+1,r,x,y,rs,b);
}
inline int get(int l,int r,int x,int k){
	if(l==r) return p[k];
	int mid=l+r>>1;
	if(x<=mid) return max(p[k],get(l,mid,x,ls));
	return max(p[k],get(mid+1,r,x,rs));
}

int main(){
#ifdef rqgao2014
	assert(freopen("input.txt","r",stdin));
#else 
	scanf("%d",&n);
#endif
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=n;i;i--)
		extend(i,s[i]-'a');
	build();
	for(int j=1;j<20;j++)
		for(int i=1;i<=cnt;i++)
			f[i][j]=f[f[i][j-1]][j-1];
	int ans=0;
	for(int i=n;i;i--){
		for(auto j:ins[i])
			change(1,cnt,num[j.FF],bnd[j.FF],1,j.SS);
		dp[i]=max(get(1,cnt,num[to[i]],1),i<n?get(1,cnt,num[to[i+1]],1):0)+1;
		gmax(ans,dp[i]);
		int x=up(i,dp[i]);make(fa[x],i);
		if(i-dp[i]-1>0) ins[i-dp[i]-1].pb(mp(x,dp[i]));
	}
	printf("%d\n",ans);
	return 0;
}