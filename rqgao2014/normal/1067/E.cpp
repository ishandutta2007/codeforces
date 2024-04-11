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
const int N=500005,M=100005,mod=998244353;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

int n,ans,pw[N],si[N],f[N][2];
vi g[N];
bool black[N];

inline void dfs1(int x,int F=0){
	for(int y:g[x])
		if(y^F){black[y]=black[x]^1;dfs1(y,x);}
}
inline void dfs(int x,int F=0){
	si[x]=1;
	for(int y:g[x])
		if(y^F){dfs(y,x);si[x]+=si[y];}
	if(black[x]){
		f[x][0]=1;
		for(int y:g[x])
			if(y^F) f[x][0]=(ll)f[x][0]*f[y][0]%mod;
		f[x][1]=(pw[si[x]-1]-f[x][0]+mod)%mod;
	}
	else{
		int t=1,ss=1;
		f[x][1]=1;
		for(int y:g[x]){
			if(y==F) continue;
			ss+=si[y];	
			ch(ans,(ll)f[y][1]*pw[n-si[y]]);
			ch(ans,(ll)f[y][0]*1ll*t%mod*pw[n-ss]);
			t=(ll)t*(f[y][1]*2ll+f[y][0])%mod;
		}
		f[x][1]=t;
		f[x][0]=(pw[si[x]]-t+mod)%mod;
	}
}

int main(){
#ifdef rqgao2014
	assert(freopen("input.txt","r",stdin));
#endif
	scanf("%d",&n);
	if(n==1){puts("0");return 0;}pw[0]=1;
	for(int i=1;i<=n;i++) pw[i]=pw[i-1]*2%mod;
	for(int i=1;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].pb(y);g[y].pb(x);	
	}
	dfs1(1);
	dfs(1);
	for(int i=1;i<=n;i++)
		black[i]^=1;
	clr(f,0);
	dfs(g[1][0]);
	printf("%d\n",ans);
	return 0;
}