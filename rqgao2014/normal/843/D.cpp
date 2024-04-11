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

const ll inf=0x3f3f3f3f3f3f3f3f;
const int N=100005,M=100005,mod=1e9+7;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

int n,m,Q,head[N],_next[N],to[N],w[N],tmp[N];
ll d[N];
bool vis[N];

inline void add(int x,int y){
	_next[y]=head[x];head[x]=y;
}
void dijkstra(){
	static heap(pair<ll,int>) q;
	for(int i=1;i<=n;i++) d[i]=inf;
	d[1]=0;q.push(mp(0,1));
	while(!q.empty()){
		int x=q.top().SS;q.pop();
		for(int i=head[x];i;i=_next[i]){
			int y=to[i];
			if(d[y]>d[x]+w[i]){
				d[y]=d[x]+w[i];
				q.push(mp(d[y],y));
			}
		}
	}
}
int tot,top[N*10],fa[N],q[N];
void push(int k,int x){
	q[++tot]=x;fa[tot]=top[k];top[k]=tot;
}
void update(int k)noexcept{
	tot=0;
	for(int i=0;i<=k;i++)
		top[i]=0;
	for(int i=1;i<=n;i++)
		tmp[i]=k+1,vis[i]=0;
	tmp[1]=0;
	push(0,1);
	for(int i=0;i<=k;i++)
		while(top[i]){
			int x=q[top[i]];top[i]=fa[top[i]];
//			dprintf("%d\n",x);
			if(vis[x]) continue;
			vis[x]=1;d[x]+=i;
			for(int j=head[x];j;j=_next[j]){
				int y=to[j];
				if(d[x]+w[j]-d[y]<tmp[y]){
					tmp[y]=d[x]+w[j]-d[y];
					push(tmp[y],y);
				}
			}
		}
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	read(n,m,Q);
	for(int i=1;i<=m;i++){
		int x;read(x,to[i],w[i]);
		add(x,i);
	}
	dijkstra();
	int upd=1,cnt=0;
	while(Q--){
		int typ,k;
		read(typ,k);
//		dprintf("%d ",typ);
		if(typ==1){
			if(!upd) update(cnt),cnt=0,upd=1;
			print(d[k]>=inf?-1:d[k]);
		}
		else{
			for(int i=1;i<=k;i++){
				int x;
				read(x),w[x]++;
			}
			cnt+=k;upd=0;
		}
	}
	return 0;
}