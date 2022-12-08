#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>
#define HEAP priority_queue
#define heap(...) priority_queue<__VA_ARGS__,vector<__VA_ARGS__>,greater<__VA_ARGS__> >
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define debuge cerr<<"isok"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define SS second
#define FF first
#define ls (k<<1)
#define rs (k<<1|1)
#define inf 0x3f3f3f3f
#define clr(a,x) memset(a,x,sizeof(a))
#define cpy(a,x) memcpy(a,x,sizeof(a))
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;

const int N=500005,M=100005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x=(x+y)%mod;}
const int BufferSize=1<<25;
char buffer[BufferSize],*Bufferhead,*Buffertail;
int Terminal;
inline char Getchar(){
	if(Bufferhead==Buffertail){
		int l=fread(buffer,1,BufferSize,stdin);
		if(!l){Terminal=1;return 0;}
		Buffertail=(Bufferhead=buffer)+l;
	}
	return *Bufferhead++;
}
template<class T> inline bool read(T &x){
	x=0;char c=Getchar(),rev=0;
	while(c<'0'||c>'9'){c=Getchar();rev|=c=='-';if(Terminal)return 0;}
	while(c>='0'&&c<='9') x=x*10+c-'0',c=Getchar();
	x=rev?-x:x;
	return 1;
}
template<class T>inline void print(T x,const char c='\n'){
	if(!x){putchar('0');putchar(c);return;}
	if(x<0) putchar('-'),x=-x;
	int m=0,a[20];
	while(x) a[m++]=x%10,x/=10;
	while(m--) putchar(a[m]+'0');
	putchar(c);
}
inline int exp(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

int n,k,a[N],b[N],c[N][3];
char p[N];
bool d[N][3];

pair<ll,int> calc(int mid){
	ll ans=0;int cnt=0;
//	debug(mid);
	heap(pair<pair<int,bool>,int>) q;
	for(int i=1;i<=n;i++) a[i]-=mid;
	for(int i=1;i<=n;i++) p[i]=0;
	for(int i=1;i<=n;i++){
		c[i][0]=b[i];d[i][0]=0;ans+=b[i];
		c[i][1]=min(0,b[i]+a[i]);d[i][1]=(c[i][1]<0);
		c[i][2]=a[i];d[i][2]=1;
	}
	for(int i=1;i<=n;i++){
		q.push(mp(mp(c[i][1]-c[i][0],d[i][1]^d[i][0]),i));
		pair<pair<int,bool>,int> t=q.top();q.pop();
		ans+=t.FF.FF;cnt+=t.FF.SS;p[t.SS]++;
		if(p[t.SS]==1) q.push(mp(mp(c[t.SS][2]-c[t.SS][1],d[t.SS][2]^d[t.SS][1]),t.SS));
	}
	for(int i=1;i<=n;i++) a[i]+=mid;
	return mp(ans,cnt);
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	read(n);read(k);
	for(int i=1;i<=n;i++)
		read(a[i]);
	for(int i=1;i<=n;i++)
		read(b[i]);
	int l=0,r=2e9+5;
	while(l<r){
		int mid=((ll)l+r+1)>>1;
		if(calc(mid).SS>k) r=mid-1; else l=mid;
	}
	print(calc(r).FF+(ll)r*k);
#ifdef rqgao2014
	cerr<<"time="<<clock()<<endl;
#endif
	return 0;
}