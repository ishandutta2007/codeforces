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
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

char G[MAXN][MAXN];
int n, m, dist[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	
	pll start, end;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> G[i][j];
			if (G[i][j] == 'S') start = {i, j};
			if (G[i][j] == 'E') end = {i, j};
		}
	}

	for (int i = 0; i < MAXN; i++) fill(dist[i], dist[i] + MAXN, INF);
	dist[end.X][end.Y] = 0;
	queue<pll> q;
	q.push(end);
	while (!q.empty()) {
		int x = q.front().X, y = q.front().Y;
		q.pop();
		if (x > 1 && dist[x - 1][y] == INF && G[x - 1][y] != 'T') dist[x - 1][y] = dist[x][y] + 1, q.push({x - 1, y});  
		if (y > 1 && dist[x][y - 1] == INF && G[x][y - 1] != 'T') dist[x][y - 1] = dist[x][y] + 1, q.push({x, y - 1});  
		if (x < n && dist[x + 1][y] == INF && G[x + 1][y] != 'T') dist[x + 1][y] = dist[x][y] + 1, q.push({x + 1, y});  	
		if (y < m && dist[x][y + 1] == INF && G[x][y + 1] != 'T') dist[x][y + 1] = dist[x][y] + 1, q.push({x, y + 1});  
	}

	int d = dist[start.X][start.Y], ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (G[i][j] >= '0' && G[i][j] <= '9' && dist[i][j] <= d) ans += int(G[i][j] - '0');
		}
	}

	cout << ans << endl;
	return 0;
}