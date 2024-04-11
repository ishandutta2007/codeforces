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
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 2000 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

bool G[MAXN][MAXN] = {false};
ll dist[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n, m, r, c, x, y;
	cin >> n >> m >> r >> c >> x >> y;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char c;
			cin >> c;
			if (c == '.') G[i][j] = true;
			dist[i][j] = INF;
		}
	}

	deque<pll> q;
	q.push_back({r, c});
	dist[r][c] = 0;

	while (!q.empty()) {
		pll v = q.front();
		q.pop_front();
		
		if (G[v.X + 1][v.Y] && dist[v.X + 1][v.Y] > dist[v.X][v.Y]) {
			dist[v.X + 1][v.Y] = dist[v.X][v.Y];
			q.push_front({v.X + 1, v.Y});
		}

		if (G[v.X - 1][v.Y] && dist[v.X - 1][v.Y] > dist[v.X][v.Y]) {
			dist[v.X - 1][v.Y] = dist[v.X][v.Y];
			q.push_front({v.X - 1, v.Y});
		}

		if (G[v.X][v.Y + 1] && dist[v.X][v.Y + 1] > dist[v.X][v.Y]) {
			dist[v.X][v.Y + 1] = dist[v.X][v.Y];
			q.push_front({v.X, v.Y + 1});
		}

		if (G[v.X][v.Y - 1] && dist[v.X][v.Y - 1] > dist[v.X][v.Y] + 1) {
			dist[v.X][v.Y - 1] = dist[v.X][v.Y] + 1;
			q.push_back({v.X, v.Y - 1});
		}
	}

	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ll r = dist[i][j] + j - c;
			if (r > y || dist[i][j] > x) continue;
			ans++;
		}

	}

	cout << ans << endl;
	return 0;
}