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
	int a[N];
	
	bool read() {
		if (scanf("%d", &n) != 1) {
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
	bool ans[N + 1];
	
	void write() {
		forn (i, n) {
			printf("%d", int(ans[i + 1]));
		}
		puts("");
	}
};


namespace Main {
	
	struct Solution: Data {
		int cnt[N];
		
		void solve() {
			forn (i, n) {
				cnt[i] = 0;
			}
			forn (i, n) {
				cnt[a[i]]++;
			}
			int l = 0, r = n;
			int k = 0;
			while (l < r) {
				if (cnt[k] == 1) {
					if (a[l] == k) {
						++l;
					} else if (a[r - 1] == k) {
						--r;
					} else {
						break;
					}
					++k;
				} else {
					break;
				}
			}
			if (l < r && cnt[k] > 0) {
				k++;
			}
			bool ok1 = true;
			forn (i, n) {
				ok1 &= (cnt[i] == 1);
			}
			forn (i, 1, n + 1) {
				if (i == 1) {
					ans[i] = ok1;
				} else {
					ans[i] = (n - i < k);
				}
			}
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