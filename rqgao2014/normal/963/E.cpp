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
const int N=115,M=8005,mod=1e9+7;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

int n,A,R,p1,p2,p3,p4,num[N][N];
int a[M][M],d[M];

inline void gauss(){
	for(int i=1;i<=n;i++){
		int t=0,en=min(i+A*2,n);
		for(int j=i;j<=en;j++)
			if(a[j][i]){t=j;break;}
		assert(t==i);
		if(t^i){
			for(int j=i;j<=n;j++)
				swap(a[i][j],a[t][i]);
		}
		int inv=exp(a[i][i],mod-2),tot=0;
		for(int j=i;j<=en;j++)
			if(a[i][j]) d[++tot]=j;
		d[++tot]=n+1;
		for(int j=i+1;j<=en;j++){
			if(!a[j][i]) continue;
			int p=(ll)a[j][i]*inv%mod;
			for(int k=1;k<=tot;k++)
				ch(a[j][d[k]],-(ll)a[i][d[k]]*p);
		}
	}
	for(int i=n;i;i--){
		d[i]=a[i][n+1];
		for(int j=i+1;j<=n;j++)
			if(a[i][j]) ch(d[i],-(ll)a[i][j]*d[j]);
		d[i]=(ll)d[i]*exp(a[i][i],mod-2)%mod;
	}
}

int main(){
#ifdef rqgao2014
	assert(freopen("input.txt","r",stdin));
#endif
	scanf("%d%d%d%d%d",&R,&p1,&p2,&p3,&p4);
	int sum=p1+p2+p3+p4;A=R+3;
	p1=(ll)p1*exp(sum,mod-2)%mod;
	p2=(ll)p2*exp(sum,mod-2)%mod;
	p3=(ll)p3*exp(sum,mod-2)%mod;
	p4=(ll)p4*exp(sum,mod-2)%mod;
	for(int i=-R;i<=R;i++)
		for(int j=-R;j<=R;j++)
			if(sqr(i)+sqr(j)<=sqr(R)) num[i+A][j+A]=++n;
	for(int i=-R;i<=R;i++)
		for(int j=-R;j<=R;j++){
			int x=num[i+A][j+A];
			if(!x) continue;
			a[x][x]=1;
			a[x][num[i-1+A][j+A]]=mod-p1;
			a[x][num[i+A][j-1+A]]=mod-p2;
			a[x][num[i+1+A][j+A]]=mod-p3;
			a[x][num[i+A][j+1+A]]=mod-p4;
			a[x][n+1]=1;
		}
	gauss();
	printf("%d\n",(d[num[A][A]]+mod)%mod);
	return 0;
}