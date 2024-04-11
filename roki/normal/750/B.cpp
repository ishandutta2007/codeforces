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
int a[50];
string s[50];

inline bool read() {
	cin >> n;
	forn (i, n)
		cin >> a[i] >> s[i];
	return true;
}
   
inline void solve() {   
	
	int d = 20000;
	forn (i, n) {
		if (d > 20000 || d < 0) {
			cout << "NO" << endl;
			return;
		}
		if (d == 20000 && s[i] != "South") {
			cout << "NO" << endl;
			return;
		}
		if (d == 0 && s[i] != "North") {
			cout << "NO" << endl;
			return;
		}
		if (s[i] == "North")
			d += a[i];
		if (s[i] == "South")
			d -= a[i]; 
	}
	if (d == 20000)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
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