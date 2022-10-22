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
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 40 + 4;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

bool is_good[MAXN][MAXN][MAXN][MAXN] = {false};
ll ps[MAXN][MAXN] = {0}, A[MAXN][MAXN] = {0}, n, m, q, E[MAXN][MAXN][MAXN][MAXN], ans[MAXN][MAXN][MAXN][MAXN] = {0};

ll sum(ll a, ll b, ll x, ll y) {
	a--; b--;
	return ps[x][y] - ps[a][y] - ps[x][b] + ps[a][b];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char c;
			cin >> c;
			if (c == '1') A[i][j] = 1;
			ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + A[i][j];
		}
	}

	for (int x1 = 1; x1 <= n; x1++) {
		for (int y1 = 1; y1 <= m; y1++) {
			for (int x2 = x1; x2 <= n; x2++) {
				for (int y2 = y1; y2 <= m; y2++) {
					if (sum(x1, y1, x2, y2) == 0) is_good[x1][y1][x2][y2] = true;
				}
			}
		}
	}

	for (int x2 = 1; x2 <= n; x2++) {
		for (int y2 = 1; y2 <= m; y2++) {
			for (int sz1 = 0; sz1 < x2; sz1++) {
				for (int sz2 = 0; sz2 < y2; sz2++) {
					ll x1 = x2 - sz1, y1 = y2 - sz2;
					if (sz1 == 0 && sz2 == 0) E[x1][y1][x2][y2] = is_good[x1][y1][x2][y2];
					else if (sz1 == 0) E[x1][y1][x2][y2] = E[x1][y1 + 1][x2][y2] + is_good[x1][y1][x2][y2];
					else if (sz2 == 0) E[x1][y1][x2][y2] = E[x1 + 1][y1][x2][y2] + is_good[x1][y1][x2][y2];
					else E[x1][y1][x2][y2] = E[x1 + 1][y1][x2][y2] + E[x1][y1 + 1][x2][y2] - E[x1 + 1][y1 + 1][x2][y2] + is_good[x1][y1][x2][y2];
				}
			}
		}
	}

	for (int x1 = 1; x1 <= n; x1++) {
		for (int y1 = 1; y1 <= m; y1++) {
			for (int x2 = x1; x2 <= n; x2++) {
				for (int y2 = y1; y2 <= m; y2++) {
					ans[x1][y1][x2][y2] = ans[x1][y1][x2 - 1][y2] + ans[x1][y1][x2][y2 - 1] - ans[x1][y1][x2 - 1][y2 - 1] + E[x1][y1][x2][y2];
				}
			}
		}
	}

	while (q--) {
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << ans[x1][y1][x2][y2] << endl;
	}
	return 0;
}