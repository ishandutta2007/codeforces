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
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

struct Input {
	int n;
	ve< tu< int, int, int > > q;
	bool read () {
		if (scanf("%d", &n) != 1) {
			return 0;
		}	
		q.resize(4 * n);
		forn(i, 4 * n) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			--a, --b, --c;
			q[i] = mt(a, b, c);
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

const tu< int, int, int > t1 = mt(0, 1, 1), t2 = mt(1, 0, 0);
const ve< tu< int, int, int > > cq =
{ t1, t1, t1, t1, t2, t2, t2, t2 };

struct Data: Input {
	vi ans;
	vi cnt;
	void write () {
		cnt.assign(n, 4);
		for (int x : ans) {
			int a, b, c;
			tie(a, b, c) = q[x];
			assert(cnt[a] > 0);
			cnt[a]--;
			//debug(cnt[a]);
			assert(cnt[b] < 9);
			cnt[b]++;
			//debug(cnt[b]);
			assert(cnt[c] < 9);	
			cnt[c]++;
			//debug(cnt[c]);
		}
		debug(all(cnt));
		puts("YES");
		for (int x : ans) {
			printf("%d ", x + 1);
		}
		printf("\n");
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {	
	ve< map< int, int > > g;
	ve< vi > qid;
	vi cycle;
	vi used;
	vi start;
	void dec(int from, int to)
	{
		g[from][to]--;
		if (!g[from][to]) {
			g[from].erase(to);
		}	
	}
	void dfs(int x) {
		while (!g[x].empty()) {
			int to = g[x].begin()->fs;
			dec(x, to);
			dec(to, x);
			dfs(to);				
		}
		cycle.pb(x);			
	}
	void find_ans(int x) {
		if (qid[x].empty()) return;
		debug(mp(x, qid[x]));
		int cur_q = qid[x].back() - n;
		qid[x].pop_back();
		int b, c;
		tie(ignore, b, c) = q[cur_q];
		assert(start[cur_q] == b || start[cur_q] == c);
		if (start[cur_q] == c) swap(b, c);
		ans.pb(cur_q);
		find_ans(c);
	}

	void solve () {
		// assert(q != cq);	
		g.resize(5 * n);
		qid.resize(n);
		start.assign(4 * n, -1);
		forn(i, 4 * n) {
			int a, b, c;
			tie(a, b, c) = q[i];
			qid[a].pb(n + i);
			g[b][n + i]++;
			g[c][n + i]++;
			g[n + i][b]++;
			g[n + i][c]++;
		}
		used.assign(5 * n, 0);
		cycle.clear();
		forn(i, n) {
			if (!g[i].empty()) {
				dfs(i);
			}	
		}	
		debug(cycle);
		int prev = -1;
		for (int x : cycle) {
			if (x >= n) {
				assert(prev >= 0 && prev < n);
				start[x - n] = prev;
			}
			prev = x;		
		}
		forn(i, n) {
			while (!qid[i].empty()) {
				find_ans(i);
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