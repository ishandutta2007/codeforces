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
string s;

inline bool read() {
	cin >> n >> s;
	return true;
}
   
const int N = 5005;

int MOD = 1000 * 1000 * 1000 + 7;

int add(int a, int b) {
	int res = a + b;
	while(res >= MOD)
		res -= MOD;
	return res;
}

void upd(int &x, int y) {
	x = add(x, y);
}	

int mul(int a, int b) {
	return li(a) * b % MOD;
}
#define  next  _____next

int C[N][N];
int dp[N][N];
int next[N][26];

inline void solve() {   
	forn (i, N) {
		C[i][i] = C[i][0] = 1;
		for (int j = 1; j < i; ++j)
			C[i][j] = add(C[i - 1][j], C[i - 1][j - 1]);
	}
	memset(next, -1, sizeof next);
	for (int i = n - 1; i >= 0; --i) {
		forn (j, 26)
			next[i][j] = next[i + 1][j];
		next[i][s[i] - 'a'] = i;
	}
	
	forn (i, 26)
		if (next[0][i] != -1)
			dp[1][next[0][i]] = 1;
	
	for (int cnt = 1; cnt < n; ++cnt)
		forn (i, n) {
			if (dp[cnt][i])
			forn (j, 26) {
				if (next[i][j] > i && j != s[i] - 'a') {
					upd(dp[cnt + 1][next[i][j]], dp[cnt][i]);
				}
			}
		}
			
	int ans = 0;
	for (int len = 1; len <= n; ++len) {
		forn (j, n) {
			if (dp[len][j])
				upd(ans, mul(dp[len][j], C[n - 1][len - 1]));
		}
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