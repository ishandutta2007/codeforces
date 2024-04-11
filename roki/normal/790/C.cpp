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
   
int cnt[3];
const int N = 80;
int dp[N][N][N][3];

void upd(int &x, int y) {
	x = min(x, y);
}

int f(int i, int j, int k, int t) {
	forn (id, n) {
		if (s[id] == 'V')
		   i--;
		else if (s[id] == 'K')
			j--;
		else
			k--;
		if (t == 0 && i == -1)
			return max(0, -j) + max(0, -k);
		if (t == 1 && j == -1)
			return max(0, -i) + max(0, -k);
		if (t == 2 && k == -1)
			return max(0, -i) + max(0, -j);
	}
	assert(false);
	return 0;
}

inline void solve() {
	forn (i, n) {
		if (s[i] == 'V')
		   cnt[0]++;
		else if (s[i] == 'K')
			cnt[1]++;
		else
			cnt[2]++;
	}
	forn (i, N)
		forn (j, N)
			forn (k, N)
				forn (it, 3)
					dp[i][j][k][it] = INF;
	dp[0][0][0][2] = 0; 
	forn (i, cnt[0] + 1)
		forn (j, cnt[1] + 1)
			forn (k, cnt[2] + 1)
				forn (last, 3) {
					if (i < cnt[0])
						upd(dp[i + 1][j][k][0], dp[i][j][k][last] + f(i, j, k, 0));
					if (j < cnt[1] && last != 0)
						upd(dp[i][j + 1][k][1], dp[i][j][k][last] + f(i, j, k, 1));
					if (k < cnt[2])
						upd(dp[i][j][k + 1][2], dp[i][j][k][last] + f(i, j, k, 2));
				}

	int ans = INF;
	forn (i, 3)
		upd(ans, dp[cnt[0]][cnt[1]][cnt[2]][i]);
	cout << ans << endl;
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