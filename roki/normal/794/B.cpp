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
ld h;

inline bool read() {
	cin >> n >> h;
	return true;
}
   
inline void solve() {
	ld h0 = h;
	ld s = h / (n * 2);
	forn (i, n - 1) {
		ld bot = (h0 - h) / h0;
		ld l = h0 - h, r = h0;
		ld low = h0 - h;
		forn (it, 200) {
			ld mid = (l + r) / 2;
			ld top = mid / h0;
			ld cs = (top + bot) / 2 * (mid - low);
			if (cs > s)
				r = mid;
			else
				l = mid;
		}
		h = h0 - l;
		cout << l << endl;
	}
}

int main()
{
#ifdef SU2
	assert(freopen("input.txt", "r", stdin));
	assert(freopen("output.txt", "w", stdout));
#endif

	cout << setprecision(25) << fixed;
	cerr << setprecision(10) << fixed;

	srand(int(time(NULL)));

	assert(read());
	solve();

#ifdef SU2
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}