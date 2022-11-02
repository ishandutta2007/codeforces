#include <bits/stdc++.h>



#define inf 0x3f3f3f3f

#define MOD 1000000007

#define pb push_back

#define sq(x) ((x)*(x))

#define x first

#define y second

#define eps 1e-9

#define bpt(x) (__builtin_popcount(x))

#define bptl(x) (__builtin_popcountll(x))

#define bit(x, y) (((x)>>(y))&1)

#define bclz(x) (__builtin_clz(x))

#define bclzl(x) (__builtin_clzll(x))

#define bctz(x) (__builtin_ctz(x))

#define bctzl(x) (__builtin_ctzll(x))

#define sgn(x) (((x)>eps)-((x)<-eps))

#define PQ priority_queue<pii, vector<pii>, greater<pii> >



using namespace std;

typedef long long INT;

typedef vector<int> VI;

typedef pair<int, int> pii;

typedef pair<pii, int> pi3;

typedef double DO;



template<typename T, typename U> inline void smin(T &a, U b) {if (a>b) a=b;}

template<typename T, typename U> inline void smax(T &a, U b) {if (a<b) a=b;}



template<class T>inline void gn(T &x) {char c, sg=0; while (c=getchar(), (c>'9' || c<'0') && c!='-');for((c=='-'?sg=1, c=getchar():0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0';if (sg) x=-x;}

template<class T, class T1>inline void gn(T &x, T1 &y) {gn(x); gn(y);}

template<class T, class T1, class T2>inline void gn(T &x, T1 &y, T2 &z) {gn(x); gn(y); gn(z);}

template<class T>inline void print(T x) {if (x<0) {putchar('-');return print(-x);}if (x<10) {putchar('0'+x);return;} print(x/10);putchar(x%10+'0');}

template<class T>inline void printsp(T x) {print(x); putchar(' ');}

template<class T>inline void println(T x) {print(x); putchar('\n');}

template<class T, class U>inline void print(T x, U y) {printsp(x); println(y);}

template<class T, class U, class V>inline void print(T x, U y, V z) {printsp(x); printsp(y); println(z);}



int power(int a, int b, int m, int ans=1) {

	for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;

	return ans;

}



#define NN 5050

int a[NN];

int mx[NN][NN];

int f[NN][NN];

int ed[NN][NN];



int main() {

#ifndef ONLINE_JUDGE

	freopen("in.in", "r", stdin);

	freopen("out.out", "w", stdout);

#endif

	int n;

	cin >> n;

	for(int i=1; i<=n; i++) gn(a[i]);

	for(int len=1; len<=n; len++) {

		for(int i=1; i+len-1<=n; i++) {

			if(len == 1) f[i][i] = a[i];

			else f[i][i+len-1] = f[i][i+len-2] ^ f[i+1][i+len-1];

		}

	}

	for(int i=1; i<=n; i++) {

		for(int j=i; j>=1; j--) {

			if(i == j) ed[i][j] = a[j];

			else ed[i][j] = max(ed[i][j+1], f[j][i]);

		}

	}

	//for(int i=1; i<=n; i++) for(int j=i; j<=n; j++) cout << i << ' '<< j << ' '<< f[j][i] << endl;

	for(int i=1; i<=n; i++) {

		mx[i][i] = a[i];

		for(int j=i+1; j<=n; j++) {

			mx[i][j] = max(mx[i][j-1], ed[j][i]);

		}

	}

	int q;

	gn(q);

	while(q--) {

		int l, r;

		gn(l, r);

		printf("%d\n", mx[l][r]);

	}

	return 0;

}