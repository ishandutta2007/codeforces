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

const ll MAXN = 1e6 + 10;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

string W[2];
int dist[2][MAXN], n, k;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	cin >> W[0] >> W[1];
	
	fill(dist[0], dist[0] + MAXN, INF);
	fill(dist[1], dist[1] + MAXN, INF);
	dist[0][0] = 0;
	queue<pair<int, int>> q;
	q.push({0, 0});
	
	while (!q.empty()) {
		pair<int, int> v = q.front();
		int x = v.X, y = v.Y;
		q.pop();	

		if (x < 0 || x > 1 || y < 0) continue;
		if (y >= n) return cout << "YES" << endl, 0;
		if (W[x][y] == 'X' || y < dist[x][y]) continue;

		
		if (dist[x][y + 1] == INF) dist[x][y + 1] = dist[x][y] + 1, q.push({x, y + 1});
		if (y > 0 && dist[x][y - 1] == INF) dist[x][y - 1] = dist[x][y] + 1, q.push({x, y - 1});
		if (dist[1 - x][y + k] == INF) dist[1 - x][y + k] = dist[x][y] + 1, q.push({1 - x, y + k});
	}

	cout << "NO" << endl;
	return 0;
}