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

const int N = 300000;

struct Input {
	int n;
	string s[N];

	bool read() {
		if (!(cin >> n)) {
			return 0;
		}
		getline(cin, s[0]);
		forn (i, n) {
			getline(cin, s[i]);
		}
		return 1;
	}

	void init(const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int ans_l;
	string ans;
	
	void write() {
		cout << ans_l << endl;
		puts(ans.c_str());
	}
};


namespace Main {
	
	struct Solution: Data {
		int x[N], y[N];
		int ans_x, ans_y;

		bool check(int l) {
			int mnx = 0, mxx = N + l;
			int mny = 0, mxy = N + l;
			int mnd = -N - l, mxd = N + l;
			forn (i, n) {
				umx(mnx, x[i] - l);
				umn(mxx, x[i] + l);
				umx(mny, y[i] - l);
				umn(mxy, y[i] + l);
				umx(mnd, x[i] - y[i] - l);
				umn(mxd, x[i] - y[i] + l);
			}
			if (mxx == 0) {
				umx(mny, 1);
			}
			if (mxy == 0) {
				umx(mnx, 1);
			}
			if (mnx > mxx) {
				return 0;
			}
			if (mny > mxy) {
				return 0;
			}
			umx(mnd, mnx - mxy);
			umn(mxd, mxx - mny);
			if (mnd > mxd) {
				return 0;
			}
			if (mxx - mxy >= mnd) {
				ans_x = mxy + mnd;
				ans_y = mxy;
			} else {
				ans_x = mxx;
				ans_y = mxx - mnd;
			}
			return 1;
		}
		
		void solve() {
			forn (i, n) {
				x[i] = y[i] = 0;
				forn (j, sz(s[i])) {
					if (s[i][j] == 'B') {
						x[i]++;
					} else if (s[i][j] == 'N') {
						y[i]++;
					} else {
						assert(0);
					}
				}
			}
			debug(x, x + n);
			debug(y, y + n);
			ans_x = 1;
			ans_y = 1;
			int lb = 0, rb = N + 2;
			while (lb != rb) {
				int md = (lb + rb) / 2;
				if (check(md)) {
					rb = md;
				} else {
					lb = md + 1;
				}
			}
			debug(mt(ans_x, ans_y));
			ans_l = lb;
			ans = "";
			forn (i, ans_x) {
				ans += 'B';
			}
			forn (i, ans_y) {
				ans += 'N';
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