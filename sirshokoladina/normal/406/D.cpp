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

typedef pair<ll, ll> point;
#define x first
#define y second

point operator + (const point &a, const point &b) {
	return mp(a.x + b.x, a.y + b.y);
}

point operator - (const point &a, const point &b) {
	return mp(a.x - b.x, a.y - b.y);
}

ll operator * (const point &a, const point &b) {
	return a.x * b.x + a.y * b.y;
}

ll operator ^ (const point &a, const point &b) {
	return a.x * b.y - a.y * b.x;
}

const int N = 100000;
const int M = 100000;

struct Data {
	int n;
	point a[N];

	int m;
	pair<int, int> r[M];

	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			cin >> a[i].x >> a[i].y;
		}
		cin >> m;
		forn (i, m) {
			scanf("%d%d", &r[i].fs, &r[i].sc);
			--r[i].fs;
			--r[i].sc;
		}
		return 1;
	}

	int ans[M];
 
	void write () {
		forn (i, m) {
			if (i) {
				printf(" ");
			}
			printf("%d", ans[i] + 1);
		}
		puts("");
	}
 
	virtual void solve () {}
 
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	static const int D = 20;

	int p[N][D];
	int l[N];

	int lca (int x, int y) {
		if (l[x] < l[y]) {
			swap(x, y);
		}
		int k = l[x] - l[y];
		ford (i, D) {
			if (k & (1 << i)) {
				x = p[x][i];
			}
		}
		if (x == y) {
			return x;
		}
		ford (i, D) {
			if (p[x][i] != p[y][i]) {
				x = p[x][i];
				y = p[y][i];
			}
		}
		return p[x][0];
	}

	void solve () {
		vector<int> q;
		ford (i, n) {
			while (q.size() > 1 && ((a[q[q.size() - 1]] - a[i]) ^ (a[q[q.size() - 2]] - a[i])) > 0) {
				q.pop_back();
			}
			p[i][0] = q.size() ? q.back() : 0;
			l[i] = q.size() ? l[q.back()] + 1 : 0;
			q.pb(i);
			forn (j, D - 1) {
				p[i][j + 1] = p[p[i][j]][j];
			}
		}
		forn (i, m) {
			ans[i] = lca(r[i].fs, r[i].sc);
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