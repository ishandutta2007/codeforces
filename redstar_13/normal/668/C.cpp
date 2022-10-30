#include<bits/stdc++.h>

#define pb push_back
#define sz(a) ((int)a.size())
#define x first
#define y second
#define bpt(x) (__builtin_popcount(x))
#define bit(x, y) (((x)>>(y))&1)
#define bclz(x) (__builtin_clz(x))
#define bctz(x) (__builtin_ctz(x))

using namespace std;

typedef long double DO;
typedef long long INT;
typedef pair<int, int> pii;
typedef vector<int> VI;

template<typename T, typename U> inline void smin(T &a, U b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, U b) {if(a<b) a=b;}

template<class T>inline void gn(T &x) {char c, sg=0; while (c=getchar(), (c>'9' || c<'0') && c!='-');for((c=='-'?sg=1, c=getchar():0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0';if (sg) x=-x;}
template<class T>inline void print(T x) {if (x<0) {putchar('-');return print(-x);}if (x<10) {putchar('0'+x);return;} print(x/10);putchar(x%10+'0');}
template <class T> inline void println(T x) {print(x); putchar('\n');}

int power(int a, int b, int m, int ans=1) {
	for(; b; b>>=1, a=1LL*a*a%m) if(b&1) ans=1LL*ans*a%m;
	return ans;
}

#define NN 100011

int n;
DO A[NN], B[NN];
DO p[NN], q[NN];

int solve() {
	cin >> n;
	for(int i=1; i<=n; i++) {
		double f; scanf("%lf", &f);
		A[i]=f+A[i-1];
	}
	for(int i=1; i<=n; i++) {
		double f; scanf("%lf", &f);
		B[i]=f+B[i-1];	
	}
	DO D;
	for(int i=1; i<=n; i++) {
		B[i]+=A[i];
		D=sqrtl(B[i]*B[i]-4*A[i]+1e-14);
		q[i]=(B[i]+D)/2; p[i]=(B[i]-D)/2;
	}
	for(int i=n; i>=1; i--) q[i]-=q[i-1], p[i]-=p[i-1];
	for(int i=1; i<=n; i++) printf("%.6lf ", (double)p[i]); puts("");
	for(int i=1; i<=n; i++) printf("%.6lf ", (double) q[i]); puts("");
	
}

int main() {
#ifndef	ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	solve();
	return 0;
}