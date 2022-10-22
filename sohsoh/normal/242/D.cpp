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
const ll C = 10;

int n, m, A[MAXN], S[MAXN];
vector<int> adj[MAXN], ans;
queue<int> q;

inline void press(int v) {
	S[v]++;
	ans.push_back(v);
	for (int u : adj[v]) {
		S[u]++;
		if (S[u] == A[u]) q.push(u);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		if (A[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		press(v);
	}

	cout << ans.size() << endl;
	for (int e : ans) cout << e << sep;
	cout << endl;

	return 0;
}