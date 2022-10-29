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

const int N = (1 << 16) + 3;
const int M = 200;

int t[M];
int a[N], b[N];
int n;

inline bool read() {
	cin >> n;
	forn (i, n) {
		char c;
		cin >> c >> a[i] >> b[i];
		t[i] = c == 'R' ? 0 : 1;
	}
	return true;
}

int dp[N][M];
   
inline void solve() {   
	
	forn (i, N)
		forn (j, M)
			dp[i][j] = -INF;
			
	dp[0][0] = 0;
	
	forn (mask, 1 << n) {
		int d[2] = {0, 0};
		forn (i, n) {
			if ((mask >> i) & 1) {
				d[t[i]]++;
			} 
		}
		forn (j, M) {
			forn (i, n) {
				if ((mask >> i) & 1) 
					continue;
				int wina = d[0] <= a[i] ? d[0] : a[i];
				int winb = d[1] <= b[i] ? d[1] : b[i];	
				dp[mask | (1 << i)][j + wina] = max(dp[mask | (1 << i)][j + wina], dp[mask][j] + winb);	
			}
		}
	}
	
	int suma = 0, sumb = 0;
	forn (i, n)
		suma += a[i], sumb += b[i];
	
	int ans = max(suma, sumb) + n;

	forn (i, M)
		ans = min(ans, max(suma - i, sumb - dp[(1 << n) - 1][i]) + n);

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