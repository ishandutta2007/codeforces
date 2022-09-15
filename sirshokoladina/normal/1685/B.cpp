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
	int a, b, ab, ba;
	string s;
	
	bool read() {
		return !!(cin >> a >> b >> ab >> ba >> s);
	}

	void init(const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	bool ans;

	void write() {
		puts(ans ? "YES" : "NO");
	}
};


namespace Main {
	
	struct Solution: Data {
		
		void solve() {
			int n = sz(s);
			int cnt_a = 0, cnt_b = 0;
			forn (i, n) {
				(s[i] == 'A' ? cnt_a : cnt_b)++;
			}
			debug(mt(a, b, ab, ba));
			debug(s);
			debug(mt(cnt_a, cnt_b));
			if (ab + ba + a != cnt_a && ab + ba + b != cnt_b) {
				ans = 0;
				return;
			}

			vi vab, vba, vxx;
			for (int l = 0; l < n; ) {
				int r = l + 1;
				while (r < n && s[r] != s[r - 1]) {
					r++;
				}
				int len = r - l;
				if (len % 2 == 1) {
					vxx.pb(len / 2);
				} else {
					(s[l] == 'A' ? vab : vba).pb(len / 2);
				}
				l = r;
			}
			debug(mt(vab, vba, vxx));
			sort(all(vab));
			sort(all(vba));
			int sum_xx = 0;
			int sum_ab = 0;
			int sum_ba = 0;
			for (int x : vxx) {
				sum_xx += x;
			}
			for (int x : vab) {
				sum_ab += x;
			}
			for (int x : vba) {
				sum_ba += x;
			}
			while (true) {
				debug(mt(sum_ab, sum_ba, sum_xx, vab, vba));
				if (max(0, ab - sum_ab) + max(0, ba - sum_ba) <= sum_xx) {
					ans = 1;
					return;
				}
				assert(ab > sum_ab || ba > sum_ba);
				if (ab >= sum_ab && ba >= sum_ba) {
					ans = 0;
					return;
				}
				if (ab < sum_ab) {
					assert(sz(vab) > 0);
					int x = vab.back();
					vab.pop_back();
					sum_ab -= x;
					sum_xx += x - 1;
				} else {
					assert(sz(vba) > 0);
					int x = vba.back();
					vba.pop_back();
					sum_ba -= x;
					sum_xx += x - 1;
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