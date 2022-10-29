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
const int N = 1005;
int a[N][5];

inline bool read() {
	cin >> n;
	forn (i, n)
		forn (j, 5)
			cin >> a[i][j];
	return true;
}
   
inline void solve() {   
	vector<int> ans;
	forn (i, n) {
		bool ok = true;
		forn (j, n) {
			if (!ok)
				break;
			forn (k, j) {
				if (!ok)
					break;
				if (j == i || k == i)
					continue;
				int sum = 0;
				forn (t, 5)
					sum += (a[j][t] - a[i][t]) * (a[k][t] - a[i][t]);
				if (sum > 0)
					ok = false;
			}
		}
		if (ok) {
			ans.pb(i);
		}
	}
	cout << sz(ans) << endl;
	for (int x : ans)
		cout << x + 1 << endl;
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

	read();
	solve();

#ifdef _DEBUG
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}