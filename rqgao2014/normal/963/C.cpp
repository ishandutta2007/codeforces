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

const ll inf=0x3f3f3f3f3f3f3f3f;
const int N=200005,M=100005,mod=1e9+7;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

int n,h,w;
ll a[N],b[N],c[N],sh[N],sw[N],lh[N],rh[N],lw[N],rw[N];

inline ll lcm(ll x,ll y){
	ll k=__gcd(x,y);
	if(x/k>inf/y){puts("0");exit(0);}
	return x*y/k;
}

inline int geth(ll x){return lower_bound(sh+1,sh+h+1,x)-sh;}
inline int getw(ll x){return lower_bound(sw+1,sw+w+1,x)-sw;}
inline int calc(ll x){
	int ans=0;
	for(ll i=1;i*i<=x;i++)
		if(x%i==0) ans+=1+(i!=x/i);
	return ans;
}

int main(){
#ifdef rqgao2014
	assert(freopen("input.txt","r",stdin));
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
		sh[i]=a[i];sw[i]=b[i];
	}
	sort(sh+1,sh+n+1);h=unique(sh+1,sh+n+1)-sh-1;
	sort(sw+1,sw+n+1);w=unique(sw+1,sw+n+1)-sw-1;
	if((ll)h*w!=n){puts("0");return 0;}
	for(int i=1;i<=h;i++) lh[i]=1;
	for(int i=1;i<=w;i++) lw[i]=1;
	for(int i=1;i<=n;i++){
		int x=geth(a[i]),y=getw(b[i]);
		rh[x]=__gcd(rh[x],c[i]);
		rw[y]=__gcd(rw[y],c[i]);
	}
	for(int i=1;i<=n;i++){
		int x=geth(a[i]),y=getw(b[i]);
		lh[x]=lcm(lh[x],c[i]/rw[y]);if(rh[x]%lh[x]){puts("0");return 0;}
		lw[y]=lcm(lw[y],c[i]/rh[x]);if(rw[y]%lw[y]){puts("0");return 0;}
	}
//	for(int i=1;i<=h;i++) debug(rh[i]/lh[i]);
//	for(int i=1;i<=w;i++) debug(rw[i]/lw[i]);
	printf("%d\n",calc(rh[1]/lh[1]));
	return 0;
}