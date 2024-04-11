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
const int N=505,M=100005,mod=1e9+7;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

int m,F,B,p[N],b[N];
int h[N],res[N],dp[N],one[N];
ll n;

inline void mul(int *a,int *b,int *res){
	static int tmp[N];
	clr(tmp,0);
	for(int i=0;i<=m;i++)
		for(int j=0;j<=m;j++)
			ch(tmp[i+j],(ll)a[i]*b[j]);
	int inv=exp(h[m],mod-2);
	for(int i=m*2;i>=m;i--){
		int t=(ll)tmp[i]*inv%mod;
		if(!t) continue;
		for(int j=0;j<=m;j++)
			ch(tmp[i-m+j],-(ll)t*h[j]);
	}
	for(int i=0;i<=m;i++) res[i]=tmp[i];
}
inline void solve(int *A,int *res,ll n){
	static int a[N];
	for(int i=0;i<=m;i++) a[i]=A[i];
	for(int i=0;i<=m;i++) res[i]=!i;
	while(n){
		if(n&1) mul(res,a,res);
		mul(a,a,a);n>>=1;
	}
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d%lld",&F,&B,&n);
	for(int i=1;i<=F;i++)
		scanf("%d",&p[i]);
	for(int i=1;i<=B;i++)
		scanf("%d",&b[i]),gmax(m,b[i]),h[b[i]]--;
	dp[0]=1;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=B;j++)
			if(i>=b[j]) ch(dp[i],dp[i-b[j]]);
	reverse(h,h+m+1);
	h[m]=one[1]=1;
	for(int i=1;i<=F;i++){
		static int tmp[N];
		solve(one,tmp,p[i]);
		for(int j=0;j<=m;j++)
			ch(res[j],tmp[j]);
	}
	solve(res,res,n);
	int ans=0;
	for(int i=0;i<=m;i++)
		ch(ans,(ll)res[i]*dp[i]);
	if(ans<0) ans+=mod;
	printf("%d\n",ans);
	return 0;
}