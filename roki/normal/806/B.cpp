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
int solved[5];

int a[120][5];

inline bool read() {
	cin >> n;
	forn (i, n)
		forn (j, 5) {
			cin >> a[i][j];
			if (a[i][j] != -1)
				solved[j]++;
	}
	return true;
}
   
int den[] = {2, 4, 8, 16, 32};
int score[] = {500, 1000, 1500, 2000, 2500}; 

bool ok(int m) {
	int tot = n + m;
	int dif = 0;
	forn (j, 5) {
		int add = 0;
		if (a[0][j] > a[1][j] && a[1][j] != -1)
			add = m;		
		int sc = 3000;
		for (int k = 0; k < 5; ++k) {
			if ((solved[j] + add) * den[k] > tot) {
				sc = score[k];
				break;
			}
		}
		if (a[0][j] != -1)
			dif += (250 - a[0][j]) * sc / 250;
		if (a[1][j] != -1)
			dif -= (250 - a[1][j]) * sc / 250;
	}
	return dif > 0;
}

inline void solve() {   
	forn (i, 1e6) {
		if (ok(i)) {
			cout << i << endl;
			return;
		}
	}
	cout << -1 << endl;
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