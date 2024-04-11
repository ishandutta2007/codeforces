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

typedef pa<ui, ui> puu;

const int N = 100000;
const int M = 30;

struct Input {
	int n;
	puu st[N], fn[N];
	
	bool read() {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			scanf("%u%u%u%u", &st[i].fs, &st[i].sc, &fn[i].fs, &fn[i].sc);
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
	const int K = 4 * N;

	inline int get_last_one(ui x) {
		int res = -1;
		ford (i, 5) {
			if (x & -(1u << (res + (1 << i)))) {
				res += 1 << i;
			}
		}
		return res;
	}

	inline puu cut(puu a, int d) {
		return puu(a.fs & -(1u << (d + 1)), a.sc & -(1u << (d + 1)));
	}

	inline puu common(puu a, puu b) {
		int d = max(get_last_one(a.fs ^ b.fs), get_last_one(a.sc ^ b.sc));
		if (d == -1) {
			return a;
		}

		if ((a.fs & (1u << d)) && (b.sc & (1u << d))) {
			return cut(a, d);
		}
		if ((a.sc & (1u << d)) && (b.fs & (1u << d))) {
			return cut(a, d);
		}

		if (a.fs & (1 << d)) {
			return cut(b, get_last_one(b.sc & ((1u << d) - 1)));
		}
		if (a.sc & (1 << d)) {
			return cut(b, get_last_one(b.fs & ((1u << d) - 1)));
		}
		if (b.fs & (1 << d)) {
			return cut(a, get_last_one(a.sc & ((1u << d) - 1)));
		}
		if (b.sc & (1 << d)) {
			return cut(a, get_last_one(a.fs & ((1u << d) - 1)));
		}
		assert(0);
	}

	inline ull ord(puu a) {
		ull res = 0;
		ford (i, 30) {
			if (!a.sc) {
				return res + a.fs;
			}
			if (a.fs & (1u << i)) {
				a.fs -= 1u << i;
				res += 1u << i;
				continue;
			}
			if (a.sc & (1u << i)) {
				a.sc -= 1u << i;
				res += 1ull << (i + i + 1);
				continue;
			}
			res += 1ull << (i + i);
		}
		return res;
	}
	
	struct Solution: Data {
		int v_cnt;
		puu a[K];
		map<puu, int> num;
		int pr[K];
		int lvl[K];
		int inc[K], dec[K];

		pa<ull, puu> tmp[K];

		void sort_unique() {
			forn (i, v_cnt) {
				tmp[i] = mp(ord(a[i]), a[i]);
			}
			debug(tmp, tmp + v_cnt);
			sort(tmp, tmp + v_cnt);
			v_cnt = unique(tmp, tmp + v_cnt) - tmp;
			forn (i, v_cnt) {
				a[i] = tmp[i].sc;
			}
		}

		set<int> bounds;

		void flip(int x) {
			if (bounds.count(x)) {
				bounds.erase(x);
			} else {
				bounds.insert(x);
			}
		}
		
		void solve() {
			forn (i, n) {
				a[v_cnt++] = st[i];
				a[v_cnt++] = fn[i];
			}
			debug(a, a + v_cnt);
			sort_unique();
			debug(a, a + v_cnt);
			ford (i, v_cnt - 1) {
				a[v_cnt++] = common(a[i], a[i + 1]);
			}
			debug(a, a + v_cnt);
			sort_unique();
			debug(a, a + v_cnt);
			forn (i, v_cnt) {
				num[a[i]] = i;
				lvl[i] = a[i].fs + a[i].sc;
			}

			{
				vi q;
				q.pb(0);
				pr[0] = -1;
				forn (i, 1, v_cnt) {
					while (common(a[q.back()], a[i]) != a[q.back()]) {
						q.pop_back();
						assert(sz(q));
					}
					pr[i] = q.back();
					q.pb(i);
				}
			}

			memset(inc, 0, sizeof inc);
			memset(dec, 0, sizeof dec);
			forn (i, n) {
				inc[num[st[i]]]++;
				inc[num[fn[i]]]++;
				dec[num[common(st[i], fn[i])]] += 2;
			}

			debug(a, a + v_cnt);
			debug(pr, pr + v_cnt);
			debug(inc, inc + v_cnt);
			debug(dec, dec + v_cnt);

			ford (i, v_cnt) {
				if (inc[i]) {
					flip(lvl[i]);
					flip(lvl[i] + 1);
				}
				inc[i] -= dec[i];
				if (inc[i]) {
					assert(i);
					flip(lvl[pr[i]] + 1);
					flip(lvl[i]);
					inc[pr[i]] += inc[i];
				}
			}

			bounds.erase(0);
			ans = sz(bounds);
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