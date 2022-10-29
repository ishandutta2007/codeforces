#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>
#include <stack>
#include <algorithm>
#include <iomanip>

using namespace std;

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i,l,r) for (int i = int(l); i <= int(r); i++)
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define mp make_pair
#define pb push_back
#define ft first
#define sc second
#define x first
#define y second

const ld EPS = 1e-9;
const int INF = int(1e9);
const li INF64 = li(1e18);

int n, d, h;

inline bool read() {
	cin >> n >> d >> h;
	return true;
}

void solve() {
	if (d == 1 && n > 2) {
		cout << -1 << endl;
		return;
	}
	if (2 * h < d) {
		cout << -1 << endl;
		return;
	}

	vector<pt> ans;

	int prev = 1;
	int ft = 2;
	int pre = -1;
	forn (i, h) {
		if (i + 1 == h)
			pre = prev;
		ans.pb(mp(prev, ft));
		prev = ft;
		ft++;
	}

	prev = 1;

	forn (i, d - h) {
		ans.pb(mp(prev, ft));
		prev = ft;
		ft++;
	}

	forn (i, n - 1 - d) {
		ans.pb(mp(pre, ft++));
	}

	if (sz(ans) > n - 1) {
		cout << -1 << endl;
		return;
	}

	forn (i, sz(ans))
		cout << ans[i].ft << ' ' << ans[i].sc << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
#endif

	cerr << setprecision(10) << fixed;
	cout << setprecision(15) << fixed;

	srand(time(NULL));

	assert(read());
	solve();

#ifdef _DEBUG
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}