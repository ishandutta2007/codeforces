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

int n, m, a, q;

int mul(int a, int b, int mod) {
	return (int)(li(a) * b % mod);
}

int add(int a, int b, int mod) {
	a += b;
	while (a < 0) {
		a += mod;
	}
	while (a >= mod) {
		a -= mod;
	}
	return a;
}

int binpow(int a, int k, int mod) {
	int res = 1;
	while (k) {
		if (k & 1) {
			res = mul(res, a, mod);
		}
		a = mul(a, a, mod);
		k >>= 1;
	}
	return res;
}

bool read() {
	scanf("%d%d%d%d", &n, &m, &a, &q);
	return true;
}

const int N = (int)1e6 + 10;

int fact[N];
int invf[N];

int b[N];
int ans[N];

int calcc(int n, int k, int mod) {
	if (k < 0 || k > n) {
		return 0;
	}
	if (k == 0 || k == n) {
		return 1;
	}
	return mul(fact[n], mul(invf[k], invf[n - k], mod), mod);
}

void solve() {
	int phi = 0;
	int cur = 1;
	while (phi == 0 || cur != 1) {
		cur = mul(cur, a, q);
		phi++;
	}
	//cerr << phi << endl;
	assert(phi > 0 && binpow(a, phi, q) == 1);
	fact[0] = 1;
	for1(i, N) {
		fact[i] = mul(fact[i - 1], i, phi);
	}
	forn(i, N) {
		invf[i] = binpow(fact[i], phi - 2, phi);
	}
	b[0] = 1;
	for1(i, n) {
		b[i] = add(b[i - 1], calcc(m, i, phi), phi);
	}
	forn(i, n) {
		ans[i] = binpow(a, b[i], q);
	}
	forr(i, n) {
		printf("%d ", ans[i]);
	}
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