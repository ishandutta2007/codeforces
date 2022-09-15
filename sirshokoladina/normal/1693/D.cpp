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

struct Input {
	int n;
	vi a;
	
	bool read() {
		if (!(cin >> n)) {
			return 0;
		}
		a.resize(n);
		forn (i, n) {
			cin >> a[i];
		}
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

	struct A {
		int n;
		vi pr_u, pr_d;
		ve<vi> pow_pr_u, pow_pr_d;
		vi pr_not_u, pr_not_d;
		vi pr_bad_u, pr_bad_d;

		A(const vi &a) {
			deepen(0);
			n = sz(a);
			debug(a);
			pr_u = calc_pr(a, true);
			pr_d = calc_pr(a, false);
			debug(pr_u);
			debug(pr_d);
			pr_not_u = calc_not_pr(pr_u);
			pr_not_d = calc_not_pr(pr_d);
			debug(pr_not_u);
			debug(pr_not_d);
			pow_pr_u = calc_pow(pr_u);
			pow_pr_d = calc_pow(pr_d);
			pr_bad_u = calc_pr_bad(pow_pr_u, pow_pr_d, pr_not_u);
			pr_bad_d = calc_pr_bad(pow_pr_d, pow_pr_u, pr_not_d);
			debug(pr_bad_u);
			debug(pr_bad_d);
		}

		ve<vi> calc_pow(const vi &v) {
			ve<vi> res(20, v);
			forn (t, sz(res) - 1) {
				forn (i, n) {
					if (res[t][i] == -1) {
						res[t + 1][i] = -1;
					} else {
						res[t + 1][i] = res[t][res[t][i]];
					}
				}
			}
			return res;
		}

		vi calc_pr(const vi &a, bool up) {
			vi res, q;
			forn (i, sz(a)) {
				while (sz(q) > 0 && (
					up ? (a[q.back()] <= a[i]) : (a[q.back()] >= a[i])
				)) {
					q.pop_back();
				}
				res.pb(sz(q) > 0 ? q.back() : -1);
				q.pb(i);
			}
			return res;
		}

		vi calc_not_pr(const vi &pr) {
			vi res;
			forn (i, n) {
				if (pr[i] == -1 || pr[i] != i - 1) {
					res.pb(i - 1);
				} else {
					res.pb(res.back());
				}
			}
			return res;
		}

		int calc_cnt_geq(const ve<vi> &pow_pr_a, int v, int bound) {
			int ans = 1;
			ford (i, sz(pow_pr_a)) {
				if (pow_pr_a[i][v] >= bound) {
					ans += (1 << i);
					v = pow_pr_a[i][v];
				}
			}
			return ans;
		}

		vi calc_pr_bad(const ve<vi> &pow_pr_a, const ve<vi> &pow_pr_b, const vi &pr_not_a) {
			vi res;
			forn (i, n) {
				if (pr_not_a[i] == -1) {
					res.pb(-1);
					continue;
				}
				int j = pr_not_a[i];
				int lb = -1; // bad
				int rb = j; // good
				while (rb - lb > 1) {
					int md = (lb + rb) / 2;
					if (calc_cnt_geq(pow_pr_a, i, md) + calc_cnt_geq(pow_pr_b, j, md) >= i - md + 1) {
						rb = md;
					} else {
						lb = md;
					}
				}
				res.pb(lb);
			}
			return res;
		}
	};

	vi rev(const vi &a) {
		vi res = a;
		reverse(all(res));
		return res;
	}

	vi ind_rev(const vi &a) {
		vi res = a;
		reverse(all(res));
		for (int &x : res) {
			x = sz(a) - 1 - x;
		}
		return res;
	}
	
	struct Solution: Data {
		
		void solve() {

			A pr(a);
			A nx(rev(a));

			vi pr_not_u = pr.pr_not_u;
			vi pr_not_d = pr.pr_not_d;
			vi pr_bad_u = pr.pr_bad_u;
			vi pr_bad_d = pr.pr_bad_d;
			vi nx_not_u = ind_rev(nx.pr_not_u);
			vi nx_not_d = ind_rev(nx.pr_not_d);
			vi nx_bad_u = ind_rev(nx.pr_bad_u);
			vi nx_bad_d = ind_rev(nx.pr_bad_d);

			debug(a);
			debug(pr_not_u);
			debug(pr_not_d);
			debug(pr_bad_u);
			debug(pr_bad_d);
			debug(nx_not_u);
			debug(nx_not_d);
			debug(nx_bad_u);
			debug(nx_bad_d);

			ve<pii> v;

			forn (i, n - 1) {
				int j = i + 1;
				for (bool i_up : {true, false}) {
					for (bool j_up : {true, false}) {
						int pr_not = i_up ? pr_not_u[i] : pr_not_d[i];
						int pr_bad = i_up ? pr_bad_u[i] : pr_bad_d[i];
						int nx_not = j_up ? nx_not_u[j] : nx_not_d[j];
						int nx_bad = j_up ? nx_bad_u[j] : nx_bad_d[j];
						debug(mt(i_up, j_up, pr_bad, pr_not, i, j, nx_not, nx_bad));
						if (j_up && !i_up) {
							if (a[i] >= a[j]) {
								continue;
							}
							if (pr_not != -1 && nx_not != n && a[pr_not] <= a[nx_not]) {
								v.pb(mp(pr_bad, nx_not));
								v.pb(mp(pr_not, nx_bad));
							} else {
								v.pb(mp(pr_bad, nx_bad));
							}
						} else if (!j_up && i_up) {
							if (a[i] <= a[j]) {
								continue;
							}
							if (pr_not != -1 && nx_not != n && a[pr_not] >= a[nx_not]) {
								v.pb(mp(pr_bad, nx_not));
								v.pb(mp(pr_not, nx_bad));
							} else {
								v.pb(mp(pr_bad, nx_bad));
							}
						} else if (i_up && j_up) {
							bool pr_ok = (pr_not == -1 || a[pr_not] < a[j]);
							bool nx_ok = (nx_not == n || a[nx_not] < a[i]);
							debug(mt(pr_ok, nx_ok))
							v.pb(mp(pr_ok ? pr_bad : pr_not, nx_ok ? nx_bad : nx_not));
						} else if (!i_up && !j_up) {
							bool pr_ok = (pr_not == -1 || a[pr_not] > a[j]);
							bool nx_ok = (nx_not == n || a[nx_not] > a[i]);
							v.pb(mp(pr_ok ? pr_bad : pr_not, nx_ok ? nx_bad : nx_not));
						} else {
							assert(false);
						}
						debug(v);
					}
				}
			}

			sort(all(v));
			debug(v);
			int j = 0;
			int r = -1;
			ans = 0;
			forn (i, n) {
				umx(r, i + 1);
				while (j < sz(v) && v[j].fs < i) {
					umx(r, v[j].sc);
					++j;
				}
				ans += r - i;
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