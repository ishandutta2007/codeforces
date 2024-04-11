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

const ll MAXN = 1e3 + 10;
const ll INF = 1e8;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

deque<pll> dq;
int dist[3][MAXN][MAXN], n, m;
char G[MAXN][MAXN];

bool is_val(int x, int y) {
	if (x > 0 && y > 0 && x <= n && y <= m && G[x][y] != '#') return true;
	return false;
}

void upd(int ind, int x, int y, int px, int py) {
	if (!is_val(x, y)) return;
	if (G[x][y] != '.') {
		if (dist[ind][x][y] > dist[ind][px][py]) {
			dist[ind][x][y] = dist[ind][px][py];
			dq.push_front({x, y});
		}
	} else {
		if (dist[ind][x][y] > dist[ind][px][py] + 1) {
			dist[ind][x][y] = dist[ind][px][py] + 1;
			dq.push_back({x, y});
		}
	}
}

void BFS(int ind) {
	while (!dq.empty()) {
		pll v = dq.front();
		dq.pop_front();
		int x = v.X, y = v.Y;
		upd(ind, x - 1, y, x, y);
		upd(ind, x + 1, y, x, y);
		upd(ind, x, y - 1, x, y);
		upd(ind, x, y + 1, x, y);
	}
}

void bfs_c(int ind, char c) {
	while (!dq.empty()) dq.pop_back();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (G[i][j] == c) {
				dist[ind][i][j] = 0;
				dq.push_back({i, j});
			}	
		}
	}

	BFS(ind);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> G[i][j];
	for (int i = 0; i < 3; i++) for (int j = 0; j < MAXN; j++) for (int k = 0; k < MAXN; k++) dist[i][j][k] = INF;
	bfs_c(0, '1');
	bfs_c(1, '2');
	bfs_c(2, '3');

	int ans = INF;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ans = min(ans, dist[0][i][j] + dist[1][i][j] + dist[2][i][j] - 2 * int(G[i][j] == '.'));
		}
	}

	if (ans == INF) ans = -1;
	cout << ans << endl;
	return 0;
}