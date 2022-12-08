#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>
#define HEAP priority_queue
#define heap(T) priority_queue<T,vector<T>,greater<T> > 
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

const int N=100005,M=100005,mod=1e9+7;
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
template<class T>inline void print(T x,const char c){
	if(!x){putchar('0');putchar(c);return;}
	if(x<0) putchar('-'),x=-x;
	int m=0,a[10];
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

int tot,p[N];
int Main(){
	int a,b;scanf("%d%d",&a,&b);
	ll n=(ll)a*b;
	ll l=1,r=1000000;
	while(l<r){
		ll mid=l+r>>1;
		if(mid*mid*mid>=n) r=mid; else l=mid+1;
	}
	if(r*r*r!=n) return 0;
	if(a%r!=0||b%r!=0) return 0;
	return 1;
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	int n;scanf("%d",&n);
	for(int i=2;i<=40000;i++){
		bool isok=1;
		for(int j=2;j*j<=i;j++)
			if(i%j==0){isok=0;break;}
		if(isok) p[++tot]=i;
	}
	for(int i=1;i<=n;i++)
		puts(Main()?"Yes":"No");
	return 0;
}