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
#define int			    ll

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 50 + 3;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, k, a, b;
int dist[MAXN][MAXN][2], sh[MAXN][MAXN][2], fact[MAXN], inv[MAXN];

void mkey(int& a) {
	if (a >= MOD) a -= MOD;
}

int C(int k, int n) {
	return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fact[0] = inv[0] = 1;
	for (int i = 1; i < MAXN; i++) fact[i] = fact[i - 1] * i % MOD, inv[i] = poww(fact[i], MOD - 2, MOD);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 50) a++;
		else b++;
	}

	queue<pair<pll, int>> q;
	for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) dist[i][j][0] = dist[i][j][1] = INF;
	dist[0][0][1] = 0;
	sh[0][0][1] = 1;
	q.push({{0, 0}, 1});
	while (!q.empty()) {
		pair<pll, int> v = q.front();
		q.pop();
		int x = v.X.X, y = v.X.Y;
		int d_v = dist[v.X.X][v.X.Y][v.Y];
		if (v.Y) x = a - v.X.X, y = b - v.X.Y;
		for (int k1 = 0; k1 <= x; k1++) {
			for (int k2 = 0; k2 <= y; k2++) {
				int w = sh[v.X.X][v.X.Y][v.Y] * C(k1, x) % MOD * C(k2, y) % MOD;
				
				if (k1 * 50 + k2 * 100 > k || k1 + k2 == 0) continue;
				if (v.Y) {
					if (dist[v.X.X + k1][v.X.Y + k2][0] == INF) {
						dist[v.X.X + k1][v.X.Y + k2][0] = d_v + 1;
						sh[v.X.X + k1][v.X.Y + k2][0] = w;
						q.push({{v.X.X + k1, v.X.Y + k2}, 0}); 
					} else if (d_v + 1 == dist[v.X.X + k1][v.X.Y + k2][0]) {
						mkey(sh[v.X.X + k1][v.X.Y + k2][0] += w);
					}
				} else {
					if (dist[v.X.X - k1][v.X.Y - k2][1] == INF) {
						dist[v.X.X - k1][v.X.Y - k2][1] = d_v + 1;
						sh[v.X.X - k1][v.X.Y - k2][1] = w;
						q.push({{v.X.X - k1, v.X.Y - k2}, 1}); 
					} else if (d_v + 1 == dist[v.X.X - k1][v.X.Y - k2][1]) {	
						sh[v.X.X - k1][v.X.Y - k2][1] += w;
					}
				}
			}
		}
	}

	int ans = min(dist[a][b][0], dist[a][b][1]);
	if (ans == INF) ans = -1;
	cout << ans << endl << sh[a][b][0] << endl;
	return 0;
}