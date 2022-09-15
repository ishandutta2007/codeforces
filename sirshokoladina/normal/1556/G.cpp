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

const int N = 500000;

struct Input {
	int k, n;
	bool t[N];
	ll l[N], r[N];
	
	bool read() {
		if (!(cin >> k >> n)) {
			return 0;
		}
		forn (i, n) {
			string s;
			cin >> s >> l[i] >> r[i];
			if (s == "ask") {
				t[i] = 0;
			} else if (s == "block") {
				t[i] = 1;
				r[i]++;
			} else {
				assert(0);
			}
		}
		return 1;
	}

	void init(const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	bool ans[N];

	void write() {
		forn (i, n) {
			if (t[i] == 0) {
				printf("%d\n", int(ans[i]));
			}
		}
	}
};


namespace Main {

	const int M = 4 * N + 10;
	
	struct Solution: Data {
		ll bounds[M + 1];
		int m;

		vi e[M];

		set<int> cur;
		vi rem[N + 1];

		bool have[M];

		int pr[M];

		int Pr(int i) {
			if (pr[i] == i) {
				return i;
			}
			return pr[i] = Pr(pr[i]);
		}

		int rnd = 0;

		void uni(int i, int j) {
			i = Pr(i);
			j = Pr(j);
			if (rnd ^= 1) {
				swap(i, j);
			}
			pr[i] = j;
		}

		void solve() {
			m = 0;
			bounds[m++] = 0;
			bounds[m++] = (1ll << k);
			forn (i, n) {
				if (t[i] == 0) {
					continue;
				}
				bounds[m++] = l[i];
				bounds[m++] = r[i];
			}
			sort(bounds, bounds + m);
			m = int(unique(bounds, bounds + m) - bounds);
			debug(bounds, bounds + m);
			ford (i, m - 1) {
				ll x = bounds[i] ^ (bounds[i + 1] - 1);
				int h = 0;
				while (1ll << (h + 1) <= x) {
					h++;
				}
				bounds[m++] = (bounds[i + 1] - 1) & ~((1ll << h) - 1);
			}
			sort(bounds, bounds + m);
			m = int(unique(bounds, bounds + m) - bounds);
			debug(bounds, bounds + m);

			m--;

			forn (i, m) {
				cur.insert(i);
			}

			forn (i, n) {
				if (t[i] == 0) {
					continue;
				}
				int li = int(lower_bound(bounds, bounds + m + 1, l[i]) - bounds);
				int ri = int(lower_bound(bounds, bounds + m + 1, r[i]) - bounds);
				auto it = cur.lower_bound(li);
				while (it != cur.end() && *it < ri) {
					rem[i].pb(*it);
					it = cur.erase(it);
				}
			}
			rem[n] = vi(all(cur));

			forn (i, n + 1) {
				debug(mt(i, l[i], r[i], rem[i]));
			}

			forn (h, k) {
				// deepen(0);
				int j = 0;
				forn (i, m) {
					j = max(0, j - 1);
					while (j < m && bounds[j + 1] <= bounds[i] + (1ll << h)) {
						j++;
					}
					while (j < m && bounds[j] < bounds[i + 1] + (1ll << h)) {
						ll cl = max<ll>(bounds[i] + (1ll << h), bounds[j]);
						ll cr = min<ll>(bounds[i + 1] + (1ll << h), bounds[j + 1]);
						ll x = cl ^ (cr - 1);
						debug(mt(i, j, bounds[i], bounds[i + 1], bounds[j], bounds[j + 1], h, 1ll << h, cl, cr));
						if (x >= (1ll << h) || (cl & (1ll << h))) {
							debug(mt(i, j, h));
							e[i].pb(j);
							e[j].pb(i);
						}
						j++;
					}
				}
			}

			debug(e, e + m);

			forn (i, m) {
				have[i] = 0;
				pr[i] = i;
			}

			ford (i, n) {
				debug(mt(i, t[i], l[i], r[i]));
				deepen();
				for (int v : rem[i + 1]) {
					debug(v);
					have[v] = 1;
					for (int to : e[v]) {
						if (have[to]) {
							debug(mt(v, to));
							uni(v, to);
						}
					}
				}
				if (t[i] == 1) {
					continue;
				}
				int li = int(upper_bound(bounds, bounds + m + 1, l[i]) - bounds) - 1;
				int ri = int(upper_bound(bounds, bounds + m + 1, r[i]) - bounds) - 1;
				debug(mt(i, li, ri));
				ans[i] = (Pr(li) == Pr(ri));
			}
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