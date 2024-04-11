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

const int N = 1000;
const int M = 1000000;

struct Data {
	int n;
	int a[N][N];

	int m;
	pair<int, int> q[M];
	
	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			forn (j, n) {
				scanf("%d", &a[i][j]);
			}
		}
		cin >> m;
		forn (i, m) {
			scanf("%d", &q[i].fs);
			if (q[i].fs != 3) {
				scanf("%d", &q[i].sc);
				--q[i].sc;
			}
		}
		return 1;
	}

	vector<int> ans;
 
	void write () {
		forn (i, ans.size()) {
			printf("%d", ans[i]);
		}
		puts("");
	}
 
	virtual void solve () {}
 
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	void solve () {
		int w = 0;
		forn (i, n) {
			w ^= a[i][i];
		}
		forn (i, m) {
			if (q[i].fs == 3) {
				ans.pb(w);
			} else {
				w ^= 1;
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