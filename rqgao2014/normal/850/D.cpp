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
const int N=65,M=100005,mod=1e9+7;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

int n,m,tot,a[N],b[N];
bool dp[N][N][N*N],now[N*N],ans[N][N];

void calc(){
	n=tot;
	printf("%d\n",n);
	reverse(b+1,b+n+1);
//	for(int i=1;i<=n;i++) printf("%d ",b[i]);puts("");
	for(int i=1;i<n;i++){
		int k=n-i-b[i];
		int x=b[n-k+1],cnt=k;
		for(int j=n;j>i&&cnt;j--)
			if(b[j]>x) b[j]--,cnt--,ans[j][i]=1;
		for(int j=i+1;j<=n&&cnt;j++)
			if(b[j]==x) b[j]--,cnt--,ans[j][i]=1;
		b[i]=0;
		for(int j=1;j<=n;j++)
			dprintf("%d ",b[j]);fputs("\n",stderr);
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(!ans[j][i]) ans[i][j]=1;
	for(int i=1;i<=n;i++,puts(""))
		for(int j=1;j<=n;j++)
			putchar(ans[i][j]+'0');
}
inline void solve(int i,int j,int k){
	if(!i) return;
	for(int x=1;x<=j;x++)
		if(dp[i-1][j-x][k-x*a[i]]){
			for(int p=1;p<=x;p++)
				b[++tot]=a[i];
			solve(i-1,j-x,k-x*a[i]);
			return;
		}
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	read(m);
	for(int i=1;i<=m;i++)
		read(a[i]),gmax(n,a[i]+1);
	sort(a+1,a+m+1);n<<=1;
	dp[0][0][0]=1;
	for(int i=1;i<=m;i++){
		clr(now,0);
		for(int j=0;j<=n;j++)
			for(int k=j*(j-1)/2;k<=n*(n-1)/2;k++){
				dp[i][j][k]=now[j*a[i]-k];
				now[j*a[i]-k]|=dp[i-1][j][k];
			}
	}
	n>>=1;
	for(int i=n;i<=n*2;i++)
		if(dp[m][i][i*(i-1)/2]){
			solve(m,i,i*(i-1)/2);
			calc();
			
			return 0;
		}
	puts("=(");
	return 0;
}