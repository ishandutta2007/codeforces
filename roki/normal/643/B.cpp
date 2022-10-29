#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iomanip>

using namespace std;

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

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;
const ld PI = acosl(ld(-1));

int n, k;
int a, b, c, d;

inline bool read() {
	cin >> n >> k;
	cin >> a >> b >> c >> d;
	return true;
}

const int N = 1005;
bool used[N];

inline void solve() {
	if (k < n + 1 || n == 4) {
		cout << -1 << endl;
		return;
	}
	
	used[a] = used[b] = used[c] = used[d] = true;
	
	cout << a << ' ' << c << ' ';
	
	for (int i = 1; i <= n; ++i)
		if (!used[i])
			cout << i << ' ';
	
	cout << d << ' ' << b << endl;
	
	cout << c << ' ' << a << ' ';
	for (int i = 1; i <= n; ++i)
		if (!used[i])
			cout << i << ' ';
	
	cout << b << ' ' << d << endl;
	
}

int main()
{
#ifdef SU2_PROJ
	assert(freopen("input.txt", "r", stdin));
	assert(freopen("output.txt", "w", stdout));
#endif

	cout << setprecision(25) << fixed;
	cerr << setprecision(10) << fixed;

	srand(int(time(NULL)));

	assert(read());
	solve();

#ifdef SU2_PROJ
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}