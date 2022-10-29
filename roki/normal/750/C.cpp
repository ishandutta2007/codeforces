#include <bits/stdc++.h>

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

int n;
const int N = 200 * 1000 + 5;

int c[N], d[N];

inline bool read() {
	cin >> n;
	forn (i, n)	
		cin >> c[i] >> d[i];
	return true;
}
   
inline void solve() {   
	li l = -INF, r = INF64;
	forn (i, n) {
		if (d[i] == 1)
			l = max(l, 1900LL);
		else
			r = min(r, 1899LL);
	//	cerr << l << ' ' << r << endl;
		l += c[i], r += c[i];
	}	
	if (l <= r) {
		if (r > INF64 / 2)
			cout << "Infinity" << endl;
		else
			cout << r << endl;
	} else {
		cout << "Impossible" << endl;
	}
}

int main()	
{
#ifdef _DEBUG
	assert(freopen("input.txt", "r", stdin));
	assert(freopen("output.txt", "w", stdout));
#endif

	cout << setprecision(25) << fixed;
	cerr << setprecision(10) << fixed;

	srand(int(time(NULL)));

	assert(read());
	solve();

#ifdef _DEBUG
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}