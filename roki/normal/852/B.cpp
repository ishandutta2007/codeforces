#include<bits/stdc++.h>

using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define for1(i, n) for(int i = 1; i < int(n); ++i)
#define fork(i, k, n) for(int i = int(k); i <= int(n); ++i)
#define forft(i, from, to) for(int i = int(from); i < int(to); ++i)
#define forr(i, n) for(int i = int(n) - 1; i >= 0; --i)
#define pb push_back
#define mp make_pair
#define mnp(a, b) make_pair((a) < (b) ? (a) : (b), (a) < (b) ? (b) : (a))
#define sz(d) int(d.size())
#define all(a) a.begin(), a.end()
#define ms(a, v) memset(a, v, sizeof(a))
#define msn(a, v, n) memset(a, v, n * sizeof(a[0]))
#define mcn(dst, src, n) memcpy(dst, src, n * sizeof(src[0]))
#define X first
#define Y second
#define correct(x, y, xmax, ymax) ((x) >= 0 && (x) < (xmax) && (y) >= 0 && (y) < (ymax))

template<typename T> T sqr(const T &x) {
	return x * x;
}

template<typename T> T my_abs(const T &x) {
	return x < 0 ? -x : x;
}

typedef long long li;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long uli;
typedef long double ld;
typedef pair<int,int> pt;
typedef pair<li,li> pli;
typedef pair<ld,ld> pd;

const int INF = (int)1e9;
const li LINF = (li)6e18;
const li INF64 = LINF;
const li INFLL = LINF;
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932384626433832795;

const int M = 105;
const int N = (int)1e6 + 10;
const int MOD = (int)1e9 + 7;

typedef int matrix[M][M];

int n, m, l;

int sc[N];
int fc[N];
int c[N];

int add(int a, int b) {
	a += b;
	while (a < 0) {
		a += MOD;
	}
	while (a >= MOD) {
		a -= MOD;
	}
	return a;
}

int mul(int a, int b) {
	return (int)((li)a * b % MOD);
}

void mul(matrix a, matrix b, matrix c) {
	forn(i, m) {
		forn(j, m) {
			c[i][j] = 0;
			forn(k, m) {
				c[i][j] = add(c[i][j], mul(a[i][k], b[k][j]));
			}
		}
	}
}

void mul(int v[M], matrix b, int vr[M]) {
	forn(j, m) {
		vr[j] = 0;
		forn(k, m) {
			vr[j] = add(vr[j], mul(v[k], b[k][j]));
		}
	}
}

matrix tmp;

void copym(matrix src, matrix dst) {
	forn(i, m) {
		forn(j, m) {
			dst[i][j] = src[i][j];
		}
	}
}

void binpow(matrix a, int k, matrix c) {
	forn(i, m) {
		forn(j, m) {
			c[i][j] = i == j;
		}
	}
	while (k) {
		if (k & 1) {
			mul(a, c, tmp);
			copym(tmp, c);
		}
		mul(a, a, tmp);
		copym(tmp, a);
		k >>= 1;
	}
}

bool read() {
	scanf("%d%d%d", &n, &l, &m);
	forn(i, n) {
		scanf("%d", &sc[i]);
	}
	forn(i, n) {
		scanf("%d", &c[i]);
	}
	forn(i, n) {
		scanf("%d", &fc[i]);
	}
	return true;
}

int cnt[M];

matrix t;

matrix tl;

int vs[M];
int vr[M];

void solve() {
	forn(i, n) {
		cnt[c[i] % m]++;
	}
	forn(i, m) {
		forn(j, m) {
			t[i][(i + j) % m] = cnt[j];
		}
	}
	binpow(t, l - 2, tl);
	/*forn(i, m) {
		forn(j, m) {
			cerr << tl[i][j] << ' ';
		}
		cerr << endl;
	}
	cerr << endl;*/
	forn(i, n) {
		vs[sc[i] % m]++;
	}
	/*forn(i, m) {
		cerr << vs[i] << ' ';
	}
	cerr << endl;*/
	mul(vs, tl, vr);
	/*forn(i, m) {
		cerr << vr[i] << ' ';
	}
	cerr << endl;*/
	int ans = 0;
	forn(i, n) {
		int need = (c[i] + fc[i]) % m;
		need = (m - need) % m;
		//cerr << need << endl;
		ans = add(ans, vr[need]);
	}
	printf("%d\n", ans);
}

//#define FILES

#define TASK "taskname"

int main() {

#ifdef SU2_PROJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
#ifdef FILES	
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
#endif
#endif
	
	srand((unsigned int)time(NULL));

	cout << setprecision(15) << fixed;

	read();
	solve();
	
#ifdef SU2_PROJ
	cerr << "time: " << clock() << " ms" << endl;
#endif

	return 0;
}