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

const int N = 1500;
const ll mod = 998244353;

struct Input {
	int n;
	int a[N][N];
	
	bool read() {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			forn (j, n) {
				scanf("%d", &a[i][j]);
			}
		}
		return 1;
	}

	void init(const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ve<ll> ans;

	void write() {
		forn (i, 1, sz(ans)) {
			if (i > 1) {
				printf(" ");
			}
			printf("%" PRId64, ans[i]);
		}
		puts("");
	}
};


namespace Main {
	
	struct Solution: Data {
		ull rnd[N];
		int ord[N][N];
		ull hash[N][N];
		bool good[N][N];
		map<ull, ve<ull>> e;

		ull rand_ull() {
			ull res = 0;
			forn (i, 10) {
				res *= 1000000009;
				res += ull(rand());
			}
			return res;
		}

		ve<ll> mult(const ve<ll> &lhs, const ve<ll> &rhs) {
			ve<ll> res(sz(lhs) + sz(rhs) - 1, 0);
			forn (i, sz(lhs)) {
				forn (j, sz(rhs)) {
					res[i + j] = (res[i + j] + lhs[i] * rhs[j]) % mod;
				}
			}
			return res;
		}

		ve<ll> calc(ull v) {
			deepen();
			debug(v);
			ve<ll> res = {1};
			sort(all(e[v]));
			e[v].erase(unique(all(e[v])), e[v].end());
			debug(e[v]);
			if (sz(e[v]) == 0) {
				return {0, 1};
			}
			for (ull to : e[v]) {
				res = mult(res, calc(to));
			}
			res[1] = 1;
			return res;
		}
		
		void solve() {
			forn (i, n) {
				rnd[i] = rand_ull();
			}
			forn (i, n) {
				forn (j, n) {
					ord[i][j] = j;
				}
				sort(ord[i], ord[i] + n, [&](int x, int y) {
					return a[i][x] < a[i][y];
				});
				ull sum = 0;
				forn (j, n) {
					sum += rnd[ord[i][j]];
					hash[i][j] = sum;
				}
			}
			forn (i, n) {
				debug(ord[i], ord[i] + n);
			}
			forn (j, n) {
				unordered_map<ull, int> cnt;
				unordered_map<ull, int> lmx;
				unordered_map<ull, int> rmn;
				const int inf = N * N;
				forn (i, n) {
					cnt[hash[i][j]]++;
					umx(lmx[hash[i][j]], a[i][ord[i][j]]);
					if (j + 1 < n) {
						umn(rmn[hash[i][j]], a[i][ord[i][j + 1]] - inf);
					}
				}
				forn (i, n) {
					good[i][j] = (
						cnt[hash[i][j]] == j + 1 &&
						lmx[hash[i][j]] < rmn[hash[i][j]] + inf
					);
				}
			}
			forn (i, n) {
				debug(good[i], good[i] + n);
			}
			ull root = accumulate(rnd, rnd + n, 0ull);
			forn (i, n) {
				assert(good[i][0]);
				assert(good[i][n - 1]);
				assert(hash[i][n - 1] == root);
				ull lst = 0;
				forn (j, n) {
					if (good[i][j]) {
						ull cur = hash[i][j];
						if (j) {
							e[cur].pb(lst);
						}
						lst = cur;
					}
				}
			}
			debug(root);
			debug(e);
			ans = calc(root);
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