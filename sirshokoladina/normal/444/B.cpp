#include <bits/stdc++.h>
using namespace std;

#ifdef SG
	#include <debug.h>
#else
	#define show(...)
	#define debug(...)
	#define deepen(...)
	#define timer(...)
#endif

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)
#define forv(i,v) for (auto i = v.begin(); i != v.end(); ++i)
#define forr(i,v) for (auto i = v.end(); i != v.begin() && (--i, 1); )
#define ve vector
#define pa pair
#define tu tuple
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fs first
#define sc second
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T> inline T abs (T x) {return x > T() ? x : -x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int N = 100000;

struct Input {
	int n;
	int a[N], b[N];
	
	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int d;
	ll x;

	ll getNextX() {
	    x = (x * 37 + 10007) % 1000000007;
	    return x;
	}
	void initAB() {
	    forn (i, n) {
	        a[i] = i + 1;
	    }
	    forn (i, n) {
	        swap(a[i], a[getNextX() % (i + 1)]);
	    }
	    forn (i, n) {
	        if (i < d)
	            b[i] = 1;
	        else
	            b[i] = 0;
	    }
	    forn (i, n) {
	        swap(b[i], b[getNextX() % (i + 1)]);
	    }
	}
	
	bool read () {
		if (!(cin >> n >> d >> x)) {
			return 0;
		}
		initAB();
		forn (i, n) {
			--a[i];
		}
		return 1;
	}

	int ans[N];
	
	void write () {
		forn (i, n) {
			printf("%d\n", ans[i] + 1);
		}
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	static const int L = (N + 63) / 64;
	
	struct mask {
		ull a[L];

		void put (int i) {
			a[i >> 6] |= 1ull << (i & 63);
		}

		bool get (int i) {
			return a[i >> 6] & (1ull << (i & 63));
		}
	};
	
	mask sh[64];
	mask u;
	
	int pos[N];

	void solve () {
		debug(a, a + n);
		debug(b, b + n);
		memset(sh, 0, sizeof sh);
		forn (i, 64) {
			forn (j, n - i) {
				if (b[j]) {
					sh[i].put(i + j);
				}
			}
		}
		memset(&u, 0, sizeof u);
		forn (i, n) {
			pos[a[i]] = i;
		}
		memset(ans, -1, sizeof ans);
		ford (i_, n) {
			int i = pos[i_];
			forn (j, L - (i >> 6)) {
				ull &x = sh[i & 63].a[j];
				ull &y = u.a[j + (i >> 6)];
				ull cur = x & ~y;
				if (cur) {
					forn (t, 64) {
						if (cur & (1ull << t)) {
							int to = (j + (i >> 6)) * 64 + t;
							if (to < n)
							ans[to] = i_;
						}
					}
					y |= x;
				}
			}
		}
		debug(u.a[0]);
	}
	
	void clear () {
		*this = Solution();
	}
};

Solution sol;

int main () {
	cout.setf(ios::showpoint | ios::fixed);
	cout.precision(20);
#ifdef SG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
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
	return 0;
}