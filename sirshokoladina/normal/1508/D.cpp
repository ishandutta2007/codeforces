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

typedef pll pt;
#define x first
#define y second

pt operator-(const pt &a, const pt &b) {
	return pt(a.x - b.x, a.y - b.y);
}

ll operator%(const pt &a, const pt &b) {
	return a.x * b.y - a.y * b.x;
}

const int N = 2000;

struct Input {
	int n;
	pt a[N];
	int q[N];
	
	bool read() {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			scanf("%" SCNd64 "%" SCNd64 "%d", &a[i].x, &a[i].y, &q[i]);
			--q[i];
		}
		return 1;
	}

	void init(const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ve<pii> ans;
	
	void write() {
		cout << sz(ans) << endl;
		for (const pii &p : ans) {
			printf("%d %d\n", p.fs + 1, p.sc + 1);
		}
	}
};


namespace Main {
	
	struct Solution: Data {
		int col_cnt = 0;
		int col[N];
		bool u[N];

		void add(int i, int j) {
			ans.pb(mp(i, j));
			swap(q[i], q[j]);
		}
		
		void solve() {
			vi ord;
			forn (i, n) {
				if (q[i] != i) {
					ord.pb(i);
				}
			}
			if (!sz(ord)) {
				return;
			}
			sort(all(ord), [&](int i, int j) {
				return a[i] > a[j];
			});
			int mni = ord.back();
			debug(mni);
			ord.pop_back();
			pt o = a[mni];
			forn (i, n) {
				a[i] = a[i] - o;
			}
			sort(all(ord), [&](int i, int j) {
				return (a[i] % a[j]) > 0;
			});
			debug(ord);
			memset(col, -1, sizeof col);
			forn (i, n) {
				if (col[i] == -1) {
					int cur_col = col_cnt++;
					while (col[i] == -1) {
						col[i] = cur_col;
						i = q[i];
					}
				}
			}
			debug(col, col + n);
			memset(u, 0, sizeof u);
			u[col[ord[0]]] = 1;
			forn (i, sz(ord) - 1) {
				if (!u[col[ord[i + 1]]]) {
					u[col[ord[i + 1]]] = 1;
					add(ord[i], ord[i + 1]);
				}
			}
			debug(ans);
			debug(q, q + n);
			vi v;
			for (int i = q[mni]; i != mni; i = q[i]) {
				v.pb(i);
			}
			for (int i : v) {
				add(mni, i);
			}
			forn (i, n) {
				assert(q[i] == i);
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