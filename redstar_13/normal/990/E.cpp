#include <bits/stdc++.h>



#define inf 0x3f3f3f3f

#define INF 0x3f3f3f3f3f3f3f3fLL

#define mod 1000000007

#define hmod 911382323

#define pb push_back

#define sq(x) ((x)*(x))

#define sz(a) ((int)a.size())

#define LEN(a) (a.length())

#define x first

#define y second

#define ls (u<<1)

#define rs (ls + 1)

#define mid (st + ed >> 1)

#define eps 1e-8

#define bpt(x) (__builtin_popcount(x))

#define bptl(x) (__builtin_popcountll(x))

#define bit(x, y) (((x)>>(y))&1)

#define bclz(x) (__builtin_clz(x))

#define bclzl(x) ((x) ? (__builtin_clzll(x)) : 0)

#define bctz(x) (__builtin_ctz(x))

#define bctzl(x) (__builtin_ctzll(x))

#define rands(n) (rand()%n+1)

#define rand0(n) (rands(n)-1)

#define Rands(n) ((INT)rand()*rand()%n+1)

#define Rand0(n) (Rands(n)-1)

#define PQ priority_queue<pii, vector<pii>, greater<pii> >

#define rep(i, a, b) for(int i=a; i<b; i++)

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

#define shit(a) (1 << (a))

#define all(a) ((a).begin(), (a).end())

#define rev(a) (power(a, mod-2, mod))



using namespace std;

typedef long long INT;

typedef unsigned long long UINT;

typedef unsigned int uint;

typedef complex<double> Complex;

typedef double DO;

typedef vector<int> VI;

typedef pair<int, int> pii;

typedef pair<INT, INT> PII;

typedef pair<pii, int> ppi;

typedef pair<int, pii> pip;

typedef pair<DO, DO> pdd;

typedef pair<int, DO> pid;

typedef pair<DO, int> pdi;



template<typename T, typename U> inline void smin(T &a, U b) {if (a>b) a=b;}

template<typename T, typename U> inline void smax(T &a, U b) {if (a<b) a=b;}



template<class T>inline void gn(T &x) {char c, sg=0; while (c=getchar(), (c>'9' || c<'0') && c!='-');for((c=='-'?sg=1, c=getchar():0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0';if (sg) x=-x;}

template<class T>inline void print(T x) {if (x<0) {putchar('-');return print(-x);}if (x<10) {putchar('0'+x);return;} print(x/10);putchar(x%10+'0');}

template<class T, class T1>inline void gn(T &x, T1 &y) {gn(x); gn(y);}

template<class T, class T1, class T2>inline void gn(T &x, T1 &y, T2 &z) {gn(x); gn(y); gn(z);}

template <class T> inline void println(T x) {print(x); putchar('\n');}

template <class T> inline void printsp(T x) {print(x); putchar(' ');}

template <class T1, class T2> inline void print(T1 x1, T2 x2) {printsp(x1), println(x2);}

template <class T1, class T2, class T3> inline void print(T1 x1, T2 x2, T3 x3) {printsp(x1), printsp(x2), println(x3);}

template <class T1, class T2, class T3, class T4> inline void print(T1 x1, T2 x2, T3 x3, T4 x4) {printsp(x1), printsp(x2), printsp(x3), println(x4);}

int power(int a, int b, int m, int ans=1) {

	for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;

	return ans;

}



#define NN 1000111

int flag[NN];

INT a[NN];

int pre[NN];

int cnt[NN];



int main() {

#ifndef ONLINE_JUDGE

	freopen("in.in", "r", stdin);

	freopen("out.out", "w", stdout);

#endif

	int n, m, k;

	gn(n, m, k);

	INT ans = INF;

	for(int i=0; i<m; i++) {

		int u;

		gn(u);

		flag[u] = 1;

	}

	for(int i=1; i<=k; i++) gn(a[i]);

	if(flag[0] == 1) return puts("-1");

	

	int mx=1, now=0;

	for(int i=0; i<m-1; i++) {

		if(flag[i]) now++;

		else now=0;

		smax(mx, now);

	}

	pre[0]=0;

	for(int i=1; i<n; i++) {

		if(flag[i]) pre[i] = pre[i-1];

		else pre[i] = i;

		cnt[i] =cnt[i-1] + (flag[i]==1);

	}

	

	for(int i=mx; i<=k; i++){

		now=0;

		int nx;

		INT tmp=0;

		while(now<n) {

			nx = now+i;

//			cerr<<i<<' '<<nx<<endl;

			tmp+=a[i];

			if(nx >= n) break;

			if(cnt[nx] - (now ? cnt[now-1] : 0) >= i) {tmp=INF;break;}

			nx = pre[nx];

			now = nx;

		}

		smin(ans, tmp);

	}

	cout << ((ans == INF) ? -1 : ans) << endl;



	return 0;

}