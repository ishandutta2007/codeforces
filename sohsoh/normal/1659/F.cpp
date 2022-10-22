#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int n, fen[MAXN], P[MAXN], rt, x;
vector<int> adj[MAXN];

inline void update(int ind, int val) {
	for (++ind; ind < (n + 10); ind += ind & -ind)
		fen[ind] += val;
}

inline int query(int ind) {
	int ans = 0;
	for (++ind; ind > 0; ind -= ind & -ind)
		ans += fen[ind];
	
	return ans;
}

inline int solve() {
	rt = 0;
	for (int i = 0; i < n + 10; i++) {
		adj[i].clear();
		fen[i] = 0;
	}

	cin >> n >> x;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		P[x] = i;
		
		cnt += (x != i);
	}

	if (cnt == 2 && P[x] == x) return cout << "Alice" << endl, 0;

	int inv = (1ll * n * (n - 1) / 2) % 2;
	for (int i = 1; i <= n; i++) {
		inv = (inv + query(P[i] - 1)) & 1;
		update(P[i], 1);
	}

	for (int v = 1; v <= n; v++) {
		if (int(adj[v].size()) > 1) {
			if (rt) return cout << "Alice" << endl, 0;
			rt = v;
		}
	}

	if (P[rt] != rt && (x == rt || x == find(P + 1, P + n + 1, rt) - P)) return cout << "Bob" << endl, 0;
	cout << (is_sorted(P + 1, P + n + 1) || (inv ^ (x != rt)) ? "Alice" : "Bob") << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}