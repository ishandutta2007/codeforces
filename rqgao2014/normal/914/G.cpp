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

char bits[N];
int n,m,lg,mx,a[N],b[N],c[N],f[N];

inline void fwt(int *a,int l,int r){
	if(l==r) return;
	int mid=l+r>>1;
	fwt(a,l,mid);fwt(a,mid+1,r);
	for(int i=l;i<=mid;i++){
		int y=a[i-l+mid+1];
		a[i-l+mid+1]=(a[i]-y)%mod;
		a[i]=(a[i]+y)%mod;
	}
}

inline void s1(int *a,int *b){
	static int t1[19][N],t2[19][N];
	for(int i=0;i<m;i++)
		t1[bits[i]][i]=a[i];
	for(int i=0;i<=lg;i++)
		fwt(t1[i],0,m-1);
	for(int i=0;i<=lg;i++)
		for(int j=0;j<=lg;j++){
			if(i+j>lg) continue;
			for(int k=0;k<m;k++)
				ch(t2[i+j][k],(ll)t1[i][k]*t1[j][k]);
		}
	for(int i=0,inv=exp(m,mod-2);i<=lg;i++){
		fwt(t2[i],0,m-1);
		for(int j=0;j<m;j++)
			t2[i][j]=(ll)t2[i][j]*inv%mod;
	}
	for(int i=0;i<m;i++)
		b[i]=t2[bits[i]][i];
}
inline void s2(int *a,int *b){
	static int tmp[N];
	for(int i=0;i<m;i++)
		tmp[i]=a[i];
	fwt(tmp,0,m-1);
	for(int i=0;i<m;i++)
		tmp[i]=(ll)tmp[i]*tmp[i]%mod;
	fwt(tmp,0,m-1);
	for(int i=0,inv=exp(m,mod-2);i<m;i++)
		tmp[i]=(ll)tmp[i]*inv%mod;
	for(int i=0;i<m;i++)
		b[i]=tmp[i];
}


int main(){
#ifdef rqgao2014
	assert(freopen("input.txt","r",stdin));
#endif
	read(n);
	for(int i=1;i<=n;i++){
		int x;read(x);
		gmax(mx,x);a[x]++;
	}
	m=1;lg=0;
	while(m<=mx) m<<=1,lg++;
	for(int i=1;i<m;i++)
		bits[i]=bits[i^(i&-i)]+1;
	f[0]=0;f[1]=1;
	for(int i=2;i<=m;i++)
		f[i]=(f[i-1]+f[i-2])%mod;
	s1(a,b);
	s2(a,c);
	for(int i=0;i<m;i++)
		a[i]=(ll)a[i]*f[i]%mod,b[i]=(ll)b[i]*f[i]%mod,c[i]=(ll)c[i]*f[i]%mod;
	for(int i=0;i<lg;i++)
		for(int j=0;j<m;j++)
			if(j&(1<<i)) ch(a[j^(1<<i)],a[j]),ch(b[j^(1<<i)],b[j]),ch(c[j^(1<<i)],c[j]);
	for(int i=0;i<m;i++)
		a[i]=(ll)a[i]*b[i]%mod*c[i]%mod;
	for(int i=0;i<lg;i++)
		for(int j=0;j<m;j++)
			if(j&(1<<i)) ch(a[j^(1<<i)],-a[j]);
	int ans=0;
	for(int i=0;i<lg;i++)
		ch(ans,a[1<<i]);
	if(ans<0) ans+=mod;
	printf("%d\n",ans);
	return 0;
}