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
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int dist[MAXN][MAXN], n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++)
			cin >> dist[i][j];

	int q;
	cin >> q;
	while (q--) {
		int a, b, c;
		cin >> a >> b >> c;
		ll ans = 0;
		for (int u = 1; u <= n; u++) {
			for (int v = 1; v <= n; v++) {
				dist[u][v] = dist[v][u] = min({dist[u][v], dist[u][a] + c + dist[v][b], dist[u][b] + c + dist[v][a]});
				if (u < v) ans += dist[u][v];
			}
		}

		cout << ans << sep;
	}

	cout << endl;
	return 0;
}