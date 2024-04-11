#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

const ll MAXN = 500 + 10;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int A[MAXN][MAXN], dist[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> A[i][j];
			dist[i][j] = INF;
		}
	}

	vector<ll> ans, Q, V;
	for (int i = 0; i < n; i++) {
		int v;
		cin >> v;
		Q.push_back(v);
	}

	reverse(all(Q));
	for (int v : Q) {
		V.push_back(v);
		for (int u : V) {
			dist[v][u] = A[v][u];
			dist[u][v] = A[u][v];
		}
		
		for (int k : V) {
			for (int u : V) {
				dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
				dist[v][u] = min(dist[v][u], dist[v][k] + dist[k][u]);
			}
		}

		ll ans_t = 0;
		for (int u1 : V)
			for (int u2 : V)
				dist[u1][u2] = min(dist[u1][u2], dist[u1][v] + dist[v][u2]), ans_t += dist[u1][u2];
		ans.push_back(ans_t);
	}

	reverse(all(ans));
	for (ll e : ans) cout << e << sep;
	cout << endl;
	return 0;
}