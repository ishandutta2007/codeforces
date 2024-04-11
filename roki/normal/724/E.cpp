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

li n, c;
const int N = 10005;
li a[N], b[N];
vector<li> dp1[N / 2];
vector<li> dp2[N / 2];

void gen() {
	n = 10000;
	forn (i, n) {
		a[i] = (rand() << 15) ^ rand();
		b[i] = (rand() << 15) ^ rand();
	}
}

inline bool read() {
//	gen();
//	return true;
	cin >> n >> c;
	forn (i, n)
		cin >> a[i];
	forn (i, n)
		cin >> b[i];
	return true;
}
   

inline void solve() {
	for (int i = N / 2 - 1; i >= 0; --i) {
		dp1[i].resize(N / 2 - i + 1);
		dp2[i].resize(N / 2 - i + 1);
	}
	
	int n1 = n / 2;
	int n2 = n - n1;
	
	for (int i = n1 - 1; i >= 0; --i) {
		int cntr = n1 - 1 - i;
		forn (j, cntr + 2) {
			dp1[i][j] = INF64;
			if (j <= cntr)
				dp1[i][j] = dp1[i + 1][j] + b[i] + c * j;
			if (j)
				dp1[i][j] = min(dp1[i][j], dp1[i + 1][j - 1] + a[i]);
		}
	}	
	
	for (int i = n2 - 1; i >= 0; --i) {
		int cntr = n2 - 1 - i;
		forn (j, cntr + 2) {
			dp2[i][j] = INF64;
			if (j <= cntr)
				dp2[i][j] = dp2[i + 1][j] + b[i + n1] + c * j;
			if (j)
				dp2[i][j] = min(dp2[i][j], dp2[i + 1][j - 1] + a[i + n1]);
		}
	}	
	
	li ans = INF64;
	
	forn (i, n1 + 1)
		forn (j, n2 + 1) {
			ans = min(ans, dp1[0][i] + dp2[0][j] + j * c * (n1 - i));
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