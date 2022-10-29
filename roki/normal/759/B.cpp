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

const int N = 100 * 1000 + 5;

int n;
int t[N];
int dur[3] = {1, 90, 1440};
int cost[3] = {20, 50, 120};
vector<int> x;

inline bool read() {
	cin >> n;
	forn (i, n)
		cin >> t[i];
	return true;
}
   
int f[4 * N];

int id(int y) {
	//cerr << y << endl;
	return lower_bound(all(x), y) - x.begin();
}

bool a[4 * N];

inline void solve() {
	x.pb(-INF);
	
	forn (i, n) {
		x.pb(t[i]);
		forn (j, 3)
			x.pb(t[i] - dur[j]);
	}

	sort(all(x));
	x.resize(unique(all(x)) - x.begin());
	
	
	int last = 0;
	
	forn (i, n)
		a[id(t[i])] = 1;
	
	forn (i, sz(x)) {
		if (a[i] == 0) {
			if (i)
				f[i] = f[i - 1];
		} else {
			f[i] = INF;
			forn (j, 3) {
				int prv = id(x[i] - dur[j]);
				f[i] = min(f[i], f[prv] + cost[j]);
			}
			cout << f[i] - last << endl;
			last = f[i];
		}
		//cerr << x[i] << ' ' << f[i] << endl;
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