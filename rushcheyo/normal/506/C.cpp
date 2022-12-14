#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100005;
int n, m, k, p, h[N], a[N];

bool check(ll mid) {
	static int now[N];
	priority_queue<pair<int, int>> q;
	for (int i = 1; i <= n; ++i) {
		now[i] = 0;
		if (m > mid / a[i]) q.emplace(m - mid / a[i], i);
	}
	for (int i = m; i; --i)
		for (int j = 1; j <= k; ++j) {
			if (q.empty()) {
				ll res = 0;
				for (int x = 1; x <= n; ++x) res += (max(0ll, h[x] - (mid + 1ll * now[x] * p - 1ll * a[x] * m)) + p - 1) / p;
				return res <= (i - 1) * k + k - j + 1;
			} else {
				auto t = q.top(); q.pop();
				if (t.first >= i) return false;
				++now[t.second];
				ll tmp = m - (mid + 1ll * now[t.second] * p) / a[t.second];
				if (tmp >= i) return false;
				if (tmp > 0) t.first = tmp, q.push(t);
			}
		}
	if (!q.empty()) return false;
	ll res = 0;
	for (int x = 1; x <= n; ++x) if (mid + 1ll * now[x] * p - 1ll * a[x] * m < h[x]) return false;
	return true;
}

int main() {
	scanf("%d%d%d%d", &n, &m, &k, &p);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", h + i, a + i);
	ll l = 0, r = 100000000000000ll;
	while (l < r) {
		ll mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%lld\n", r);
	return 0;
}