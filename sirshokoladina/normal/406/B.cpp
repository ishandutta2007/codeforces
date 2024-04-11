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

const int S = 1000000;
const int N = 500000;

struct Data {
	int n;
	int a[N];
	
	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d", &a[i]);
			--a[i];
		}
		return 1;
	}

	vector<int> ans;
 
	void write () {
		cout << ans.size() << endl;
		forn (i, ans.size()) {
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
	bool u[S];

	void solve () {
		memset(u, 0, sizeof u);
		forn (i, n) {
			u[a[i]] = 1;
		}
		int k = 0;
		forn (i, S / 2) {
			if (u[i] && u[S - 1 - i]) {
				++k;
			}
		}
		forn (i, S / 2) {
			if (u[i] ^ u[S - 1 - i]) {
				if (u[i]) {
					ans.pb(S - 1 - i);
				} else {
					ans.pb(i);
				}
			}
			if (!u[i] && !u[S - 1 - i] && k) {
				ans.pb(i);
				ans.pb(S - 1 - i);
				--k;
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