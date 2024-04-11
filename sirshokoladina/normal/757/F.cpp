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
	int n, st;
	ve<pil> e[N];
	
	bool read () {
		int m;
		if (!(cin >> n >> m >> st)) {
			return 0;
		}
		--st;
		forn (i, m) {
			int x, y;
			ll z;
			scanf("%d%d%" SCNd64, &x, &y, &z);
			--x;
			--y;
			e[x].pb(mp(y, z));
			e[y].pb(mp(x, z));
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
};


namespace Main {
	const ll inf = 1000000000000000000ll;
	const int L = 20;
	
	struct Solution: Data {
		vi q;
		
		ll d[N];
		set<pa<ll, int>> h;
		
		vi f[N];
		
		int pr[N];
		int lvl[N];
		int ppp[N][L];
		
		int lca (int a, int b) {
			if (lvl[a] < lvl[b]) {
				swap(a, b);
			}
			
			forn (i, L) {
				if ((lvl[a] - lvl[b]) & (1 << i)) {
					a = ppp[a][i];
				}
			}
			
			if (a == b) {
				return a;
			}
			
			ford (i, L) {
				if (ppp[a][i] != ppp[b][i]) {
					a = ppp[a][i];
					b = ppp[b][i];
				}
			}
			return pr[a];
		}
		
		int cnt[N];
		
		void solve () {
			forn (i, n) {
				d[i] = inf;
			}
			d[st] = 0;
			forn (i, n) {
				h.insert(mp(d[i], i));
			}
			
			while (sz(h)) {
				int v = h.begin()->sc;
				debug(v);
				h.erase(h.begin());
				if (d[v] == inf) {
					break;
				}
				q.pb(v);
				for (const auto& p : e[v]) {
					if (d[v] + p.sc < d[p.fs]) {
						h.erase(mp(d[p.fs], p.fs));
						d[p.fs] = d[v] + p.sc;
						h.insert(mp(d[p.fs], p.fs));
					}
				}
			}
			debug(d, d + n);
			
			forn (i, n) {
				for (const auto& p : e[i]) {
					if (d[i] == d[p.fs] + p.sc) {
						f[i].pb(p.fs);
					}
				}
				debug(mt(i, f[i]));
			}
			
			pr[st] = st;
			lvl[st] = 0;
			ppp[st][0] = pr[st];
			forn (t, L - 1) {
				ppp[st][t + 1] = ppp[ppp[st][t]][t];
			}
			forn (i, 1, sz(q)) {
				pr[q[i]] = f[q[i]][0];
				forn (j, 1, sz(f[q[i]])) {
					pr[q[i]] = lca(pr[q[i]], f[q[i]][j]);
				}
				lvl[q[i]] = lvl[pr[q[i]]] + 1;
				ppp[q[i]][0] = pr[q[i]];
				forn (t, L - 1) {
					ppp[q[i]][t + 1] = ppp[ppp[q[i]][t]][t];
				}
				debug(mt(q[i], pr[q[i]], lvl[q[i]]));
			}
			
			memset(cnt, 0, sizeof cnt);
			
			ans = 0;
			ford (i, 1, sz(q)) {
				cnt[q[i]]++;
				umx(ans, cnt[q[i]]);
				cnt[pr[q[i]]] += cnt[q[i]];
			}
			
			debug(cnt, cnt + n);
			
//			ans += n - sz(q);
		}
		
		void clear () {
			*this = Solution();
		}
	};
}


Main::Solution sol;

int main () {
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