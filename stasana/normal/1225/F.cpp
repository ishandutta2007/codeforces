#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

typedef int64_t ll;

inline void start() {
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
}

vector<vector<ll>> tree;
vector<ll> h;
vector<ll> p;
vector<ll> b;

void dfs_tan(ll v) {
	if (tree[v].empty()) {
		h[v] = 1;
		return;
	}
	for (ll u : tree[v]) {
		dfs_tan(u);
		h[v] = max(h[v], h[u] + 1);
	}
}

void dfs_kun(ll v) {
	b.emplace_back(v);
	sort(tree[v].begin(), tree[v].end(), [&](int a, int b) {
		return h[a] < h[b];
	});
	for (ll u : tree[v]) {
		dfs_kun(u);
	}
}

inline void solve() {
	ll n;
	cin >> n;
	tree.resize(n);
	p.resize(n);
	h.resize(n);
	for (ll i = 1; i < n; ++i) {
		cin >> p[i];
		tree[p[i]].emplace_back(i);
	}
	dfs_tan(0);
	dfs_kun(0);
	vector<ll> res;
	for (ll i = 1; i < n; ++i) {
		ll x = b[i];
		ll y = b[i - 1];
		while (y != p[x]) {
			res.emplace_back(x);
			y = p[y];
		}
	}
	for (ll i : b) {
		cout << i << " ";
	}
	cout << endl;
	cout << res.size() << endl;
	for (ll i : res) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	start();
	solve();
	return 0;
}