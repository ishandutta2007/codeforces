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
#define pb push_back
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

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int N = 1000;

struct Input {
	int n;
	int a[N];

	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d", &a[i]);
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int ans;
	
	void write () {
		cout << ans << endl;
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	static const int M = 30000000;
	int p[M], cnt[M];
	
	ui ma, mb;
	
	int h (int n) {
		return ((ui(n) * ma) ^ mb) % M;
	}
	
	int calc (int i, int j) {
		int k = i + j;
		if (p[h(k)] == k && cnt[h(k)]) {
			cnt[h(k)]--;
			int ret = calc(j, k);
			cnt[h(k)]++;
			return ret + 1;
		}
		return 2;
	}
	
	void solve () {
		sort(a, a + n);
		for (; 1;) {
			ma = ui(rand()) * 1000u + ui(rand());
			mb = ui(rand()) * 1000u + ui(rand());
			bool ok = 1;
			forn (i, n - 1) {
				if (a[i] != a[i + 1] && h(a[i]) == h(a[i + 1])) {
					ok = 0;
				}
			}
			if (ok) {
				break;
			}
		}
		memset(cnt, 0, sizeof cnt);
		forn (i, n) {
			p[h(a[i])] = a[i];
			cnt[h(a[i])]++;
		}
		ans = 0;
		forn (i, n) {
			ans += (a[i] == 0);
		}
		forn (i, n) {
			forn (j, n) {
				if (i != j && (a[i] || a[j])) {
					cnt[h(a[i])]--;
					cnt[h(a[j])]--;
					debug(mt(a[i], a[j], calc(a[i], a[j])));
					umx(ans, calc(a[i], a[j]));
					cnt[h(a[i])]++;
					cnt[h(a[j])]++;
				}
			}
		}
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
	freopen((problemname + ".in").c_str(), "r", stdin);
//	freopen((problemname + ".out").c_str(), "w", stdout);
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