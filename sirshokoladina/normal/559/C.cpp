#include <bits/stdc++.h>
using namespace std;

#ifdef SG
	#include <debug.h>
#else
	#define show(...)
	#define debug(...)
	#define deepen(...)
	#define timer(...)
#endif

#define ARG4(_1,_2,_3,_4,...) _4

#define forn3(i,l,r) for (int i = int(l); i < int(r); ++i)
#define forn2(i,n) forn3 (i, 0, n)
#define forn(...) ARG4(__VA_ARGS__, forn3, forn2) (__VA_ARGS__)

#define ford3(i,l,r) for (int i = int(r) - 1; i >= int(l); --i)
#define ford2(i,n) ford3 (i, 0, n)
#define ford(...) ARG4(__VA_ARGS__, ford3, ford2) (__VA_ARGS__)

#define ve vector
#define pa pair
#define tu tuple
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fs first
#define sc second
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const ll mod = 1000000007;

const int N = 100000;
const int K = 2000;

struct Input {
	int n, m;
	int k;
	int x[K + 1], y[K + 1];
	
	bool read () {
		if (!(cin >> n >> m >> k)) {
			return 0;
		}
		forn (i, k) {
			scanf("%d%d", &x[i], &y[i]);
			--x[i];
			--y[i];
		}
		x[k] = n - 1;
		y[k] = m - 1;
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ll ans;
	
	void write () {
		cout << ans << endl;
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	ll pw (ll a, ll n) {
		ll res = 1;
		while (n) {
			if (n & 1) {
				res = res * a % mod;
			}
			a = a * a % mod;
			n >>= 1;
		}
		return res;
	}
	
	ll f[2 * N + 1];
	ll rf[2 * N + 1];
	
	ll c (int a, int b) {
		if (a < 0 || b < 0) {
			return 0;
		}
		return f[a + b] * rf[a] % mod * rf[b] % mod;
	}
	
	ll d[K + 1];
	
	void solve () {
		f[0] = 1;
		forn (i, 2 * N) {
			f[i + 1] = f[i] * (i + 1) % mod;
		}
		forn (i, 2 * N + 1) {
			rf[i] = pw(f[i], mod - 2);
		}
		{
			ve<pii> v(k + 1);
			forn (i, k + 1) {
				v[i] = mp(x[i], y[i]);
			}
			sort(all(v), [&] (pii a, pii b) {
				return a.fs + a.sc < b.fs + b.sc;
			});
			forn (i, k + 1) {
				tie(x[i], y[i]) = v[i];
			}
		}
		memset(d, 0, sizeof d);
		forn (i, k + 1) {
			d[i] = c(x[i], y[i]);
			forn (j, i) {
				d[i] = (d[i] + (mod - d[j]) * c(x[i] - x[j], y[i] - y[j]) % mod) % mod;
			}
		}
		debug(d, d + k + 1);
		ans = d[k];
	}
	
	void clear () {
		*this = Solution();
	}
};

Solution sol;

int main () {
	cout.setf(ios::showpoint | ios::fixed);
	cout.precision(20);
#ifdef SG
	freopen((problemname + ".in").c_str(), "r", stdin);
//	freopen((problemname + ".out").c_str(), "w", stdout);
	while (sol.read()) {
		sol.solve();
		sol.write();
		sol.clear();
	}
#else
	sol.read();
	sol.solve();
	sol.write();
#endif
	return 0;
}