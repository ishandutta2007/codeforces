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

int n, k;
const int N = 55;
string s[N];

inline bool read() {
	cin >> n >> k;
	forn (i, n - k + 1)
		cin >> s[i];
	return true;
}
   
string ans[N];

inline void solve() {   
	forn (i, n) {
		ans[i] = 'A';
		ans[i] += ('a' + i / 26);
		ans[i] += ('a' + i % 26);
	}
	forn (i, n)
		cerr << ans[i] << endl;
	forn (i, n - k + 1) {
		if (s[i] == "NO") {
			ans[i + k - 1] = ans[i];
		}
	}
	forn (i, n)
		cout << ans[i] << ' ';
	cout << endl;
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