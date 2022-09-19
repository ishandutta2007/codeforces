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

const ll INF = 2e18l;

const int N = 100;
const int M = 20;

struct Data {
	int n, m;
	ll b;
	ll x[N], k[N];
	int s[N], num[N][M];

	bool read () {
		if (!(cin >> n >> m >> b)) {
			return 0;
		}
		forn (i, n) {
			cin >> x[i] >> k[i] >> s[i];
			forn (j, s[i]) {
				cin >> num[i][j];
				--num[i][j];
			}
		}
		return 1;
	}
	
	ll ans;

	void write () {
		cout << ((ans == INF) ? -1 : ans) << endl;
	}

	virtual void solve () {}

	void clear () {
		*this = Data();
	}
};

struct cmp {
	ll *k;
	cmp (ll *k_): k(k_) {}
	bool operator () (int i, int j) {
		return k[i] < k[j];
	}
};

struct Solution: Data {
	int p[N];
	ll d[1 << M];
	int msk[N];

	void solve () {
		ans = INF;
		forn (i, n) {
			msk[i] = 0;
			forn (j, s[i]) {
				msk[i] |= (1 << num[i][j]);
			}
		}
		forn (i, n) {
			p[i] = i;
		}
		sort(p, p + n, cmp(k));
		forn (i, 1 << m) {
			d[i] = INF;
		}
		d[0] = 0;
		forn (i, n) {
			ford (j, 1 << m) {
				d[j | msk[p[i]]] = min(d[j | msk[p[i]]], d[j] + x[p[i]]);
			}
			ans = min(ans, d[(1 << m) - 1] + b * k[p[i]]);
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
	while (sol.read()) {
		sol.solve();
		sol.write();
		sol.clear();
	}
	return 0;
}