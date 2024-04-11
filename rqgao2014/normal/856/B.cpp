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
#define timeck()  dprintf("Case #%d solved, time = %d ms\n",argv,(int)(clock()*1000/CLOCKS_PER_SEC))
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
const int N=1000005,M=100005,mod=1e9+7;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

int n,m,a[N][26],dep[N],fail[N],dp[N][2];
char str[N];
vi g[N];
bool vis[N];

inline void add(int x,int y){g[x].pb(y);g[y].pb(x);}
inline void dfs(int x){
	vis[x]=1;
	dp[x][0]=0;dp[x][1]=1;
	for(int y:g[x]) 
		if(!vis[y]){
			dfs(y);
			dp[x][1]+=dp[y][0];
			dp[x][0]+=dp[y][1];
		}
	gmax(dp[x][1],dp[x][0]);
}

int Main(int argv){
	read(n);
	for(int i=1;i<=n;i++){
		reads(str);
		int l=strlen(str);
		for(int j=0,k=0;j<l;j++){
			if(!a[k][str[j]-'a']) a[k][str[j]-'a']=++m,dep[m]=dep[k]+1;
			k=a[k][str[j]-'a'];
		}
	}
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		int k=q.front();q.pop();
		if(fail[k]&&dep[fail[k]]==dep[k]-1) add(k,fail[k]);
		for(int i=0;i<26;i++){
			if(!a[k][i]) continue;
			q.push(a[k][i]);
			if(!k){fail[a[k][i]]=0;continue;}
			int t=fail[k];
			while(t&&!a[t][i]) t=fail[t];
			fail[a[k][i]]=a[t][i];
		}
	}
	int ans=0;
	for(int i=1;i<=m;i++)
		if(!vis[i]){dfs(i);ans+=dp[i][1];}
	print(ans);
#ifdef rqgao2014
	timeck();
#endif
	return 0;
}
void clear(){
	for(int i=0;i<=m;i++){
		g[i].clear(),fail[i]=dep[i]=vis[i]=0;
		for(int j=0;j<26;j++)
			a[i][j]=0;
	}m=0;
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	int T;scanf("%d",&T);
	for(int i=1;i<=T;i++)
		Main(i),clear();
	return 0;
}