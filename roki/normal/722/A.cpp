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
string s;

inline bool read() {
	cin >> n >> s;
	return true;
}

int f(int h, int m, string s) {
	int h0 = h / 10;
	int h1 = h % 10;
	int res = 0;
	if (s[0] - '0' != h0)
		res++;
	if (s[1] - '0' != h1)
		res++;
	int m0 = m / 10;
	int m1 = m % 10;
	if (s[3] - '0' != m0)
		res++;
	if (s[4] - '0' != m1)
		res++;
	return res;
}
   
inline void solve() {
	int hh, mm;
	int ans = INF;   
	if (n == 12) {
		for (int h = 1; h <= 12; ++h)
			forn (m, 60) {
				if (f(h, m, s) < ans) {
					ans = f(h, m, s);
					hh = h, mm = m;
				}
			}
	} else {
		forn (h, 24)
		forn (m, 60) {
				if (f(h, m, s) < ans) {
					ans = f(h, m, s);
					hh = h, mm = m;
				}
			}
	}
	if (hh < 10)
		cout << 0;
	cout << hh << ":";
	if (mm < 10)
		cout << 0;
	cout << mm << endl;
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