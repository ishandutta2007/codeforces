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
	string s;
	
	bool read() {
		return !!getline(cin, s) && sz(s);
	}

	void init(const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	string ans;

	void write() {
		puts(ans.c_str());
	}

	bool check() {
		sort(all(s));
		sort(all(ans));
		return s == ans;
	}
};


namespace Main {
	
	struct Solution: Data {
		int cnt[256];
		
		void solve() {
			debug(s);
			memset(cnt, 0, sizeof cnt);
			int n = sz(s);
			for (int x : s) {
				cnt[x]++;
			}
			sort(all(s));
			string c = s;
			c.erase(unique(all(c)), c.end());
			debug(s);
			debug(c);
			if (sz(c) == 1) {
				ans = s;
				return;
			}
			for (char x : s) {
				if (cnt[x] == 1) {
					ans = "";
					ans += x;
					for (char y : s) {
						if (y != x) {
							ans += y;
						}
					}
					return;
				}
			}
			int k = cnt[c[0]];
			int l = cnt[c[1]];
			if (n >= 2 * k - 2) {
				ans = "";
				int i = k;
				ans += c[0];
				ans += c[0];
				forn (t, k - 2) {
					ans += s[i++];
					ans += c[0];
				}
				while (i < n) {
					ans += s[i++];
				}
				return;
			}
			if (sz(c) > 2) {
				ans = "";
				ans += c[0];
				ans += c[1];
				forn (t, k - 1) {
					ans += c[0];
				}
				ans += c[2];
				forn (t, l - 1) {
					ans += c[1];
				}
				forn (i, k + l + 1, n) {
					ans += s[i];
				}
				return;
			}
			ans = "";
			ans += c[0];
			forn (t, l) {
				ans += c[1];
			}
			forn (t, k - 1) {
				ans += c[0];
			}
			return;
		}
		
		void clear() {
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
	
	string s;
	int t;
	cin >> t;
	getline(cin, s);
	forn (i, t) {
		sol.read();
		sol.solve();
		sol.write();
		assert(sol.check());
		sol.clear();
	}
	
	return 0;
}