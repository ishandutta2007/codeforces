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

const int N = 21;
int mod = 31607;

int pow(int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1) {
			(res *= a) %= mod;
		}
		(a *= a) %= mod;
		n >>= 1;
	}
	return res;
}

int inv(int a) {
	return pow(a, mod - 2);
}

struct Input {
	int n;
	int a[N][N];
	
	bool read() {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			forn (j, n) {
				int x;
				scanf("%d", &x);
				a[i][j] = x * inv(10000) % mod;
			}
		}
		return 1;
	}

	void init(const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int ans;
	
	void write() {
		cout << ans << endl;
	}
};


namespace Main {
	
	struct Solution: Data {
		int p[1 << N], q[1 << N];
		int tmp[1 << N];

		int calc() {
			forn (msk, 1 << n) {
				p[msk] = 1;
			}
			forn (j, n) {
				tmp[0] = 1;
				forn (i, n) {
					forn (msk, 1 << i) {
						tmp[msk + (1 << i)] = tmp[msk] * a[i][j] % mod;
					}
				}
				forn (msk, 1 << n) {
					(p[msk] *= mod + 1 - tmp[(1 << n) - 1 - msk]) %= mod;
				}
			}
			q[0] = 1;
			forn (i, n) {
				int mul = 1;
				forn (j, n) {
					(mul *= a[i][j]) %= mod;
				}
				forn (msk, 1 << i) {
					q[msk + (1 << i)] = q[msk] * mul % mod;
				}
			}
			forn (msk, 1 << n) {
				p[msk] = (mod + 1 - p[msk]) * q[msk] % mod;
			}
			forn (i, n) {
				forn (msk, 1 << n) {
					if (msk & (1 << i)) {
						(p[msk - (1 << i)] += mod - p[msk] % mod);
						(q[msk - (1 << i)] += mod - q[msk] % mod);
					}
				}
			}
			return (mod + 1 - q[0] + p[0]) % mod;
		}
		
		void solve() {
			Input back = *this;
			int res[4];
			int tot[4];
			forn (msk, 4) {
				int mul = 1;
				if (msk & 1) {
					forn (i, n) {
						(mul *= a[i][i]) %= mod;
						a[i][i] = 1;
					}
				}
				if (msk & 2) {
					forn (i, n) {
						(mul *= a[i][n - 1 - i]) %= mod;
						a[i][n - 1 - i] = 1;
					}
				}
				res[msk] = calc() * mul % mod;
				tot[msk] = mul;
				init(back);
			}
			forn (i, 2) {
				forn (msk, 4) {
					if (msk & (1 << i)) {
						(res[msk - (1 << i)] += mod - res[msk]) %= mod;
						(tot[msk - (1 << i)] += mod - tot[msk]) %= mod;
					}
				}
			}
			ans = (mod + 1 - tot[0] + res[0]) % mod;
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