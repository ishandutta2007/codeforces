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

int n, k, x;
vector<int> a;

inline bool read() {
	cin >> n >> k >> x;
	a.resize(n);
	forn (i, n)
		cin >> a[i];
	return true;
}
   
const int N = 1027;
int cnt[2][N];

int f(int r) {
	if (r < 0)
		return 0;
	return r / 2 + 1;
}

inline void solve() {   
	forn (i, n)
		cnt[0][a[i]]++;	
	forn (ii, k) {
		int i = ii & 1;
		int nt = 1 - i;
		memset(cnt[nt], 0, sizeof cnt[nt]);
		int l = 0;
		forn (y, N) {
			if (cnt[i][y] == 0)
				continue;
			int r = l + cnt[i][y] - 1;
			int cur = f(r) - f(l - 1);
			cnt[nt][y ^ x] += cur;
			cnt[nt][y] += cnt[i][y] - cur;
			l += cnt[i][y];
		}
	}
	int low = -1, hi = -1;
	forn (i, N) {
		if (cnt[k & 1][i]) {
			hi = i;
			if (low == -1)
				low = i;
		}
	}
	cout << hi << ' ' << low << endl;
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