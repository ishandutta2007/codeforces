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

vector<pair<int, int>> adj[2][MAXN];
int dist[2][MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char c;
			cin >> c;
			if (c == '#') {
				adj[0][i].push_back({1, j});
				adj[1][j].push_back({0, i});
			}
		}
	}

	fill(dist[0], dist[0] + MAXN, INF);
	fill(dist[1], dist[1] + MAXN, INF);

	queue<pair<int, int>> q;
	q.push({0, 1});
	dist[0][1] = 0;
	while (!q.empty()) {
		pair<int, int> v = q.front();
		q.pop();
		for (pair<int, int> u : adj[v.X][v.Y])
			if (dist[u.X][u.Y] == INF) dist[u.X][u.Y] = dist[v.X][v.Y] + 1, q.push(u);
	}

	if (dist[0][n] == INF) dist[0][n] = -1;
	return cout << dist[0][n] << endl, 0;
	return 0;
}