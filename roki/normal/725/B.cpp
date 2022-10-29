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

string s;

inline bool read() {
	cin >> s;
	return true;
}
  
inline void solve() {   

	map<char, int> m;
	m['a'] = 4, m['b'] = 5, m['c'] = 6;
	m['f'] = 1, m['e'] = 2, m['d'] = 3;
	
	li x = 0;
	forn (i, sz(s) - 1)
		x = x * 10 + (s[i] - '0');
	x--;
	li ans = (x / 4) * 16;
	x %= 4;
	char c = s[sz(s) - 1];
	if (x % 2 == 0) {
		ans += m[c];
	} else {
		ans += m[c] + 7;
	}
	cout << ans << endl;
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