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
const int bnd=500;
const int N=1000005,M=100005,mod=1e9+7;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

int n,d[bnd+5][2005];
vi pat[10005],v[N];
map<ll,int> to;
inline void srch(int x,int last=2){
	static vi now;
	if(x>bnd) return;
	pat[++n]=now;
	for(int i=last;i<=42;i++){
		if(i==23||i==29||i==31||i==37||i==41) continue;
		now.pb(i-1);srch(x*i,i);now.pop_back();
	}
}
inline int getn(vi a){
	sort(all(a));ll ha=0;
	int c=1;
	for(int i:a) c*=i+1,ha=ha*45+i;
	if(c>bnd) return 0;
	return to[ha];	
}
inline void solve(int tar,int *d){
	queue<int> q;
	for(int i=1;i<=n;i++){
		d[i]=0;
		int c=1;
		for(int j:pat[i]) c*=j+1;
		if(c==tar) q.push(i),d[i]=1;
	}
	while(!q.empty()){
		int x=q.front();
		vi a=pat[x];q.pop();
		for(int i=0;i<SZ(a);i++){
			int y;
			a[i]++;y=getn(a);if(y&&!d[y]) d[y]=d[x]+1,q.push(y);a[i]--;
			a[i]--;y=getn(a);if(y&&!d[y]) d[y]=d[x]+1,q.push(y);a[i]++;
		}
		a.pb(1);int y=getn(a);
		if(y&&!d[y]) d[y]=d[x]+1,q.push(y);
	}
	for(int i=1;i<=n;i++) if(!d[i]) d[i]=inf;
}

void prepare(){
	static bool vis[N];
	int n=1e6;
	for(int i=2;i<=n;i++)
		if(!vis[i]){
			for(int j=i;j<=n;j+=i){
				vis[j]=1;
				int t=j,c=0;
				while(t%i==0) t/=i,c++;
				v[j].pb(c);
			}
		}
	int mx=0;
	for(int j=2;j<=n;j++)
		sort(all(v[j]));
	srch(1);
	for(int i=1;i<=::n;i++){
		ll ha=0;
		for(int k:pat[i]) ha=ha*45+k;
		to[ha]=i;
	}
	for(int i=1;i<=bnd;i++)
		solve(i,d[i]);	
}

int main(){
#ifdef rqgao2014
	assert(freopen("input.txt","r",stdin));
#endif
	prepare();
	int T;scanf("%d",&T);
	while(T--){
		int a,b;
		scanf("%d%d",&a,&b);
		int x=getn(v[a]),y=getn(v[b]);
		int ans=inf;
		for(int i=1;i<=bnd;i++)
			gmin(ans,d[i][x]+d[i][y]);
		printf("%d\n",ans-2);
	}
		
	return 0;
}