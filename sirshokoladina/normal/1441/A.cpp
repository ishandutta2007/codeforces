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

const int N = 200000;
const ll mod = 998244353;

struct Input {
	int n, k;
	int a[N], b[N];
	
	bool read() {
		if (!(cin >> n >> k)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d", &a[i]);
			--a[i];
		}
		forn (i, k) {
			scanf("%d", &b[i]);
			--b[i];
		}
		return 1;
	}

	void init(const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ll ans;
	
	void write() {
		cout << ans << endl;
	}
};


namespace Main {
	
	struct Solution: Data {
		int cnt[N];
		int pos[N];
		int pr[N], nx[N];

		void del(int i) {
			int _pr = pr[i];
			int _nx = nx[i];
			if (_pr >= 0 && _pr < n) {
				nx[_pr] = _nx;
			}
			if (_nx >= 0 && _nx < n) {
				pr[_nx] = _pr;
			}
		}
		
		void solve() {
			forn (i, n) {
				cnt[i] = 0;
				pos[a[i]] = i;
				pr[i] = i - 1;
				nx[i] = i + 1;
			}
			forn (i, k) {
				cnt[b[i]]++;
			}
			ans = 1;
			forn (i, k) {
				debug(i);
				debug(cnt, cnt + n);
				int j = pos[b[i]];
				int _pr = pr[j];
				int _nx = nx[j];
				debug(mt(j, _pr, _nx));
				int tot = 0;
				int some = 0;
				for (int cur : {_pr, _nx}) {
					if (cur >= 0 && cur < n && cnt[a[cur]] == 0) {
						tot++;
						some = cur;
					}
				}
				debug(mt(tot, some));
				ans = (ans * tot) % mod;
				if (tot == 0) {
					return;
				}
				del(some);
				--cnt[b[i]];
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