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

int n,a[N],b[N];
int f[1<<16],to[1<<16];
pii from[1<<16];
queue<int> q;
vector<pair<int,pii> > ans;

void prepare(){
	int n=9;clr(f,0);
	f[0]=1;q.push(0);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++){
				int k=j*2-i;
				if(k>=n){
					int y=x^(1<<i)^(1<<j);
					if(!f[y]) q.push(y),f[y]=f[x]+1,from[y]=mp(i,j),to[y]=x;
				}
				else{
					int y=x^(1<<i)^(1<<j)^(1<<k);
					if(!f[y]) q.push(y),f[y]=f[x]+1,from[y]=mp(i,j),to[y]=x;
				}
			}
	}
}
void solve(int n,int l){
	clr(f,0);
	int st=0;
	for(int i=0;i<n;i++) st|=a[i]<<i;
	f[st]=1;q.push(st);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++){
				int k=j*2-i;
				if(k>=n) break;
				int y=x^(1<<i)^(1<<j)^(1<<k);
				if(!f[y]) q.push(y),f[y]=f[x]+1,from[y]=mp(i,j),to[y]=x;
			}
	}
	if(!f[0]){puts("NO");exit(0);}
	int k=0;
	while(k!=st){
		int i=from[k].FF,j=from[k].SS,kk=j*2-i;
		ans.pb(mp(i+l,mp(j+l,kk+l)));
		k=to[k];
	}
}

int main(){
#ifdef rqgao2014
	assert(freopen("input.txt","r",stdin));
	freopen("output.txt","w",stdout);
#endif
	prepare();
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]),b[i]=a[i];
	int l=0;
	while(n-l>=17){
		int st=0;
		for(int i=0;i<9;i++)
			st|=(a[i+l]<<i);
		while(st){
			int i=from[st].FF,j=from[st].SS,k=j*2-i;
			a[i+l]^=1;a[j+l]^=1;a[k+l]^=1;
			ans.pb(mp(i+l,mp(j+l,k+l)));
			st=to[st];//dprintf("%d\n",st);
		}
		l+=9;
	}
//	debuge;
	for(int i=0;i<n-l;i++)
		a[i]=a[i+l];
	solve(n-l,l);
	puts("YES");
	printf("%d\n",SZ(ans));
	for(auto i:ans){
		int x=i.FF,y=i.SS.FF,z=i.SS.SS;
		printf("%d %d %d\n",i.FF+1,i.SS.FF+1,i.SS.SS+1);
		assert(y-x==z-y&&0<=x&&x<=y&&y<=z&&z<n);
		b[x]^=1;b[y]^=1;b[z]^=1;
	}
	debug(SZ(ans));
	for(int i=0;i<n;i++)
		assert(!b[i]);
	return 0;
}