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

const int N = 100;

struct Data {
	int n, m;

	bool read () {
		return cin >> n >> m;
	}
	
	int ans[N][N];

	void write () {
		forn (i, n) {
			forn (j, m) {
				if (j) {
					cout << ' ';
				}
				cout << ans[i][j];
			}
			cout << endl;
		}
	}

	virtual void solve () {}

	void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	vector<int> make (int k) {
		vector<int> ans;
		if (k == 1) {
			ans.pb(1);
			return ans;
		}
		if (k == 2) {
			ans.pb(3);
			ans.pb(4);
			return ans;
		}
		if (k & 1) {
			forn (i, k - 2) {
				ans.pb(1);
			}
			ans.pb(2);
			ans.pb((k + 1) / 2);
		} else {
			forn (i, k - 1) {
				ans.pb(1);
			}
			ans.pb((k - 2) / 2);
		}
		return ans;
	}

	void solve () {
		vector<int> v1 = make(n);
		vector<int> v2 = make(m);
		forn (i, n) {
			forn (j, m) {
				ans[i][j] = v1[i] * v2[j];
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