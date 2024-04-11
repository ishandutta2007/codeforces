#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 200 + 10;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int h, t, R, n, m, dist[MAXN][MAXN], col[MAXN][MAXN], ans, dp[MAXN][MAXN];
pll A[MAXN], B[MAXN];

void dfs(int x, int y) {
	col[x][y] = 1;
	dp[x][y] = 1;

	for (int i = 1; i <= min(n, x); i++) {
		int nx = x - i, ny = y;
		nx += A[i].X, ny += A[i].Y;
		if (nx + ny <= R) {
			if (col[nx][ny] == 0) {
				dfs(nx, ny);
				dp[x][y] = max(dp[x][y], dp[nx][ny] + 1);
			} else if (col[nx][ny] == 1) {
				cout << "Draw" << endl;
				exit(0);
			} else 	dp[x][y] = max(dp[x][y], dp[nx][ny] + 1);
		}
	}

	for (int i = 1; i <= min(m, y); i++) {
		int nx = x, ny = y - i;
		nx += B[i].X, ny += B[i].Y;
		if (nx + ny <= R) {
			if (col[nx][ny] == 0) {
				dfs(nx, ny);
				dp[x][y] = max(dp[x][y], dp[nx][ny] + 1);
			} else if (col[nx][ny] == 1) {
				cout << "Draw" << endl;
				exit(0);
			} else dp[x][y] = max(dp[x][y], dp[nx][ny] + 1);
		}
	}

	col[x][y] = 2;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> h >> t >> R >> n;
	for (int i = 1; i <= n; i++) cin >> A[i].X >> A[i].Y;
	cin >> m;
	for (int i = 1; i <= m; i++) cin >> B[i].X >> B[i].Y;
	for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) dist[i][j] = INF;	
	dist[h][t] = 0;
	queue<pll> q;
	q.push({h, t});

	while (!q.empty()) {
		int x = q.front().X, y = q.front().Y, d_v = dist[x][y];
		q.pop();
	
		for (int i = 1; i <= min(n, x); i++) {
			int nx = x - i, ny = y;
			nx += A[i].X, ny += A[i].Y;
			if (nx + ny <= R) {
				if (dist[nx][ny] == INF) {
					dist[nx][ny] = d_v + 1;
					q.push({nx, ny});
				}
			}
		}

		for (int i = 1; i <= min(m, y); i++) {
			int nx = x, ny = y - i;
			nx += B[i].X, ny += B[i].Y;
			if (nx + ny <= R) {
				if (dist[nx][ny] == INF) {
					dist[nx][ny] = d_v + 1;
					q.push({nx, ny});
				} 
			}
		}
	}

	ans = dist[0][0];
	if (ans < INF) return cout << "Ivan" << endl << ans << endl, 0;
	
	ans = 0;
	dfs(h, t);

	cout << "Zmey" << endl << dp[h][t] << endl;
	return 0;
}