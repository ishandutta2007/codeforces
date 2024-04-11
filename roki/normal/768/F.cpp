#include <bits/stdc++.h>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i,l,r) for (int i = int(l); i <= int(r); i++)
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define mp make_pair
#define pb push_back
#define ft first
#define sc second
#define x first
#define y second

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

int n, m, h;

inline bool read() {
	cin >> n >> m >> h;
	return true;
}

const int N = 500000;

int f[N];

const int MOD = 1e9 + 7;

int mul(int a, int b) {
	return li(a) * b % MOD;
}

int bp(int a, int b) {
	int res = 1;
	while(b) {
		if (b & 1)
			res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

int modinverse(int n) {
	return bp(n, MOD - 2);
}

int C(int n, int k) {
	return mul(f[n], modinverse(mul(f[k], f[n - k])));
}

int g(int n, int k, int h) {
	if (k < 0)
		return 0;
	if (k == 0)
		return n == 0;
	if (li(k) * h > n)
		return 0;
	n -= k * h;
	return C(n + k - 1, k - 1);
}
   
void upd(int &a, int b) {
	a += b;
	while(a >= MOD)
		a -= MOD;
}

inline void solve() {   
	f[0] = 1;
	forn (i, N - 1)
		f[i + 1] = mul(f[i], i + 1);
	int num = 0;
	forn (i, m + 1) {
		int x = g(m, i, h + 1);
		upd(num, mul(x, g(n, i - 1, 1)));
		upd(num, mul(x, g(n, i, 1)));
		upd(num, mul(x, g(n, i, 1)));
		upd(num, mul(x, g(n, i + 1, 1)));
	}
	int den = 0;
	forn (i, m + 1) {
		int x = g(m, i, 1);
		upd(den, mul(x, g(n, i - 1, 1)));
		upd(den, mul(x, g(n, i, 1)));
		upd(den, mul(x, g(n, i, 1)));
		upd(den, mul(x, g(n, i + 1, 1)));
	}
	cout << mul(num, modinverse(den)) << endl;
}

int main()
{
#ifdef SU2
	assert(freopen("input.txt", "r", stdin));
	assert(freopen("output.txt", "w", stdout));
#endif

	cout << setprecision(25) << fixed;
	cerr << setprecision(10) << fixed;

	srand(int(time(NULL)));

	assert(read());
	solve();

#ifdef SU2
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}