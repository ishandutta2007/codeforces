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
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll dp[MAXN], W[MAXN], B[MAXN], C[MAXN], n, m;
vector<ll> adj_w[MAXN], adj_b[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		ll u, v, c;
		cin >> u >> v >> c;
		swap(v, u);
		if (c) adj_b[u].push_back(v);
		else adj_w[u].push_back(v);
	}

	fill(C, C + MAXN, 2);
	fill(W, W + MAXN, n);
	fill(dp, dp + MAXN, n);
	fill(B, B + MAXN, n);

	dp[n] = W[n] = B[n] = 0;
	
	queue<ll> q;
	q.push(n);
	while (!q.empty()) {
		ll v = q.front();
		q.pop();
		for (ll u : adj_b[v]) {
			if (B[u] < n) continue;
			B[u] = dp[v] + 1;
			if (max(B[u], W[u]) < n) {
				q.push(u);
				dp[u] = max(B[u], W[u]);
			}	
		}

		for (ll u : adj_w[v]) {
			if (W[u] < n) continue;
			W[u] = dp[v] + 1;
			if (max(B[u], W[u]) < n) {
				q.push(u);
				dp[u] = max(B[u], W[u]);
			}	
		}
	}

	if (dp[1] >= n) dp[1] = -1;
	cout << dp[1] << endl;
	for (int i = 1; i <= n; i++) {
		if (W[i] > B[i]) cout << 0;
		else cout << 1;
	}
       	cout << endl;	
	return 0;
}