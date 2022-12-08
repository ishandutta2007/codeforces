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
const int N=200005,M=100005,mod=998244353;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

namespace NTT{
	const int N=(1<<19)+5,rt=3;
	const ull MAXMOD=(ull)mod*mod;
	int a[N],b[N],w[N];
	inline void fft(int *x,int n,int p){
		if(p) reverse(w+1,w+n);
		for(int i=0,j=0;i<n;i++){
			if(i<j) swap(x[i],x[j]);
			for(int k=n>>1;(j^=k)<k;k>>=1);
		}
		static ull a[N];
		for(int i=0;i<n;i++) a[i]=x[i];
		for(int i=2,cnt=0;i<=n;i<<=1){
			int c=i>>1,now=n/i;
			for(int j=0;j<n;j+=i)
				for(int k=0;k<c;k++){
					ull t=a[j+k+c]%mod*w[now*k];
					a[j+k+c]=a[j+k]+MAXMOD-t;
					a[j+k]+=t;
				}
			if(++cnt%18==0){
				for(int j=0;j<n;j++)
					a[j]%=mod;
			}
		}
		for(int i=0;i<n;i++) x[i]=a[i]%mod;
		if(p){
			reverse(w+1,w+n);
			for(int i=0,inv=exp(n,mod-2);i<n;i++)
				x[i]=(ll)x[i]*inv%mod;
		}
	}
	inline void mul(int *_a,int *_b,int n,int m,int *res,int k){
		int maxx=1,wn;
		while(maxx<=n+m) maxx<<=1;
		wn=exp(rt,(mod-1)/maxx);w[0]=1;
		for(int i=1;i<=maxx;i++) w[i]=(ll)w[i-1]*wn%mod;
		for(int i=0;i<maxx;i++) a[i]=b[i]=0;
		for(int i=0;i<=n;i++) a[i]=_a[i];
		for(int i=0;i<=m;i++) b[i]=_b[i];
		fft(a,maxx,0);fft(b,maxx,0);
		for(int i=0;i<maxx;i++) a[i]=(ll)a[i]*b[i]%mod;
		fft(a,maxx,1);
		for(int i=0;i<=k;i++) res[i]=(i<=n+m?a[i]:0);
	}
}

int n,A,B,fac[N],ifac[N],a[N];

inline void prepare(){
	int n=200000;fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=(ll)fac[i-1]*i%mod;
	ifac[n]=exp(fac[n],mod-2);
	for(int i=n;i;i--) ifac[i-1]=(ll)ifac[i]*i%mod;
}

inline void rotate(int *a,int n,int c,int *ans){
	static int x[N],y[N];
	for(int i=0;i<=n;i++)
		x[i]=(ll)a[i]*fac[i]%mod;
	for(int i=0,pw=1;i<=n;i++,pw=(ll)pw*c%mod)
		y[n-i]=(ll)pw*ifac[i]%mod;
	NTT::mul(x,y,n,n,x,n*2);
	for(int i=0;i<=n;i++)
		ans[i]=(ll)x[i+n]*ifac[i]%mod;
}

inline void solve(int n,int *a){
	if(!n){clr(a,0);a[0]=1;return;}
	int m=n>>1;
	static int ta[N];
	solve(m,a);
	rotate(a,m,m,ta);
	NTT::mul(a,ta,m,m,a,m*2);
	if(n&1){
		for(int i=n;~i;i--)
			a[i]=((ll)a[i]*(n-1)+(i?a[i-1]:0))%mod;
	}
}

int main(){
#ifdef rqgao2014
	assert(freopen("input.txt","r",stdin));
#endif
	prepare();
	scanf("%d%d%d",&n,&A,&B);
	if(!A||!B){puts("0");return 0;}
	solve(n-1,a);
	int ans=(ll)a[A+B-2]*fac[A+B-2]%mod*ifac[A-1]%mod*ifac[B-1]%mod;
	printf("%d\n",ans);
//	S(n-1,A+B-2)*C(A+B-2,A-1)
	return 0;
}