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
const int N=100005,M=100005,mod=1e9+7;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

int n,m,ans,p1[9],p2[9],u[9],v[9];
map<int,bool> vis,son;

inline bool good(int x)noexcept{return x>0&&x<=n&&!vis[x];}
inline void ins(int x){
	vis[x]=1;
	for(int i=x;i&&!son[i];i>>=1)
		son[i]=1;
}
inline int size(int l,int r)noexcept{
	if(l>n) return 0;
	if(r>=n) return n-l+1;
	return r-l+1+size(l<<1,r<<1|1);
}
inline int dfs(int x){
	if(!son[x]){
		ins(x);
		int res=size(x,x);
		if(good(x/2)) res+=dfs(x/2);
		return res;
	}
	ins(x);
	int res=1;
	if(good(x<<1)) res+=dfs(x<<1);
	if(good(x<<1|1)) res+=dfs(x<<1|1);
	if(good(x/2)) res+=dfs(x/2);
	return res;
}
inline int lca(int x,int y,bool flag=1){
	if(vis[x]||vis[y]) return 0;
	if(flag) ins(x),ins(y);
	while(x!=y){
		if(y>x) swap(x,y);
		x>>=1;
		if(vis[x]&&x!=y) return 0;
		if(flag) ins(x);
	}
	return x;
}
inline vi find(int x,int y){
	int p=lca(x,y);
	vi L(0),R(0);
	while(x!=p) L.pb(dfs(x)),x>>=1;
	while(y!=p) R.pb(dfs(y)),y>>=1;
	L.pb(dfs(p));
	reverse(R.begin(),R.end());
	for(int i:R) L.pb(i);
	return L;
}

inline int solve(int step){
	vis.clear();son.clear();
	for(int i=1;i<step;i++)
		if(!lca(v[i],u[i+1])) return 0;
	if(vis[u[1]]||vis[v[step]]||u[1]==v[step]) return 0;
//	for(int i=1;i<=step;i++) printf("%d %d\n",u[i],v[i]);
//	puts("");
	if(!lca(u[1],v[step],0))
		return (ll)dfs(u[1])*dfs(v[step])%mod;
//	debug(vis[1]);
	vi a=find(u[1],v[step]);
	ll ans=0;
	for(int i=0;i<a.size();i++)
		for(int j=i+1;j<a.size();j++)
			ans+=(ll)a[i]*a[j];
	return ans%mod;
}
void dfs(int step,int st){
	if(step>1) ch(ans,solve(step-1));
	for(int i=1;i<=m;i++)
		if(!(st&(1<<i-1))){
			u[step]=p1[i];v[step]=p2[i];
			dfs(step+1,st|(1<<i-1));
			u[step]=p2[i];v[step]=p1[i];
			dfs(step+1,st|(1<<i-1));
		}
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
//	debug(size(2,2));
	for(int i=1;i<=m;i++)
		scanf("%d%d",&p1[i],&p2[i]);
	dfs(1,0);
	ch(ans,(ll)n*n);
	printf("%d\n",ans);
	return 0;
}