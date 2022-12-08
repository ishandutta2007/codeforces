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
const int N=100005,M=100005,mod=1e9+7;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

int n,m,a[N];
vi b[N];
bool flag,v[100][100];

inline bool check(){
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++)
			if(v[b[i][j]][b[i+1][j]]) return 0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
			if(v[b[i][j]][b[i][j+1]]) return 0;
	return 1;
}

int main(){
#ifdef rqgao2014
	assert(freopen("input.txt","r",stdin));
#endif
	scanf("%d%d",&n,&m);
	if(n*m<=9){
		for(int i=0;i<=n+2;i++)
			b[i].resize(m+3);
		for(int i=1;i<=n*m;i++) a[i]=i;
		for(int i=1;i<n;i++)
			for(int j=1;j<=m;j++)
				v[(i-1)*m+j][i*m+j]=v[i*m+j][(i-1)*m+j]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<m;j++)
				v[(i-1)*m+j][(i-1)*m+j+1]=v[(i-1)*m+j+1][(i-1)*m+j]=1;
		do{
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++)
					b[i][j]=a[(i-1)*m+j];
			if(check()){
				puts("YES");
				for(int i=1;i<=n;i++,puts(""))
					for(int j=1;j<=m;j++)
						printf("%d ",b[i][j]);
				return 0;
			}
		}while(next_permutation(a+1,a+n*m+1));
		puts("NO");return 0;
	}
	puts("YES");
	if(n>m) swap(n,m),flag=1;
	for(int i=0;i<=n+2;i++)
		b[i].resize(m+3);
	if(m&1){
		for(int i=m,j=1;i>0;i-=2,j++)
			b[1][j]=i;
		for(int i=m-1,j=m/2+2;i>0;i-=2,j++)
			b[1][j]=i;
		for(int i=m-2,j=1;i>0;i-=2,j++)
			b[2][j]=i;
		for(int i=m-1,j=m/2+1;i>0;i-=2,j++)
			b[2][j]=i;
		b[2][m]=m;
		for(int i=3;i<=n;i++)
			if(i&1) b[i]=b[1]; else b[i]=b[2];
	}
	else{
		for(int i=m-1,j=1;i>0;i-=2,j++)
			b[1][j]=i;
		for(int i=m,j=m/2+1;i>0;i-=2,j++)
			b[1][j]=i;
		for(int i=2;i<=n;i++){
			b[i]=b[1];
			if(i%2==0) reverse(b[i].begin()+1,b[i].begin()+m+1);
		}
	}
	for(int i=2;i<=n;i++)
		for(int j=1;j<=m;j++)
			b[i][j]+=(i-1)*m;
	if(!flag){
		for(int i=1;i<=n;i++,puts(""))
			for(int j=1;j<=m;j++)
				printf("%d ",b[i][j]);
	}
	else{
		for(int i=1;i<=m;i++,puts(""))
			for(int j=1;j<=n;j++){
				int x=(b[j][i]-1)/m+1,y=(b[j][i]-1)%m+1;
				printf("%d ",(y-1)*n+x);
			}
	}
	return 0;
}