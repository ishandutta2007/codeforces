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
const int N=200005,M=100005,mod=1e9+7;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

char s[N];
int n,Q;

struct sam{
	int last,cnt,a[N][26],ri[N],fa[N],mx[N],pos[N];
	int seq[N],tot;
	vi g[N];
	sam(){last=cnt=1;}
	inline void extend(int i,int c){
		int p=last,np=++cnt;last=np;
		ri[np]=pos[np]=i;mx[np]=mx[p]+1;
		while(p&&!a[p][c]) a[p][c]=np,p=fa[p];
		if(!p){fa[np]=1;return;}
		int q=a[p][c];
		if(mx[q]==mx[p]+1){fa[np]=q;return;}
		int nq=++cnt;cpy(a[nq],a[q]);
		ri[nq]=i;mx[nq]=mx[p]+1;fa[nq]=fa[q];
		fa[q]=fa[np]=nq;
		while(p&&a[p][c]==q) a[p][c]=nq,p=fa[p];
	}
	inline void dfs(int x){
		if(pos[x]) seq[++tot]=pos[x];
		for(int y:g[x])
			dfs(y);
	}
	inline void build(){
		for(int i=2;i<=cnt;i++)
			g[fa[i]].pb(i);
	}
	inline int calc(char *s,int m,int k){
		int now=1;
		for(int i=1;i<=m;i++)
			now=a[now][s[i]-'a'];
		tot=0;dfs(now);
		if(tot<k) return -1;
		sort(seq+1,seq+tot+1);
		int ans=inf;
		for(int i=1;i<=tot-k+1;i++)
			gmin(ans,seq[i+k-1]-seq[i]);
		return ans+m;
	}
}p;

int main(){
#ifdef rqgao2014
	assert(freopen("input.txt","r",stdin));
#endif
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1;i<=n;i++)
		p.extend(i,s[i]-'a');
	p.build();
	scanf("%d",&Q);
	for(int i=1;i<=Q;i++){
		static char str[N];
		int k,m;
		scanf("%d%s",&k,str+1);
		m=strlen(str+1);
		printf("%d\n",p.calc(str,m,k));
	}
	return 0;
}