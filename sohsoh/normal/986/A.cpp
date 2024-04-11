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
 
const ll MAXN = 1e5 + 10;
const ll MAXK = 200 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll A[MAXN][MAXK], n, m, k, s;
vector<ll> adj[MAXN], order;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 0; i < MAXN; i++) fill(A[i], A[i] + MAXK, INF);
	cin >> n >> m >> k >> s;
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		A[i][x] = 0;
	}

	for (int i = 0; i < m; i++) {
		ll u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for (int i = 1; i <= k; i++) {
		queue<ll> q;
		for (int j = 1; j <= n; j++) if (A[j][i] == 0) q.push(j);
		while (!q.empty()) {
			ll v = q.front();
			q.pop();
			for (ll u : adj[v]) if (A[u][i] == INF) A[u][i] = A[v][i] + 1, q.push(u);
		}
	}

	for (int i = 1; i <= n; i++) {
		sort(A[i], A[i] + k + 2);
		ll ans = 0;
		for (int j = 0; j < s; j++) ans += A[i][j];
		cout << ans << sep;
	}

	cout << endl;
	return 0;
}