#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef int64_t ll;

const ll INF = (ll)(1e17) + 666;

void start() {
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
}

ll n;
vector<vector<ll>> tree;
vector<ll> result;
vector<ll> arr;
vector<ll> sz;

void add(ll v, ll delta, ll x = -1) {
	if (result[v] >= x) {
		result[v] += delta;
	}
	for (ll u : tree[v]) {
		add(u, delta, x);
	}
}

void dfs(ll v) {
	result[v] = 1;
	sz[v] = 0;
	for (ll u : tree[v]) {
		dfs(u);
		add(u, sz[v]);
		sz[v] += sz[u];
	}
	if (sz[v] < arr[v]) {
		cout << "NO" << endl;
		exit(0);
	}
	result[v] = arr[v];
	for (ll u : tree[v]) {
		add(u, 1, result[v]);
	}
	++sz[v];
}

void solve() {
	cin >> n;
	result.resize(n);
	tree.resize(n);
	arr.resize(n);
	sz.resize(n);
	ll root;
	for (ll i = 0; i < n; ++i) {
		ll p;
		cin >> p >> arr[i];
		--p;
		if (p != -1) {
			tree[p].emplace_back(i);
		} else {
			root = i;
		}
	}
	dfs(root);
	add(root, 1, 0);
	cout << "YES" << endl;
	for (ll i : result) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	start();
	solve();
	return 0;
}