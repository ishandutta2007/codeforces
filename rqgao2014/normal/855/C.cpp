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

int n,m,k,p,si[N],dp[N][12][3];
vi g[N];
bool vis[N];

void dfs(int x){
//	debug(x);
	vis[x]=si[x]=1;
	int now[12][3],tmp[12][3],f[12];
	clr(now,0);clr(f,0);
	now[0][2]=1;f[1]=1;
	for(int y:g[x]){
		if(vis[y]) continue;
		dfs(y);
		clr(tmp,0);
		for(int i=0;i<=p&&i<=si[x];i++)
			for(int j=0;j<=p-i&&j<=si[y];j++)
				for(int l=0;l<3;l++){
					if(!now[i][l]) continue;
					for(int r=0;r<3;r++)
						ch(tmp[i+j][min(l,r)],(ll)now[i][l]*dp[y][j][r]);
				}
		cpy(now,tmp);
		clr(tmp,0);
		for(int i=0;i<=p;i++){
			if(!f[i]) continue;
			for(int j=0;j<=p-i;j++){
				ch(tmp[i+j][0],(ll)dp[y][j][1]*f[i]);
				ch(tmp[i+j][0],(ll)dp[y][j][2]*f[i]%mod*k);
			}
		}
		for(int i=0;i<=p;i++)
			f[i]=tmp[i][0];
		si[x]+=si[y];
	}
//	debug(x);
	for(int i=0;i<=p;i++)
		for(int j=0;j<3;j++)
			ch(dp[x][i][min(j+1,2)],now[i][j]);
	for(int i=0;i<=p;i++)
		dp[x][i][1]=(ll)dp[x][i][1]*k%mod;
	for(int i=1;i<=p;i++)
		dp[x][i][0]=f[i];
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	read(n,m);
	for(int i=1;i<n;i++){
		int x,y;read(x,y);
		g[x].pb(y);g[y].pb(x);
	}
	read(k,p);p=min(p,n);
	k=(ll)(k-1)*exp(m-1,mod-2)%mod;
	dfs(1);
	int ans=0;
	for(int i=0;i<=p;i++)
		for(int j=0;j<3;j++)
			ch(ans,(ll)dp[1][i][j]*exp(m-1,n-i));
	print(ans);
	return 0;
}