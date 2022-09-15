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

const int N = 100000;

struct Input {
	int n;
	int a[N];
	
	bool read() {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d", &a[i]);
			--a[i];
		}
		return 1;
	}

	void init(const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int ans;
	
	void write() {
		cout << ans << endl;
	}
};


namespace Main {
	
	struct Solution: Data {
		int cnt[N];
		int choose;
		
		void solve() {
			vi d;
			forn (i, n + 1) {
				if (i == 0 || i == n || a[i - 1] == a[i]) {
					d.pb(i);
				}
			}
			debug(a, a + n);
			debug(d);
			forn (i, n) {
				cnt[i] = 0;
			}
			forn (i, sz(d) - 1) {
				int l = d[i];
				int r = d[i + 1];
				if (a[l] == a[r - 1]) {
					cnt[a[l]]++;
				}
			}
			debug(cnt, cnt + n);
			choose = 0;
			forn (i, n) {
				if (cnt[i] > cnt[choose]) {
					choose = i;
				}
			}
			debug(choose);
			int balance = 0;
			forn (i, sz(d) - 1) {
				int l = d[i];
				int r = d[i + 1];
				for (int x : {l, r - 1}) {
					if (a[x] == choose) {
						balance++;
					} else {
						balance--;
					}
				}
			}
			debug(balance);
			ans = sz(d) - 2;
			if (balance <= 2) {
				return;
			}
			forn (i, sz(d) - 1) {
				int l = d[i];
				int r = d[i + 1];
				forn (j, l, r - 1) {
					if (a[j] != choose && a[j + 1] != choose) {
						debug(j);
						balance -= 2;
						ans++;
						if (balance <= 2) {
							return;
						}
					}
				}
			}
			ans = -1;
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