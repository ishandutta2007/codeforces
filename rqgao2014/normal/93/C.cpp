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

int n,ans,a[10];
bool u[256];
inline bool check(int x,int dep){
	for(int i=1;i<dep;i++)
		for(int j=1;j<=8&&j*a[i]<=x;j<<=1)
			if(u[x-j*a[i]]) return 1;
	return 0;
}
inline bool dfs(int dep=2,int st=2){
	if(check(n,dep)){a[dep]=n;return 1;}
	if(dep==ans) return 0;
	for(int i=st;i<n;i++)
		if(check(i,dep)){
			a[dep]=i,u[i]=1;
			if(dfs(dep+1,i+1)) return 1;
			u[i]=0;
		}
	return 0;
}
inline bool calc(){
	a[1]=1;u[1]=u[0]=1;
	return dfs();
}

inline bool p1(int i,int j,int k){printf("lea e%cx, [%d*e%cx]\n",i+'a'-1,k,j+'a'-1);}
inline bool p2(int i,int j,int k){
	int idx=lower_bound(a+1,a+ans+1,a[i]-a[j]*k)-a;
	printf("lea e%cx, [e%cx + %d*e%cx]\n",i+'a'-1,idx+'a'-1,k,j+'a'-1);
}
inline void make(int i){
	for(int j=1;j<i;j++)
		for(int k=1;k<=8&&a[j]*k<=a[i];k<<=1){
			if(a[j]*k==a[i]){p1(i,j,k);return;}
			else if(u[a[i]-a[j]*k]){p2(i,j,k);return;}
		}
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&n);
	if(n==1){puts("0");return 0;}
	ans=2;
	while(!calc()) ans++;
	printf("%d\n",ans-1);
	clr(u,0);
//	for(int i=1;i<=ans;i++) printf("%d ",a[i]);puts("");
	u[1]=1;
	for(int i=2;i<=ans;i++){
		make(i);
		u[a[i]]=1;
	}
	return 0;
}