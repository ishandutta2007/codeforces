#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

long long quickpow(long long a, long long b) {
	long long res = 1;
	a %= mod;
	while (b) {
		if (b & 1)
			res = res * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}

long long inv(long long n) {
	return quickpow(n, mod - 2);
}

vector<int> prime;
int vis[1005];

void euler() {
	for (int i = 2; i < 1005; ++i) {
		if (!vis[i])prime.push_back(i);
		for (int j = 0; j < prime.size() && i * prime[j] < 1005; ++j) {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0)break;
		}
	}
}

struct edge {
	int to, x, y;
};

vector<edge> g[200005];

long long sum;
map<int, int> tot, cur, pr[200005];

void dfs(int p, int f, long long val) {
	sum = (sum + val) % mod;
	for (auto &i: g[p]) {
		if (i.to == f) continue;
		map<int, int> mp;
		int y = i.y;
		for (int j: prime) {
			if (1ll * j * j > y) break;
			while (y % j == 0) ++pr[i.to][j], y /= j;
		}
		if (y > 1) ++pr[i.to][y];
		for (auto j: pr[i.to]) cur[j.first] += j.second;
		int x = i.x;
		for (int j: prime) {
			if (1ll * j * j > x) break;
			while (x % j == 0) ++mp[j], x /= j;
		}
		if (x > 1) ++mp[x];
		for (auto j: mp) {
			if (j.second > cur[j.first]) {
				tot[j.first] += j.second - cur[j.first];
				cur[j.first] = 0;
			} else {
				cur[j.first] -= j.second;
			}
		}
		for (auto j: mp) pr[i.to][j.first] -= j.second;
		dfs(i.to, p, val * inv(i.x) % mod * i.y % mod);
	}
	for (auto i: pr[p]) cur[i.first] -= i.second;
}

void solve() {
	int n;
	cin >> n;
	tot.clear();
	cur.clear();
	for (int i = 1; i <= n; ++i) pr[i].clear(), g[i].clear();
	for (int i = 0; i < n - 1; ++i) {
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		g[a].push_back({b, x, y});
		g[b].push_back({a, y, x});
	}
	sum = 0;
	dfs(1, 0, 1);
	for (auto i: tot) {
		sum = sum * quickpow(i.first, i.second) % mod;
	}
	cout << sum << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	euler();
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}