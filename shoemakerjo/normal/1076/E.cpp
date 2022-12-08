#include <bits/stdc++.h>

using namespace std;
#define maxn 300010
#define ll long long
#define pii pair<int, int>
int n, m;
vector<int> adj[maxn];
int dep[maxn];

ll BIT[maxn];
ll ans[maxn];
vector<pii> upd[maxn];

void update(int spot, ll val) {
	while (spot < maxn) {
		BIT[spot] += val;
		spot += spot & (-spot);
	}
}

ll query(int spot) {
	ll res = 0LL;
	while (spot > 0) {
		res += BIT[spot];
		spot -= spot & (-spot);
	}
	return res;
}

void go(int u, int p) {
	dep[u] = p == -1 ? 1 : dep[p]+1;


	for (pii val : upd[u]) {
		int d = val.first;
		ll x = val.second;
		update(dep[u], x);
		update(dep[u]+d+1, 0-x);
	}
	ans[u] = query(dep[u]);

	for (int v : adj[u]) {
		if (v != p) {
			go(v, u);
		}
	}

	for (pii val : upd[u]) {
		int d = val.first;
		ll x = val.second;
		update(dep[u], 0-x);
		update(dep[u]+d+1, x);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int x, y;
	for (int i = 0; i < n-1; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	cin >> m;
	int v, d;
	for (int i = 0; i < m; i++) {
		cin >> v >> d >> x;
		upd[v].push_back(pii(d, x));
	}
	go(1, -1);
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}