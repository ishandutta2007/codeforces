#include <bits/stdc++.h>
using namespace std;

#ifdef SG
	#include <debug.h>
#else
	template<typename T> struct outputer;
	struct outputable {};
	#define PRINT(...)
	#define OUTPUT(...)
	#define show(...)
	#define debug(...)
	#define deepen(...)
	#define timer(...)
	#define fbegin(...)
	#define fend
	#define pbegin(...)
	#define pend
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
#define pb emplace_back
#define fs first
#define sc second
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())

typedef long double ld;
typedef int64_t ll;
typedef uint64_t ull;
typedef uint32_t ui;
typedef uint16_t us;
typedef uint8_t uc;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int N = 200000;
const ll mod = 998244353;

struct Input {
	int n_cnt, q_cnt;
	string s;
	
	bool read() {
		if (!(cin >> n_cnt >> q_cnt)) {
			return 0;
		}
		getline(cin, s);
		getline(cin, s);
		return 1;
	}

	void init(const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ll ans;

	void write() {
		cout << ans << endl;
	}
};


namespace Main {

	static const int L = 18;
	static const int M = 1 << L;

	ll pw(ll x, ll n) {
		ll res = 1;
		while (n) {
			if (n & 1) {
				res = (res * x) % mod;
			}
			x = (x * x) % mod;
			n >>= 1;
		}
		return res;
	}
	
	struct Solution: Data {
		ll rt[L + 1];
		
		void precalc() {
			rt[L] = 1;
			while (pw(rt[L], M) != 1 || pw(rt[L], M / 2) == 1) {
				++rt[L];
			}
			ford (i, L) {
				rt[i] = rt[i + 1] * rt[i + 1] % mod;
			}
		}
		
		void butterfly(ll *a, int n) {
			for (int i = 1, j = 0; i < n; ++i) {
				int k = n >> 1;
				while (j >= k) {
					j -= k;
					k >>= 1;
				}
				j += k;
				if (i < j) {
					swap(a[i], a[j]);
				}
			}
		}
		
		void fft(ll *a, int n) {
			butterfly(a, n);
			for (int m = 1, t = 0; m < n; m <<= 1) {
				ll r = rt[++t];
				for (int k = 0; k < n; k += m << 1) {
					ll w = 1;
					for (int j = k; j < k + m; j++) {
						ll u = a[j], v = a[j + m] * w % mod;
						a[j] = (u + v) % mod;
						a[j + m] = (u - v + mod) % mod;
						w = w * r % mod;
					}
				}
			}
		}
		
		void inv(ll *a, int n) {
			forn (i, n) {
				a[i] = a[i] * (mod - (mod - 1) / n) % mod;
			}
			reverse(a + 1, a + n);
		}

		ll buf1[M], buf2[M];

		ve<ll> multiply(const ve<ll> &v1, const ve<ll> &v2) {
			int m = 1;
			while (m < sz(v1) + sz(v2) - 1) {
				m *= 2;
			}
			forn (i, m) {
				buf1[i] = buf2[i] = 0;
			}
			forn (i, sz(v1)) {
				buf1[i] = v1[i];
			}
			forn (i, sz(v2)) {
				buf2[i] = v2[i];
			}
			debug(ve<ll>(buf1, buf1 + m));
			debug(ve<ll>(buf2, buf2 + m));
			fft(buf1, m);
			fft(buf2, m);
			forn (i, m) {
				buf1[i] = (buf1[i] * buf2[i]) % mod;
			}
			fft(buf1, m);
			inv(buf1, m);
			debug(ve<ll>(buf1, buf1 + m));
			return ve<ll>(buf1, buf1 + (sz(v1) + sz(v2) - 1));
		}

		ve<ll> rec(int l, int r) {
			if (r - l == 1) {
				if (s[l] == 'w') {
					return {1, 0};
				}
				if (s[l] == 'b') {
					return {0, 1};
				}
				if (s[l] == '?') {
					return {1, 1};
				}
				assert(0);
			}
			int md = (l + r) / 2;
			ve<ll> v1 = rec(l, md);
			ve<ll> v2 = rec(md, r);
			if ((md - l) % 2 == 1) {
				reverse(all(v2));
			}
			return multiply(v1, v2);
		}
		
		void solve() {
			precalc();
			int n = n_cnt;
			ve<ll> res = rec(0, n);
			assert(sz(res) == n + 1);
			ll ans_p = 0, ans_q = 0;
			forn (i, n + 1) {
				if ((2 * i - n) % 4) {
					continue;
				}
				ans_p = (ans_p + abs(2 * i - n) / 4 * res[i]) % mod;
				ans_q = (ans_q + res[i]) % mod;
			}
			ans = ans_p * pw(ans_q, mod - 2) % mod;
		}
		
		void clear() {
			*this = Solution();
		}
	};
}


Main::Solution sol;

int main() {
	cout.setf(ios::showpoint | ios::fixed);
	cout.precision(20);

	#ifdef SG
		freopen((problemname + ".in").c_str(), "r", stdin);
//		freopen((problemname + ".out").c_str(), "w", stdout);
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
	
	/*
	int t;
	cin >> t;
	forn (i, t) {
		sol.read();
		sol.solve();
		sol.write();
		sol.clear();
	}
	*/
	
	return 0;
}