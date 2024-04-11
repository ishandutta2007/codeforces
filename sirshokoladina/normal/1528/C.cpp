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
	vi e[N], f[N];
	
	bool read() {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, 1, n) {
			int x;
			scanf("%d", &x);
			--x;
			e[x].pb(i);
		}
		forn (i, 1, n) {
			int x;
			scanf("%d", &x);
			--x;
			f[x].pb(i);
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

	const int M = 2 * N;

	struct SumTree {
		int m;

		int sum[2 * M];

		void init(int n) {
			m = 1;
			while (m < n) {
				m *= 2;
			}
			forn (i, 2 * m) {
				sum[i] = 0;
			}
		}

		void add(int i, int val) {
			i += m;
			while (i > 0) {
				sum[i] += val;
				i /= 2;
			}
		}

		int get(int v, int lb, int rb, int l, int r) {
			if (rb <= l || r <= lb) {
				return 0;
			}
			if (l <= lb && rb <= r) {
				return sum[v];
			}
			return (
				get(2 * v, lb, (lb + rb) / 2, l, r) +
				get(2 * v + 1, (lb + rb) / 2, rb, l, r)
			);
		}

		int get(int l, int r) {
			return get(1, 0, m, l, r);
		}
	};

	struct AssignTree {
		int m;

		int upd[2 * M];

		void init(int n) {
			m = 1;
			while (m < n) {
				m *= 2;
			}
			forn (i, 2 * m) {
				upd[i] = -1;
			}
		}

		int get(int i) {
			int res = -1;
			i += m;
			while (i > 0) {
				if (upd[i] != -1) {
					res = upd[i];
				}
				i /= 2;
			}
			return res;
		}

		void set(int v, int lb, int rb, int l, int r, int val) {
			if (rb <= l || r <= lb) {
				return;
			}
			if (l <= lb && rb <= r) {
				upd[v] = val;
				return;
			}
			if (upd[v] != -1) {
				upd[2 * v] = upd[v];
				upd[2 * v + 1] = upd[v];
				upd[v] = -1;
			}
			set(2 * v, lb, (lb + rb) / 2, l, r, val);
			set(2 * v + 1, (lb + rb) / 2, rb, l, r, val);
		}

		void set(int l, int r, int val) {
			set(1, 0, m, l, r, val);
		}
	};
	
	struct Solution: Data {
		SumTree sum_tree;
		AssignTree assign_tree;

		int in[N], out[N];
		int counter;

		void dfs(int v, int pr) {
			in[v] = counter++;
			for (int to : f[v]) {
				if (to == pr) {
					continue;
				}
				dfs(to, v);
			}
			out[v] = counter;
		}

		int cur_sz;
		ve<pii> st;

		void add(int v) {
			debug(mt("add", v));
			sum_tree.add(in[v], 1);
			assign_tree.set(in[v], out[v], v);
			cur_sz++;
		}

		void del(int v) {
			debug(mt("del", v));
			sum_tree.add(in[v], -1);
			assign_tree.set(in[v], out[v], n);
			cur_sz--;
		}

		void try_add(int v) {
			int sm = sum_tree.get(in[v], out[v]);
			debug(sm);
			if (sm) {
				return;
			}
			int w = assign_tree.get(in[v]);
			debug(w);
			if (w != n) {
				st.pb(mp(w, 0));
				del(w);
			}
			st.pb(mp(v, 1));
			add(v);
		}

		void undo() {
			int v = st.back().fs;
			if (st.back().sc) {
				del(v);
			} else {
				add(v);
			}
			st.pop_back();
		}

		void rec(int v, int pr) {
			deepen();
			debug(mt("enter", v));
			int st_sz = sz(st);
			try_add(v);
			umx(ans, cur_sz);
			for (int to : e[v]) {
				if (to == pr) {
					continue;
				}
				rec(to, v);
			}
			while (sz(st) > st_sz) {
				undo();
			}
			debug(mt("exit", v));
		}
		
		void solve() {
			sum_tree.init(n);
			assign_tree.init(n);
			assign_tree.set(0, n, n);
			counter = 0;
			dfs(0, -1);
			debug(in, in + n);
			debug(out, out + n);
			ans = 0;
			cur_sz = 0;
			rec(0, -1);
		}
		
		void clear() {
			forn (i, n) {
				e[i].clear();
				f[i].clear();
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