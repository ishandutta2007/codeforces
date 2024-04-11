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
const int N=2005,M=100005,mod=998244353;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

int n,m,f[2][N][11],g[2][N][11],fac[N],ifac[N];
vi a,b;
char str[15];
inline int calc(int x,int k){
	if(!x) return !k;
	return (ll)fac[x+k-1]*ifac[x-1]%mod;
}

int Main(int argv){
	read(n);
	for(int i=1;i<=n;i++){
		reads(str);
		int t=0;
		for(int j=0;j<strlen(str);j++)
			if(j&1) t=(t+11-str[j]+'0')%11; else t=(t+str[j]-'0')%11;
		if(strlen(str)&1) a.pb(t); else b.pb(t);
	}
//	return 0;
	n=a.size();m=b.size();
	f[0][0][0]=1;
	for(int i=0;i<n;i++){
		clr(f[i+1&1],0);
		for(int j=0;j<=(n+1)/2&&j<=i;j++)
			for(int k=0;k<11;k++){
				if(!f[i&1][j][k]) continue;
				ch(f[i+1&1][j+1][(k+a[i])%11],f[i&1][j][k]);
				ch(f[i+1&1][j][(k+11-a[i])%11],f[i&1][j][k]);
			}
	}
//	debuge;
	for(int i=0;i<11;i++)
		g[0][0][i]=f[n&1][(n+1)/2][i];
	for(int i=0;i<m;i++){
		clr(g[i+1&1],0);
		for(int j=0;j<=i;j++)
			for(int k=0;k<11;k++){
				if(!g[i&1][j][k]) continue;
				ch(g[i+1&1][j+1][(k+b[i])%11],g[i&1][j][k]);
				ch(g[i+1&1][j][(k+11-b[i])%11],g[i&1][j][k]);
			}
	}
//	debuge;
	int L=n/2+1,R=n-n/2,ans=0;
	for(int j=0;j<=m;j++)
		ch(ans,(ll)g[m&1][j][0]*calc(L,j)%mod*calc(R,m-j));
	ans=(ll)ans*fac[(n+1)/2]%mod*fac[n/2]%mod;
	print(ans);
#ifdef rqgao2014
	timeck();
#endif
	return 0;
}
void clear(){
	clr(f,0);clr(g,0);
	a.clear();b.clear();
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	int n=2000;
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=(ll)fac[i-1]*i%mod;
	ifac[n]=exp(fac[n],mod-2);
	for(int i=n;i;i--) ifac[i-1]=(ll)ifac[i]*i%mod;
	int T;scanf("%d",&T);
	for(int i=1;i<=T;i++)
		Main(i),clear();
	return 0;
}