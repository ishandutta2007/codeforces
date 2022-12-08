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
const int N=300005,M=100005,mod=1e9+7;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

int n,m,S,T,p[N],typ[N];

inline int solve(vi a){
	int m=SZ(a)-1,mx=0;
	for(int i=0;i<m;i++)
		gmax(mx,a[i+1]-a[i]);
	return mx;
}

int main(){
#ifdef rqgao2014
	assert(freopen("input.txt","r",stdin));
#endif
	read(n);
	for(int i=1;i<=n;i++){
		char tmp[10];
		read(p[i]);reads(tmp);
		typ[i]=(tmp[0]=='R')+(tmp[0]=='B')*2;
	}
	for(int i=1;i<=n;i++) if(!typ[i]){S=i;break;}
	for(int i=n;i;i--) if(!typ[i]){T=i;break;}
	int ans=0;
	if(!S){
		int mn=inf,mx=0;
		for(int i=1;i<=n;i++)
			if(typ[i]==1) gmin(mn,p[i]),gmax(mx,p[i]);
		if(mx)ans+=mx-mn;
		mn=inf,mx=0;
		for(int i=1;i<=n;i++)
			if(typ[i]==2) gmin(mn,p[i]),gmax(mx,p[i]);
		if(mx)ans+=mx-mn;
		printf("%d\n",ans);
		return 0;
	}
	for(int i=S;i<T;){
		int r=i+1;
		while(typ[r]) r++;
		vi R(0),B(0);
		R.pb(p[i]);B.pb(p[i]);
		for(int j=i+1;j<r;j++)
			if(typ[j]==1) R.pb(p[j]); else B.pb(p[j]);
		R.pb(p[r]);B.pb(p[r]);
		ans+=(p[r]-p[i])+min((p[r]-p[i]),(p[r]-p[i])*2-solve(R)-solve(B));
		i=r;
	}
	int ar,ab;
	ar=ab=p[S];
	for(int i=1;i<S;i++)
		if(typ[i]==1) gmin(ar,p[i]); else gmin(ab,p[i]);
	ans+=p[S]*2-ar-ab;
	ar=ab=p[T];
	for(int i=T+1;i<=n;i++)
		if(typ[i]==1) gmax(ar,p[i]); else gmax(ab,p[i]);
	ans-=p[T]*2-ar-ab;
	printf("%d\n",ans);
	return 0;
}