#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double 
#define vi vector<int>
#define HEAP(T) priority_queue<T>
#define heap(T) priority_queue<T,vector<T>,greater<T> > 
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define debuge cerr<<"isok"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define error(...) fprintf(stderr,__VA_ARGS__)
#define SS second
#define FF first
#define ls (k<<1)
#define rs (k<<1|1)
#define inf 0x3f3f3f3f
#define clr(a,x) memset(a,x,sizeof(a))
#define cpy(a,x) memcpy(a,x,sizeof(a))
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
using namespace std;

const double eps=1e-12;
const int N=2505,M=100005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
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
	x=rev?-x:x;
	return 1;
}
inline bool reads(char *x){
	char c=Getchar();
	while(c<33||c>126){c=Getchar();if(Terminal)return 0;}
	while(c>=33&&c<=126) (*x++)=c,c=Getchar();
	*x=0;return 1;
}
template<class T>inline void print(T x,const char c){
	if(!x){putchar('0');putchar(c);return;}
	if(x<0) putchar('-'),x=-x;
	int m=0,a[10];
	while(x) a[m++]=x%10,x/=10;
	while(m--) putchar(a[m]+'0');
	putchar(c);
}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

struct node{int x,y;}a[N<<1];
int n;
double ans,mn=1e9,dp[N<<1][N][2],d[N][N];

inline double get(int l,int r){
	if(l>n) l-=n;
	if(r>n) r-=n;
	return d[l][r];
}
inline double solve(int l,int r,int k){
	if(l==r-1) return 0;
	int x=r-l;
	if(dp[l][x][k]>eps) return dp[l][x][k];
	if(!k){
		gmax(dp[l][x][k],solve(l,r-1,1)+get(l,r-1));
		gmax(dp[l][x][k],solve(l+1,r,0)+get(l+1,l));
	}
	else{
		gmax(dp[l][x][k],solve(l,r-1,1)+get(r,r-1));
		gmax(dp[l][x][k],solve(l+1,r,0)+get(l+1,r));
	}
	return dp[l][x][k];
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			d[j][i]=d[i][j]=sqrt(sqr((double)a[i].x-(double)a[j].x)+sqr((double)a[i].y-(double)a[j].y));
	for(int i=n+1;i<=n*2;i++)
		a[i]=a[i-n];
	for(int i=1;i<=n;i++){
		double d=get(i,i+1);
		gmin(mn,d);ans+=d;
	}
	for(int i=1;i<=n*2;i++)
		for(int j=0;j<=n;j++)	
			dp[i][j][0]=dp[i][j][1]=-1;
	ans-=mn;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			gmax(ans,solve(i,j,0)+solve(j,i+n,0)+d[i][j]);
			gmax(ans,solve(i,j,1)+solve(j,i+n,1)+d[i][j]);
		}
	printf("%.12f\n",ans);
	return 0;
}