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
const int N=100005,M=100005,mod=1e9+7;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

ll dp[105][12][12],f[12][105];
inline ll solve(int x,int a,int b){
	if(!x){
		if(!b) return 1;
		return 0;
	}
	if(~dp[x][a][b]) return dp[x][a][b];
	dp[x][a][b]=0;
	if(a) dp[x][a][b]+=solve(x-1,a-1,b+1)*a;
	if(b) dp[x][a][b]+=solve(x-1,a+1,b-1)*b;
	return dp[x][a][b];
}
inline ll calc(int b,int x){return solve(x-1,b-1,1)*(b-1);}
inline ll get(int b,ll n){
	if(!n) return 0;
	int m=0,a[105];
	while(n) a[++m]=n%b,n/=b;
	reverse(a+1,a+m+1);
	ll ans=0;
	for(int i=2;i<m;i+=2)
		ans+=calc(b,i);
//	debug(ans);
	if(m%2==0){
		int x=b,y=0;
		bool vis[12];
		clr(vis,0);
		ans+=(a[1]-1)*solve(m-1,b-1,1);
		for(int i=2;i<=m;i++){
			if(vis[a[i-1]]) y--,x++; else x--,y++;
			vis[a[i-1]]^=1;
			for(int j=0;j<a[i];j++)
				if(vis[j]) ans+=solve(m-i,x+1,y-1); else ans+=solve(m-i,x-1,y+1);
		}
		if(vis[a[m]]) y--,x++; else x--,y++;
		if(!y) ans++;
	}
	return ans;
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	int Q;read(Q);
	clr(dp,-1);
	clr(f,-1);
//	debug(solve(2,2,0));
	while(Q--){
		int b;ll l,r;
		read(b,l,r);
		print(get(b,r)-get(b,l-1));
	}
	return 0;
}