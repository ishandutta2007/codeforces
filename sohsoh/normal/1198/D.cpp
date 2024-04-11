/*
    Soheil Mohammadkhani
    Sos Goge Tabarok :)
*/
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
 
#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 50 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll dp[MAXN][MAXN][MAXN][MAXN] = {0};
ll A[MAXN][MAXN], ps[MAXN][MAXN] = {0};

ll sum(ll x1, ll y1, ll x2, ll y2) {
	x1--;
	y1--;
	return ps[x2][y2] - ps[x2][y1] - ps[x1][y2] + ps[x1][y1];
}

int main() {
	fast_io;
	ll n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char c;
			cin >> c;
			A[i][j] = 0;
			if (c == '#') A[i][j] = 1;
		}
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + A[i][j];
	
	
	for (int szx = 0; szx <= n; szx++) {
		for (int szy = 0; szy <= n; szy++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					ll x = i + szx, y = j + szy;
					if (x > n || y > n) continue;

					if (i == x && j == y) {
						dp[i][j][x][y] = A[i][j];
						continue;
					}

					dp[i][j][x][y] = max(szx + 1, szy + 1);
					for (int c = j; c <= y; c++) {
						if (sum(i, c, x, c) == 0) {
							ll ans = 0;
							if (c > j) ans += dp[i][j][x][c - 1];
							if (c < y) ans += dp[i][c + 1][x][y];
							dp[i][j][x][y] = min(dp[i][j][x][y], ans);
						}
					}

					for (int r = i; r <= x; r++) {
						if (sum(r, j, r, y) == 0) {
							ll ans = 0;
							if (r > i) ans += dp[i][j][r - 1][y];
							if (r < x) ans += dp[r + 1][j][x][y];
							dp[i][j][x][y] = min(dp[i][j][x][y], ans);
						}
					}
				}
			}
		}
	}
	
	cout << dp[1][1][n][n] << endl;
	return 0;
}