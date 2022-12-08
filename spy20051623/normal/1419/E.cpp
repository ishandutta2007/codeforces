#include <bits/stdc++.h>

using namespace std;

vector<int> prime;
int vis[33333];
int n, x;
map<int, int> m;

void euler() {
	for (int i = 2; i < 33333; ++i) {
		if (!vis[i]) prime.push_back(i);
		for (int j = 0; j < prime.size() && i * prime[j] < 33333; ++j) {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
}

void dfs(int v, map<int, int>::iterator it, bool st) {
	if (it == m.end()) {
		if (v != n && v != x) cout << v << ' ';
		return;
	}
	auto it1 = it;
	++it1;
	for (int i = 0; i <= it->second; ++i) {
		if (st) {
			st = false;
			v *= it->first;
			continue;
		}
		dfs(v, it1, false);
		v *= it->first;
	}
}

void solve() {
	m.clear();
	cin >> n;
	int t = n;
	for (int i: prime) {
		if (i * i > t) break;
		while (t % i == 0) ++m[i], t /= i;
	}
	if (t > 1) ++m[t];
	bool ok = true;
	for (auto it = m.begin(); it != m.end(); ++it) {
		if (it != --m.end()) {
			auto it1 = it;
			++it1;
			x = it->first * it1->first;
		} else x = 0;
		dfs(1, it, true);
		if (x && x != n) cout << x << ' ';
		if (x == n) ok = false;
	}
	cout << n << '\n';
	if (!ok) cout << 1 << '\n';
	else cout << 0 << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	euler();
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}