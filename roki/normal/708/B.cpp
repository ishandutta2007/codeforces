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

int c00, c01, c10, c11;

void gen() {
	string s = "";
	int n = 2;
	forn (i, n)
		s += '0' + rand() % 2;
	forn (i, n)
		forn (j, i)
			if (s[i] == '0' && s[j] == '0')
				c00++;
	forn (i, n)
		forn (j, i)
			if (s[i] == '0' && s[j] == '1')
				c10++;
	forn (i, n)
		forn (j, i)
			if (s[i] == '1' && s[j] == '0')
				c01++;
	forn (i, n)
		forn (j, i)
			if (s[i] == '1' && s[j] == '1')
				c11++;
	cerr << s << endl;
}

inline bool read() {
	//gen();
	//return true;
	cin >> c00 >> c01 >> c10 >> c11;
	return true;
}
   
const int N = 1000 * 1000 + 1;

inline void solve() {  
	if (c01 == 0 && c10 == 0 && c11 == 0 && c00 == 0) {
		cout << 0 << endl;
		return;
	}
	int c0 = -1;
	forn (i, N)
		if (li(i) * (i - 1) == c00 * 2)
			c0 = i;
	int c1 = -1;
	forn (i, N)
		if (li(i) * (i - 1) == c11 * 2)
			c1 = i;
 	if (c0 == -1 || c1 == -1 || c0 + c1 > 1000000) {
 		cout << "Impossible" << endl;
 		return;
 	}

 	if (c01 == 0 && c10 == 0) {
 		if (c00 && c11) {
 			cout << "Impossible" << endl;
 			return;
 		}
 		if (c00 == 0)
 			forn (i, c1)
 				cout << 1;
 		if (c11 == 0)
 			forn (i, c0)
 				cout << 0;
		return;
 	}

 	string ans = "";
 	int n = c0 + c1;
 	forn (i, n) {
		if (c01 >= c1 && c0 > 0 && li(c0 - 1) * c1 >= c10) {
			ans += '0';
			c01 -= c1;
			c0--;
		} else {
			ans += '1';
			c10 -= c0;
			c1--;
		}
 	}
 	if (c10 != 0 || c01 != 0 || c0 != 0 || c1 != 0)
 		cout << "Impossible" << endl;
 	else
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