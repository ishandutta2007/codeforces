#include <bits/stdc++.h>

#define x first
#define y second
#define eps 1e-8
#define pb push_back
#define mod 1000000007
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3fLL
#define bit(x, y) (((x)>>(y))&1)
#define bctz(x) (__builtin_ctz(x))
#define bclz(x) (__builtin_clz(x))
#define bclzl(x) (__builtin_clzll(x))
#define bctzl(x) (__builtin_ctzll(x))
#define bpt(x) (__builtin_popcount(x))
#define bptl(x) (__builtin_popcountll(x))
#define PQ priority_queue<pii, vector<pii>, greater<pii> >

using namespace std;

typedef double DO;
typedef long long INT;
typedef pair<int, int> pii;
typedef pair<pii, int> pi3;
typedef vector<int> VI;

template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

template<typename T> inline void gn(T &x) {char c, sg=0; while (c=getchar(), (c>'9' || c<'0') && c!='-');for((c=='-'?sg=1, c=getchar():0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0';if (sg) x=-x;}
template<class T, class T1>inline void gn(T &x, T1 &y) {gn(x); gn(y);}
template<class T, class T1, class T2>inline void gn(T &x, T1 &y, T2 &z) {gn(x); gn(y); gn(z);}
template<typename T> inline void print(T x) {if (x<0) {putchar('-');return print(-x);}if (x<10) {putchar('0'+x);return;} print(x/10);putchar(x%10+'0');}
template<typename T> inline void println(T x) {print(x), putchar('\n');}
template<typename T> inline void printsp(T x) {print(x), putchar(' ');}
template<class T, class T1> inline void print(T x, T1 y) {printsp(x), println(y);}
template<class T, class T1, class T2> inline void print(T x, T1 y, T2 z) {printsp(x), printsp(y), println(z);}

int power(int a, int b, int m, int ans=1) {
	for (; b; b>>=1, a=(INT)a*a%m) if (b&1) ans=(INT)ans*a%m;
	return ans;
}
#define NN 10010
int p[NN];
int vst[NN];
int np;

void pre(){
	for(int i=2;i<NN;i++){
		if(vst[i]) continue;
		p[++np]=i;
		for(int j=i;j<NN;j+=i) vst[j]=1;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	pre();
	int q;
	scanf("%d",&q);
	while(q--){
		int a;
		scanf("%d",&a);
		int n=0;
		int st=1;
		while(st<=a){
			n++;
			st*=2;
		}
		if(a!=st-1){
			printf("%d\n",(1<<n)-1);
			continue;
		}
		int flag=0;
		for(int i=1;i<=np&&p[i]<a;i++){
			if(a%p[i]==0){
				a/=p[i];
				flag=1;
				break;
			}
		}
		if(flag) printf("%d\n",a);
		else puts("1");
	}
  return 0;
}