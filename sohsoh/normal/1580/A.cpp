// ?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 400 + 10;
const ll INF = 1e9;

int ans = INF, F[MAXN], n, m, G[MAXN][MAXN], r_ps[MAXN][MAXN];

inline void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char c;
			cin >> c;
			G[i][j] = (c == '0' ? 0 : 1);
			r_ps[j][i] = r_ps[j][i - 1] + G[i][j];
		}
	}

	ans = INF;
	F[0] = INF / 2;
	for (int x = 1; x <= n; x++) {
		for (int y = x + 4; y <= n; y++) {
			int t = 0;
			for (int i = 1; i <= m; i++) {
				if (i - 3 > 0) 
					ans = min(ans, t + F[i - 3] + y - x - 1 - (r_ps[i][y - 1] - r_ps[i][x]));
				
				t += r_ps[i][y - 1] - r_ps[i][x];
				t += 1 - G[x][i];
				t += 1 - G[y][i];
				
				F[i] = -t + y - x - 1 - (r_ps[i][y - 1] - r_ps[i][x]);
				F[i] = min(F[i], F[i - 1]);
			}
		}
	}

	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		// clear
		solve();
	}
	return 0;
}