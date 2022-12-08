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
const int N=50005,M=100005,mod=1e9+7;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

int n,k,a[N][15],rk[15][N];
pii b[N];
set<pii> s;
set<pii> now[15];

inline int to(int k,int b){
	set<pii>::iterator it=now[k].upper_bound(mp(b,0));
	if(it==now[k].begin()) return 0;
	it--; return (*it).SS;
}
inline int from(int k,int b){
	set<pii>::iterator it=now[k].upper_bound(mp(b,0));
	if(it==now[k].end()) return inf;
	return (*it).SS;
}
int top(){
	set<pii>::iterator it=s.end();it--;
	return (*it).SS;
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	read(n,k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k;j++)
			read(a[i][j]);
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++)
			b[j]=mp(a[j][i],j);
		sort(b+1,b+n+1);
		for(int j=1;j<=n;j++)
			rk[i][b[j].SS]=j;
	}
	s.insert(mp(rk[1][1],1));
	print(top());
	for(int i=1;i<=k;i++)
		now[i].insert(mp(rk[i][1],rk[1][1]));
	for(int i=2;i<=n;i++){
		int mn=inf,mx=0;
		for(int j=1;j<=k;j++)
			gmax(mx,to(j,rk[j][i])),gmin(mn,from(j,rk[j][i]));
//		dprintf("%d %d\n",mn,mx);
		
		mx=mx?(*s.lower_bound(mp(mx,0))).FF:0;
		mn=mn<inf?(*s.lower_bound(mp(mn,0))).FF:inf;
		if(mx>=mn){
//			debuge;
			set<pii>::iterator it=s.lower_bound(mp(mn,0));
			int si=1;
			vector<pii> del(0);
			while(it!=s.end()&&(*it).FF<=mx){
//				dprintf("set: %d %d\n",(*it).FF,(*it).SS);
				si+=(*it).SS;del.pb(*it);
				it++;
			}
			for(auto i:del) s.erase(i);
			s.insert(mp(max(mx,rk[1][i]),si));
		}
		else s.insert(mp(rk[1][i],1));
		print(top());
		for(int j=1;j<=k;j++)
			now[j].insert(mp(rk[j][i],rk[1][i]));
	}
	return 0;
}