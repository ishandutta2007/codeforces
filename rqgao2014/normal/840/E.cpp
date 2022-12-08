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
inline bool reads(char *x){
	char c=Getchar();
	while(c<33||c>126){c=Getchar();if(Terminal)return 0;}
	while(c>=33&&c<=126) (*x++)=c,c=Getchar();
	*x=0;return 1;
}
template<class T>inline void print(T x,const char c){
	if(!x){putchar('0');putchar(c);return;}
	if(x<0) putchar('-'),x=-x;
	int m=0,a[20];
	while(x) a[m++]=x%10,x/=10;
	while(m--) putchar(a[m]+'0');
	putchar(c);
}
//--------------------------------head---------------------------------------------

const int inf=0x3f3f3f3f;
const int N=100005,M=100005,mod=1e9+7,B=256;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

#define type unsigned short 

int n,m;
type dp[N][B],a[N],dep[N],fa[N],anc[N],f[B];
vector<type> g[N];
bool vis[N],use[B][8];

void dfs(int x){
	vis[x]=1;
	for(int y:g[x]){
		if(vis[y]) continue;
		fa[y]=x;dep[y]=dep[x]+1;
		dfs(y);
	}
	if(dep[x]>=B){
		type p=x;
		clr(f,0);clr(use,0);
		for(type i=0;i<B;i++,p=fa[p]){
			gmax(f[a[p]>>8],(type)((a[p]&255)^i));
			use[a[p]>>8][0]=1;
		}
		anc[x]=p;
		for(type j=1;j<8;j++)
			for(type i=0;i<B;i++)
				if(i+(1<<j)<=B) use[i][j]=use[i][j-1]|use[i+(1<<j-1)][j-1];
		for(type i=0;i<B;i++){
			type l=0,r=B-1;
			for(short j=7;~j;j--){
				type mid=l+r>>1;
				if(i&(1<<j)){
					if(use[l][j]) r=mid; else l=mid+1;
				}
				else if(use[mid+1][j]) l=mid+1; else r=mid;
			}
			dp[x][i]=((l^i)<<8)|f[l];
		}
	}
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	read(n);read(m);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<n;i++){
		type x,y;read(x);read(y);
		g[x].pb(y);g[y].pb(x);
	}
	dep[1]=1;dfs(1);
//	debuge;
	while(m--){
		type u,v,d,s=0,ans=0;read(u);read(v);
		u=fa[u];d=dep[v]-dep[u];
		for(type i=0;(i+1<<8)<=d;i++)
			gmax(ans,dp[v][i]),v=anc[v],s+=B;
		for(type i=s;i<d;i++)
			gmax(ans,(type)(a[v]^i)),v=fa[v];
		print(ans,'\n');
	}
	return 0;
}