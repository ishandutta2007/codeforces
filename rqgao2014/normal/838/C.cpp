#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>
#define HEAP(T) priority_queue<T>
#define heap(T) priority_queue<T,vector<T>,greater<T> > 
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define debuge cerr<<"isok"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define error(...) fprintf(stderr,__VA_ARGS__)
#define SS second
#define FF first
#define ls (k<<1)
#define rs (k<<1|1)
#define inf 0x3f3f3f3f
#define clr(a,x) memset(a,x,sizeof(a))
#define cpy(a,x) memcpy(a,x,sizeof(a))
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
using namespace std;

const int N=300005,M=100005;
int mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
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
	x=rev?-x:x;
	return 1;
}
inline bool reads(char *x){
	char c=Getchar();
	while(c<33||c>126){c=Getchar();if(Terminal)return 0;}
	while(c>=33&&c<=126) (*x++)=c,c=Getchar();
	*x=0;return 1;
}
template<class T>inline void print(T x,const char c){
	if(!x){putchar('0');putchar(c);return;}
	if(x<0) putchar('-'),x=-x;
	int m=0,a[10];
	while(x) a[m++]=x%10,x/=10;
	while(m--) putchar(a[m]+'0');
	putchar(c);
}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

int n,k,fac[N],ifac[N],dp[2][N];
inline int C(int x,int y){return (ll)fac[x]*ifac[x-y]%mod*ifac[y]%mod;}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d%d",&n,&k,&mod);
	ifac[0]=fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=(ll)fac[i-1]*i%mod;
	ifac[n]=exp(fac[n],mod-2);
	for(int i=n-1;i;i--) ifac[i]=(ll)ifac[i+1]*(i+1)%mod;
	if(n&1){
		printf("%d\n",exp(k,n));
		return 0;
	}
	int ans=0;
	dp[0][n]=1;
	for(int i=1;i<=k;i++){
		clr(dp[i&1],0);
		int res=0;
		for(int j=1;j<=n;j++){
			int tmp=dp[i-1&1][j];
			if(!tmp) continue;
			int u=j^(j&-j);
			for(int k=u;k;k=(k-1)&u)
				ch(dp[i&1][k],(ll)tmp*C(j,k));
			ch(res,tmp);
		}
		ch(ans,(ll)res*ifac[k-i]);
	}
	ans=(ll)ans*fac[k]%mod;
	ans=(exp(k,n)-ans+mod)%mod;
	printf("%d\n",ans);
	return 0;
}