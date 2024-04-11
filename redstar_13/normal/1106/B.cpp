#include <bits/stdc++.h>

#define x first
#define y second
#define _ls (u<<1)
#define _rs (_ls|1)
#define _mid (L+R>>1)
#define pb push_back
#define sq(x) ((x)*(x))
#define SZ(x) ((x).size())
#define _get(l,r) (l+r|l!=r)
#define sgn(a) ((a>eps)-(a<-eps))
#define bit(x,y) (((x)>>(y))&1)
#define bctz(x) (__builtin_ctz(x))
#define bclz(x) (__builtin_clz(x))
#define bclzl(x) (__builtin_clzll(x))
#define bctzl(x) (__builtin_ctzl(x))
#define bpt(x) (__builtin_popcount(x))
#define bptl(x) (__builtin_popcountll(x))
#define PQ priority_queue<pii,vector<pii>,greater<pii> >

using namespace std;
typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef pair<pii, int> pi3;
typedef double DO;

template<typename T, typename U> inline void smin(T &a, const U &b) {if (a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if (a<b) a=b;}

#define INPUT_LEN 1000
#define gets my_gets
char gchar() {static char tbuf1[INPUT_LEN],*tmp_st=tbuf1,*tmp_ed=tbuf1;if(tmp_st==tmp_ed){int len=fread(tbuf1,1,INPUT_LEN,stdin);if (len==0)return -1;tmp_ed=tbuf1+len;tmp_st=tbuf1;}return*(tmp_st++);}
inline bool gn(int &x) {char c, sg=0;while (c=gchar(),(c>'9'||c<'0')&&c!='-'&&c!=-1);if (c==-1) return 0;for((c=='-'?sg=1,c=gchar():0),x=0;c>='0'&&c<='9';c=gchar())x=(x<<1)+(x<<3)+c-'0';if (sg) x=-x;return 1;}
inline bool gn(INT &x) {char c, sg=0;while (c=gchar(),(c>'9'||c<'0')&&c!='-'&&c!=-1);if (c==-1) return 0;for((c=='-'?sg=1,c=gchar():0),x=0;c>='0'&&c<='9';c=gchar())x=(x<<1)+(x<<3)+c-'0';if (sg) x=-x;return 1;}
inline bool gn(char &x) {while(x=gchar(),x!=-1&&isspace(x));return x!=-1;}
inline bool gn(string &s){char c;s.clear();while(c=gchar(),c!=-1&&isspace(c));if(c!=-1)s+=c;while(c=gchar(),c!=-1&&!isspace(c))s+=c;return c!=-1;}
inline bool gn(DO &x) {string s;bool ok=gn(s);x=atof(s.c_str());return ok;}
inline bool gn(char *s) {string s1;bool ok=gn(s1);strcpy(s,s1.c_str());return ok;}
inline bool gets(char *s) {char c,t=0;while(c=gchar(),c!=-1&&c!='\n')*s++=c,t=1;*s=0;return c!=-1 || t;};

inline void print(int x) {if(x<0){putchar('-');return print(-x);}if(x<10){putchar('0'+x);return;}print(x/10);putchar(x%10+'0');}
inline void print(INT x) {if(x<0){putchar('-');return print(-x);}if(x<10){putchar('0'+x);return;}print(x/10);putchar(x%10+'0');}
inline bool print(char &x) {putchar(x);}
inline void print(DO &x){printf("%.10lf", x);}
inline void print(char *s){printf("%s", s);}
inline void print(string &s){printf("%s", s.c_str());}

template<class T,class T1>inline bool gn(T &x, T1 &y) {bool ok=gn(x); gn(y);return ok;}
template<class T,class T1,class T2>inline bool gn(T &x, T1 &y, T2 &z){bool ok=gn(x); gn(y); gn(z);return ok;}
template<class U,class V,class W,class X>inline bool gn(U &u, V &v, W &w, X &x){bool ok=gn(u,v);gn(w,x);return ok;}
template<class T>inline void printsp(T x) {print(x);putchar(' ');}
template<class T>inline void println(T x) {print(x);putchar('\n');}
template<class T,class U>inline void print(T x, U y){printsp(x);println(y);}
template<class T,class U,class V>inline void print(T x, U y, V z){printsp(x);print(y,z);}
template<class T,class U,class V,class W>inline void print(T x, U y, V z,W w){printsp(x);print(y, z, w);}

inline int power(int a, int b, int m, int ans=1) {
	for(; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;
	return ans;
}
const int NN=101010;
int a[NN],c[NN],I[NN];

inline bool cmp(int i,int j){
	if(c[i]!=c[j]) return c[i]<c[j];
	return i<j;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
//	freopen("in.in", "w", stdout);
#endif
	int n,m;gn(n,m);
	for(int i=1; i<=n; i++){
		gn(a[i]);
		I[i]=i;
	}
	for(int i=1; i<=n; i++) gn(c[i]);
	sort(I+1,I+n+1,cmp);
	int pos=1,t,d;
	while(m--){
		gn(t,d);
		if(a[t]>=d) {
			a[t]-=d;
			println((INT)d*c[t]);
		}else{
			INT ans=0;
			ans+=(INT)a[t]*c[t];
			d-=a[t];
			a[t]=0;
			while(d>0 && pos<=n){
				if(a[I[pos]]>=d){
					a[I[pos]]-=d;
					ans+=(INT)d*c[I[pos]];
					d=0;
				}else{
					d-=a[I[pos]];
					ans+=(INT)c[I[pos]]*a[I[pos]];
					a[I[pos]]=0;
					pos++;
				}
			}
			if(d>0) puts("0");
			else println(ans);
		}
//		for(int i=1; i<=n; i++) printsp(a[i]);puts("");puts("");
	}
	return 0;
}