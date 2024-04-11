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

int n, m, s, d;
const int N = 200 * 1000 + 5;
int a[N];

inline bool read() {
	if (scanf("%d%d%d%d", &n, &m, &s, &d) != 4)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	a[n++] = 2 * INF + 5;
	return true;
}

void solve() {
	
	sort(a, a + n);

	int x = 0;

	vector<pair<string, int> > ans;

	int f = 0;

	while (x < m) {

		if (a[f] > m) {
			ans.push_back(mp("RUN", m - x));
			break;
		}
		
		int len = a[f] - 1 - x;
		if (len < s) {
			puts("IMPOSSIBLE");
			return;
		}

		ans.push_back(mp("RUN", len));
		x += len;

		while (a[f + 1] - a[f] - 2 < s)
			f++;

		int jumplen = a[f++] + 1 - x;
		if (jumplen > d) {
			puts("IMPOSSIBLE");
			return;
		}
		ans.push_back(mp("JUMP", jumplen));
		x += jumplen;
	}
	forn(i, sz(ans))
		cout << ans[i].ft << ' ' << ans[i].sc << endl;
}

int main()
{
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