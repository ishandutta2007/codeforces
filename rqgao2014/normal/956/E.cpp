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
const int N=10005,M=100005,mod=1e9+7;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

struct node{int a,b;}a[N];
int n,l,r,g[N],s[N];
bitset<N> f[2][N];

int main(){
#ifdef rqgao2014
	assert(freopen("input.txt","r",stdin));
#endif
	scanf("%d%d%d",&n,&l,&r);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].a);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].b);
	sort(a+1,a+n+1,[&](node a,node b){return mp(a.b,b.a)>mp(b.b,a.a);});
	f[0][n+1][0]=1;
	for(int i=n;i;i--){
		f[0][i]=f[0][i+1]|(f[0][i+1]<<a[i].a);
		if(a[i].b) f[1][i]=f[0][i+1]|f[1][i+1]|(f[1][i+1]<<a[i].a);
	}
	for(int i=1;i<=10000;i++) g[i]=-inf;
	int ans=0;
	for(int i=l;i<=r;i++)
		if(f[1][1][i]){ans=1;break;}
	for(int i=1,R=0;i<=n;i++){
		if(!a[i].b) break;
		R+=a[i].a;
		if(R>r) break;
		for(int j=R;j>=a[i].a;j--)
			gmax(g[j],g[j-a[i].a]+1);
		s[0]=g[0];
		for(int j=1;j<=R;j++)
			s[j]=max(s[j-1],g[j]);
		int x=-1,L;
		for(int k=r-R;~k;k--)
			if(f[0][i+1][k]){x=k;break;}
		if(~x){
			L=max(0,l-x);
			if(R>=L) gmax(ans,s[R-L]);
		}
		
		int tx=x;x=-1;
		for(int k=tx;~k;k--)
			if(f[1][i+1][k]){x=k;break;}
		if(~x){
			L=max(0,l-x);
			if(R>=L) gmax(ans,s[R-L]+1);
		}
	}
	printf("%d\n",ans);
	return 0;
}