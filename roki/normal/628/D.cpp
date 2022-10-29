#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <queue>
#include <deque>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <iomanip>

using namespace std;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i,l,r) for (int i = int(l); i <= int(r); i++)
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define ft first
#define sc second
#define x first
#define y second
#define mp make_pair
#define pb push_back

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

int m, D;
string a, b;

inline bool read()
{
	cin >> m >> D;
	cin >> a >> b;
	return true;
}

const int N = 2000 + 10;
const int MOD = 1000 * 1000 * 1000 + 7;

int dp[N][N][4];

inline void solve()
{
	dp[0][0][0] = 1;

	forn (i, sz(a)) {
		forn (j, m) {
			forn (d, 4) {
				if (dp[i][j][d] == 0)
					continue;
				if (i & 1) {
					if ((d & 1 || D <= b[i] - '0') && (d & 2 || D >= a[i] -'0')) {
						int nm = (j * 10 + D) % m;
						int nmask = d | (D < b[i] - '0') | ((D > a[i] - '0') << 1);
						dp[i + 1][nm][nmask] += dp[i][j][d];
						while (dp[i + 1][nm][nmask] > MOD)
							dp[i + 1][nm][nmask] -= MOD;
					}
					continue;
				}
				forn (t, 10) {
					if (t == D)
						continue;
					if ((d & 1 || t <= b[i] - '0') && (d & 2 || t >= a[i] -'0')) {
						int nm = (j * 10 + t) % m;
						int nmask = d | (t < b[i] - '0') | ((t > a[i] - '0') << 1);
						dp[i + 1][nm][nmask] += dp[i][j][d];
						while (dp[i + 1][nm][nmask] > MOD)
							dp[i + 1][nm][nmask] -= MOD;
					}
				}
			}
		}
	}

	int ans = 0;

	forn (i, 4)
		ans = (ans + dp[sz(a)][0][i]) % MOD;

	cout << ans << endl;
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	cerr << setprecision(10) << fixed;
	cout << setprecision(15) << fixed;
	
	srand(time(NULL));
	
	read();
	solve();
	
#ifdef _DEBUG
	cerr << "TIME: " << clock() << endl;
#endif
	
	return 0;
}