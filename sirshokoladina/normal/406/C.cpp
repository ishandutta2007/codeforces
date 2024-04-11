#include <iostream>
#include <iomanip>

#include <vector>
#include <string>
#include <deque>
#include <queue>
#include <set>
#include <map>

#include <algorithm>

#include <cstdio>
#include <cstdlib>
#include <complex>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)

#define mp make_pair
#define pb push_back
#define fs first
#define sc second
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#ifdef SG
	#define debug(x) cerr << #x << ": " << (x) << endl
#else
	#define debug(x)
#endif

template <typename T>
ostream & operator << (ostream & out, vector<T> const & a) {
	out << "[";
	for (int i = 0; i < sz(a); ++i) {
		if (i != 0) {
			out << ", ";
		}
		out << a[i];
	}
	out << "]";
	return out;
}

template <typename T1, typename T2>
ostream & operator << (ostream & out, pair<T1, T2> const & p) {
	out << "(" << p.fs << ", " << p.sc << ")";
	return out;
}

const int N = 100000;

struct Data {
	int n, m;
	vector<int> e[N];

	bool read () {
		if (!(cin >> n >> m)) {
			return 0;
		}
		forn (i, m) {
			int x, y;
			scanf("%d%d", &x, &y);
			--x;
			--y;
			e[x].pb(y);
			e[y].pb(x);
		}
		return 1;
	}

	bool res;
	vector<pair<pair<int, int>, int> > ans;
 
	void write () {
		if (!res) {
			puts("No solution");
			return;
		}
		forn (i, ans.size()) {
			printf("%d %d %d\n", ans[i].fs.fs + 1, ans[i].fs.sc + 1, ans[i].sc + 1);
		}
	}
 
	virtual void solve () {}
 
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	bool u[N];
	set<pair<int, int> > st;

	bool dfs (int v, int pr) {
		u[v] = 1;
		vector<int> q;
		forn (i, e[v].size()) {
			int to = e[v][i];
			if (to == pr) {
				continue;
			}
			if (u[to] || dfs(to, v)) {
				pair<int, int> id = mp(min(v, to), max(v, to));
				if (!st.count(id)) {
					q.pb(to);
					st.insert(id);
				}
			}
		}
		q.pb(pr);
		debug(mp(v, q));
		forn (i, q.size() >> 1) {
			ans.pb(mp(mp(q[2 * i], v), q[2 * i + 1]));
		}
		return q.size() & 1;
	}

	void solve () {
		res = 1;
		memset(u, 0, sizeof u);
		forn (i, n) {
			if (!u[i]) {
				if (!dfs(i, -1)) {
					res = 0;
					return;
				}
			}
		}
	}

	Solution (Data d = Data()): Data(d) {
	}

	void clear () {
		*this = Solution();
	}
};

Solution sol;

int main () {
#ifdef SG
	freopen("input.txt", "r", stdin);
//	freopen("", "w", stdout);
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