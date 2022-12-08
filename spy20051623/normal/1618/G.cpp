#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
const int N = 2e5 + 5;
pii a[N << 1];
int fa[N << 1], w[N << 1];
map<int, vector<int>> mp;
long long sum[N << 1];
struct dt {
	int id, k;
	long long ans;
} d[N];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void solve() {
	int n, m, q;
	cin >> n >> m >> q;
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].first;
		a[i].second = 1;
		ans += a[i].first;
	}
	for (int i = 1; i <= m; ++i) {
		cin >> a[n + i].first;
	}
	sort(a + 1, a + n + m + 1);
	for (int i = 1; i <= n + m; ++i) {
		fa[i] = i;
		w[i] = a[i].second;
		sum[i] = sum[i - 1] + a[i].first;
		if (i > 1) mp[a[i].first - a[i - 1].first].push_back(i - 1);
	}
	auto it = mp.begin();
	for (int i = 1; i <= q; ++i) {
		cin >> d[i].k;
		d[i].id = i;
	}
	sort(d + 1, d + q + 1, [&](dt &x, dt &y) { return x.k < y.k; });
	for (int i = 1; i <= q; ++i) {
		if (d[i].k == d[i - 1].k) {
			d[i].ans = ans;
			continue;
		}
		while (it != mp.end() && it->first <= d[i].k) {
			for (int j: it->second) {
				int x = find(j), y = find(j + 1);
				ans -= sum[y] - sum[y - w[y]];
				ans -= sum[x] - sum[x - w[x]];
				w[y] += w[x];
				fa[x] = y;
				ans += sum[y] - sum[y - w[y]];
			}
			++it;
		}
		d[i].ans = ans;
	}
	sort(d + 1, d + q + 1, [&](dt &x, dt &y) { return x.id < y.id; });
	for (int i = 1; i <= q; ++i) cout << d[i].ans << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}