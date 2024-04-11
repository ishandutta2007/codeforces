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

struct Input {
	int n;
	int a[N];
	
	bool read() {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			cin >> a[i];
			--a[i];
		}
		return 1;
	}

	void init(const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	bool can;
	int ans[N];
	
	void write() {
		if (!can) {
			puts("NO");
			return;
		}
		puts("YES");
		forn (i, n) {
			cout << ans[i] + 1 << ' ';
		}
		cout << endl;
	}
};


namespace Main {
	
	struct Solution: Data {
		vi e[N];
		bool u[N];

		vi p;

		void run(int v) {
			if (u[v]) {
				return;
			}
			u[v] = 1;
			u[n - 1 - v] = 1;
			int val = a[n - 1 - v];
			debug(mt(v, n - 1 - v, val));
			deepen();
			while (sz(e[val])) {
				int to = e[val].back();
				e[val].pop_back();
				run(to);
			}
			p.pb(n - 1 - v);
			if (v != n - 1 - v) {
				p.pb(v);
			}
		}

		int go[N];
		
		void solve() {
			forn (i, n) {
				e[a[i]].pb(i);
			}
			debug(a, a + n);
			debug(e, e + n);
			forn (i, n) {
				u[i] = 0;
			}
			ve<tu<int, int, int>> vs;
			forn (v, n / 2, n) {
				if (u[v]) {
					continue;
				}
				p = vi();
				run(v);
				reverse(all(p));
				if (sz(p) % 2 == 0) {
					rotate(p.begin(), p.begin() + 1, p.end());
				}
				debug(p);
				if (sz(p) == 1) {
					can = 0;
					return;
				}
				forn (i, sz(p) / 2) {
					if (a[p[2 * i]] != a[p[2 * i + 1]]) {
						can = 0;
						return;
					}
				}
				forn (i, sz(p)) {
					go[p[i]] = p[(i + 1) % sz(p)];
				}
				int v1 = p[0];
				int v2 = go[v1];
				int v3 = go[v2];
				vs.push_back(mt(v1, v2, v3));
			}

			forn (i, sz(vs)) {
				auto u = vs[i];
				auto v = vs[(i + 1) % sz(vs)];
				go[get<0>(u)] = get<1>(v);
				go[get<1>(u)] = get<2>(v);
				if (i == sz(vs) - 1 && sz(vs) % 2 == 0) {
					swap(go[get<0>(u)], go[get<1>(u)]);
				}
			}

			debug(go, go + n);
			can = 1;
			forn (i, n) {
				ans[go[i]] = i;
			}
		}
		
		void clear() {
			forn (i, n) {
				e[i] = vi();
			}
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