#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}

void exgcd(int a, int b, int &x, int &y) {
	if (!b) { x = 1, y = 0; return; }
	exgcd(b, a % b, y, x);
	y -= a / b * x;
}
int inv(int a, int p) {
	int x, y;
	exgcd(a, p, x, y);
	return (x + p) % p;
}

int get(vector<int> v, int n) {
	sort(v.begin(), v.end());
	for (int i = n - 1; i >= 0; --i) {
		if (!v.empty() && v.back() == i) v.pop_back();
		else return i;
	}
	return 0;
}

ll solve(int n, int m, vector<int> v) {
	if (v.empty()) { puts("-1"); exit(0); }
	int tmp = inv(m, n);
	vector<pair<int, ll>> dis;
	for (int x : v) dis.emplace_back(1ll * x * tmp % n, x);
	sort(dis.begin(), dis.end());
	dis.erase(unique(dis.begin(), dis.end()), dis.end());
	for (int T = 0; T < 2; ++T)
		for (int i = 0; i < dis.size(); ++i) {
			int nxt = (i + 1) % dis.size();
			dis[nxt].second = min(dis[nxt].second, dis[i].second + 1ll * (dis[nxt].first - dis[i].first + n) % n * m);
		}
	ll res = -1;
	for (int i = 0; i < dis.size(); ++i) {
		int nxt = (i + 1) % dis.size();
		int d = (dis[nxt].first - dis[i].first - 1 + n) % n;
		if (d) res = max(res, dis[i].second + 1ll * d * m);
	}
	return res;
}

int main() {
	int n, m;
	vector<int> r, g;
	scanf("%d%d", &n, &m);
	int k;
	scanf("%d", &k), r.resize(k);
	for (int i = 0; i < k; ++i) scanf("%d", &r[i]);
	scanf("%d", &k), g.resize(k);
	for (int i = 0; i < k; ++i) scanf("%d", &g[i]);
	if (n < m) swap(n, m), swap(r, g);
	int x = gcd(n, m);
	if (x > n + m) return puts("-1"), 0;
	ll ans = max(get(r, n), get(g, m));
	vector<vector<int>> all(x);
	for (int t : r) all[t % x].push_back(t / x);
	for (int t : g) all[t % x].push_back(t / x);
	for (int i = 0; i < x; ++i) ans = max(ans, solve(n / x, m / x, all[i]) * x + i);
	printf("%lld\n", ans);
	return 0;
}