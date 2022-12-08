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
const int N=100005,M=100005,mod=1e9+7,K=16;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

int n,m;
struct node{
	int h,cnt[20];
	char pre[35],suf[35];
	bitset<(1<<K+1)> v;
}a[205];

inline node make(char *s){
	int m=strlen(s+1);
	node tmp;
	tmp.v=0;
	for(int L=1;L<=K;L++){
		tmp.cnt[L]=0;
		for(int l=1;l+L-1<=m;l++){
			int r=l+L-1,st=1<<L;
			for(int i=l;i<=r;i++)
				st|=(s[i]-'0')<<i-l;
			if(!tmp.v[st]) tmp.v[st]=1,tmp.cnt[L]++;
		}
	}
	if(m>=K){
		tmp.h=K;
		for(int i=1;i<=K;i++)
			tmp.pre[i]=s[i];
		for(int i=1;i<=K;i++)
			tmp.suf[i]=s[m-K+i];
		tmp.pre[K+1]=tmp.suf[K+1]=0;
	}
	else{
		tmp.h=m;
		for(int i=1;i<=m;i++)
			tmp.pre[i]=tmp.suf[i]=s[i];
		tmp.pre[m+1]=tmp.suf[m+1]=0;
	}
	return tmp;
}

inline void con(char *a,char *b,char *s){
	int lh=strlen(a+1);
	int rh=strlen(b+1);
	for(int i=1;i<=lh;i++) s[i]=a[i];
	for(int i=lh+1;i<=lh+rh;i++) s[i]=b[i-lh];
	s[lh+rh+1]=0;
}

inline node merge(node l,node r){
	if(l.h<K&&r.h<K){
		char s[100];
		con(l.pre,r.pre,s);
//		printf("%s\n",s+1);
		return make(s);
	}
	node tmp;
	tmp.h=K;
	tmp.v=l.v|r.v;
	char s[100];
	con(l.suf,r.pre,s);
	tmp.v|=make(s).v;
	for(int i=1;i<=K;i++)
		if(i>l.h) tmp.pre[i]=r.pre[i-l.h]; else tmp.pre[i]=l.pre[i];
	tmp.pre[K+1]=0;
	if(r.h<K){
		for(int i=1;i<=K-r.h;i++)
			tmp.suf[i]=l.suf[r.h+i];
		for(int i=K-r.h+1;i<=K;i++)
			tmp.suf[i]=r.suf[i-K+r.h];
	}
	else{
		for(int i=1;i<=K;i++)
			tmp.suf[i]=r.suf[i];
	}
	tmp.suf[K+1]=0;
	for(int i=1;i<=K;i++){
		tmp.cnt[i]=0;
		for(int j=0;j<(1<<i);j++)
			if(tmp.v[j|(1<<i)]) tmp.cnt[i]++;
	}
	return tmp;
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		char s[105];
		scanf("%s",s+1);
		a[i]=make(s);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		a[i+n]=merge(a[x],a[y]);
		int mx=0;
		for(int j=1;j<=K;j++)
			if(a[i+n].cnt[j]==(1<<j)) mx=j;
		printf("%d\n",mx);
	}
	return 0;
}