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
	string s;

	bool read() {
		if (!(cin >> n >> s)) {
			return 0;
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
		for (pii x : ans) {
			cout << x.fs + 1 << ' ' << x.sc << endl;
		}
	}
};


namespace Main {
	
	struct Solution: Data {
		vi bal;
		
		void solve() {
			debug(s);

			bal.pb(0);
			forn (i, sz(s)) {
				if (s[i] == '(') {
					bal.pb(bal.back() + 1);
				} else {
					bal.pb(bal.back() - 1);
				}
			}
			debug(bal);

			int fs_neg = sz(bal) + 100;
			int lt_neg = -1;
			forn (i, sz(bal)) {
				if (bal[i] < 0) {
					umn(fs_neg, i);
					umx(lt_neg, i);
				}
			}
			debug(mt(fs_neg, lt_neg));

			if (lt_neg == -1) {
				return;
			}

			int mx_l_pos = 0;
			int mx_l = bal[0];
			forn (i, 0, fs_neg + 1) {
				if (umx(mx_l, bal[i])) {
					mx_l_pos = i;
				}
			}
			debug(mt(mx_l_pos, mx_l));

			int mx_r_pos = sz(bal) - 1;
			int mx_r = bal[sz(bal) - 1];
			forn (i, lt_neg, sz(bal)) {
				if (umx(mx_r, bal[i])) {
					mx_r_pos = i;
				}
			}
			debug(mt(mx_r_pos, mx_r));

			int mx_c_pos = fs_neg;
			int mx_c = bal[fs_neg];
			forn (i, fs_neg, lt_neg + 1) {
				if (umx(mx_c, bal[i])) {
					mx_c_pos = i;
				}
			}
			debug(mt(mx_c_pos, mx_c));

			debug(mx_l + mx_r - mx_c);
			if (mx_l + mx_r - mx_c >= 0) {
				ans.pb(mp(mx_l_pos, mx_r_pos));
				return;
			}

			int mx_pos = 0;
			int mx = bal[0];
			forn (i, sz(bal)) {
				if (umx(mx, bal[i])) {
					mx_pos = i;
				}
			}
			debug(mt(mx_pos, mx));

			ans.pb(mp(0, mx_pos));
			ans.pb(mp(mx_pos, sz(bal) - 1));
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
	#endif
	
	int t;
	cin >> t;
	forn (i, t) {
		sol.read();
		sol.solve();
		sol.write();
		sol.clear();
	}
	
	return 0;
}