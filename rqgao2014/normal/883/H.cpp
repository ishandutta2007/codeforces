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
const int N=400005,M=100005,mod=1e9+7;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

int n,cnt[100],c1;
char s[N],ans[N];

inline int f(char c){
	if(c>='a') return c-'a';
	if(c>='A') return c-'A'+26;
	return c-'0'+52;
}
inline char g(int c){
	if(c>=52) return c-52+'0';
	if(c>=26) return c-26+'A';
	return c+'a';
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		cnt[f(s[i])]++;
	for(int i=0;i<62;i++)
		if(cnt[i]&1) c1++;
	if(!c1){
		puts("1");
		for(int i=0,p=0;i<62;i++)
			for(int j=1;j<=cnt[i];j+=2)
				p++,ans[p]=ans[n+1-p]=g(i);
		printf("%s\n",ans+1);
		return 0;
	}
	for(int d=c1;d<=n;d+=2)
		if(n%d==0&&(n/d&1)){
			printf("%d\n",d);
			static int no[N],tot,L=n/d;
			for(int i=0;i<62;i++)
				if(cnt[i]&1) no[++tot]=i,cnt[i]--;
			for(int i=0;i<62;i++)
				while(tot<d&&cnt[i]) no[++tot]=i,cnt[i]--;
			for(int i=1;i<=d;i++){
				ans[(L+1)/2]=g(no[i]);
				int now=0;
				for(int j=0;j<62;j++)
					while(now<L/2&&cnt[j]) ans[++now]=g(j),ans[L-now+1]=g(j),cnt[j]-=2;
				printf("%s%c",ans+1,i<d?' ':'\n');
			}
			return 0;
		}
	return 0;
}