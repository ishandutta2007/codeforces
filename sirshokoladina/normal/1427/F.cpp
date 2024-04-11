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

const int N = 1200;

struct Input {
	int n;
	bool a[N];
	
	bool read() {
		if (!(cin >> n)) {
			return 0;
		}
		n *= 6;
		forn (i, n) {
			a[i] = 1;
		}
		forn (i, n / 2) {
			int x;
			scanf("%d", &x);
			--x;
			a[x] = 0;
		}
		return 1;
	}

	void init(const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ve<vi> ans;

	void write() {
		for (auto v : ans) {
			forn (i, sz(v)) {
				if (i) {
					printf(" ");
				}
				printf("%d", v[i] + 1);
			}
			puts("");
		}
	}
};


namespace Main {
	
	struct Solution: Data {
		pii b[N];

		void run(int who) {
			if (n == 0) {
				return;
			}
			debug(b, b + n);
			vi res;
			forn (t, 2) {
				ve<vi> q;
				forn (i, n) {
					if (!sz(q)) {
						q.pb(vi{i});
						continue;
					}
					int root_color = b[q.front()[0]].sc;
					int leaf_color = b[q.back()[0]].sc;
					int cur_color = b[i].sc;
					if (cur_color != leaf_color) {
						q.pb(vi{});
					}
					q.back().pb(i);
					if (sz(q.back()) == 3) {
						vi v = q.back();
						q.pop_back();
						if (
							!sz(res) &&
							v[2] == v[0] + 2 &&
							cur_color == who &&
							(t || root_color != who)
						) {
							res = v;
						}
					}
				}
				assert(sz(q) == 0);
			}
			assert(sz(res) == 3);
			ans.pb(vi{b[res[0]].fs, b[res[1]].fs, b[res[2]].fs});
			{
				int j = 0;
				forn (i, n) {
					if (!count(all(res), i)) {
						b[j++] = b[i];
					}
				}
				assert(j == n - 3);
				n = j;
			}
			run(!who);
		}
		
		void solve() {
			forn (i, n) {
				b[i] = mp(i, a[i]);
			}
			run(0);
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