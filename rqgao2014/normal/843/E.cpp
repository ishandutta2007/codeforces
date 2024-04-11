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
//--------------------------------------------------head--------------------------------------------------

const int inf=0x3f3f3f3f;
const int N=2005,M=100005,mod=1e9+7;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

struct node{int to,next,w;};
node p[M];
int n,m,tot,S,T,st[N],head[N],e[M];
bool vis[N];
void add(int x,int y,int z){
	p[++tot]=(node){y,head[x],z};head[x]=tot;
	p[++tot]=(node){x,head[y],0};head[y]=tot;		
}
void build(int nn,int mm,int ss,int tt){n=nn;S=ss;T=tt;tot=1;clr(head,0);}
inline int dfs(int x,int f){
	if(x==T) return f;
	int r=0;
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to,tmp;
		if(st[y]!=st[x]+1||!p[i].w) continue;
		tmp=dfs(y,min(f-r,p[i].w));
		p[i].w-=tmp;p[i^1].w+=tmp;
		r+=tmp;if(r==f) break;
	}
	if(!r) st[x]=-1;
	return r;
}
bool bfs(){
	queue<int> q;
	q.push(S);
	clr(st,-1);st[S]=1;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=head[x];i;i=p[i].next){
			int y=p[i].to;
			if(~st[y]||!p[i].w) continue;
			st[y]=st[x]+1;q.push(y);
		}
	}
	return ~st[T];
}
int dinic(){
	int ans=0,t=0;
	while(bfs())
		while(t=dfs(S,inf)) ans+=t;
	return ans;
}

void dfs(int x){
	vis[x]=1;
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to;
		if(vis[y]||!p[i].w) continue;
		dfs(y);
	}
}

int u[M],v[M],g[M],must[M];

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	int S,T;
	read(n,m,S,T);
	build(n,m,S,T);
	for(int i=1;i<=m;i++){
		read(u[i],v[i],g[i]);
		if(!g[i]) add(u[i],v[i],inf); else add(u[i],v[i],1);
	}
	for(int i=1;i<=m;i++)
		if(g[i]) add(v[i],u[i],inf);
	printf("%d\n",dinic());
	dfs(S);
	for(int i=1;i<=n;i++)
		if(vis[i]){
			for(int j=head[i];j;j=p[j].next){
				int y=p[j].to;
				if(!vis[y]) must[j>>1]=1;
			}
		}
	build(n,m,0,n+1);
	for(int i=1;i<=m;i++)
		if(g[i]){
			add(0,v[i],1),add(u[i],n+1,1);
			add(u[i],v[i],inf);
			e[i]=tot;
		}
	add(T,S,inf);
	dinic();
	for(int i=1;i<=m;i++){
		if(!g[i]){puts("0 1");continue;}
		int f=p[e[i]].w+1,c=f+1-must[i];
		printf("%d %d\n",f,c);
	}
	return 0;
}