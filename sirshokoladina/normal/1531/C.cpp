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

const int N = 100;

struct Input {
	int n;
	
	bool read() {
		return !!(cin >> n);
	}

	void init(const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ve<string> ans;
	
	void write() {
		if (!sz(ans)) {
			puts("-1");
			return;
		}
		cout << sz(ans) << endl;
		for (const auto &s : ans) {
			puts(s.c_str());
		}
	}
};


namespace Main {
	
	struct Solution: Data {
		bool check(int m, int k) {
			if (n < k * k || n > 2 * m * k - k * k) {
				return 0;
			}
			if ((n - k * k) % 2) {
				return 0;
			}
			debug(mt(n, m, k));
			forn (i, m) {
				ans.pb(string(m, '.'));
			}
			forn (i, k) {
				forn (j, k) {
					ans[i][j] = 'o';
				}
			}
			int r = n - k * k;
			forn (i, k) {
				forn (j, k, m) {
					if (r > 0) {
						ans[i][j] = ans[j][i] = 'o';
						r -= 2;
					}
				}
			}
			assert(r == 0);
			reverse(all(ans));
			return 1;
		}
		
		void solve() {
			forn (m, n + 1) {
				forn (i, m + 1) {
					if (check(m, i)) {
						return;
					}
				}
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
			puts("");
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