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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)

#define fs first
#define sc second
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair

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

struct Data {
	int n, k;
	bool read () {
		return cin >> n >> k;
	}
	
	bool res;
	vector<pair<int, int> > ans;
	
	void write () {
		if (!res) {
			cout << -1 << endl;
			return;
		}
		cout << ans.size() << endl;
		forn (i, ans.size()) {
			printf("%d %d\n", ans[i].fs + 1, ans[i].sc + 1);
		}
	}

	virtual void solve () {}

	void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	void solve () {
		if (k * n > n * (n - 1) / 2) {
			res = 0;
			return;
		}
		res = 1;
		forn (i, k) {
			forn (j, n) {
				ans.pb(mp(j, (j + i + 1) % n));
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
//	freopen("output.txt", "w", stdout);
#endif
	while(sol.read()) {
		sol.solve();
		sol.write();
		sol.clear();
	}
	return 0;
}