#include <bits/stdc++.h>

using namespace std;

int a[300005];

struct dt {
	int x{}, t{}, d{};

	dt() = default;

	dt(int xx, int tt, int dd) {
		x = xx, t = tt, d = dd;
	}

	bool operator<(dt &o) const {
		return t < o.t;
	}
} d[300005];

void solve() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		a[i] = 2e9;
	}
	queue<dt> q;
	for (int i = 0; i < k; ++i) {
		scanf("%d", &d[i].x);
	}
	for (int i = 0; i < k; ++i) {
		scanf("%d", &d[i].t);
	}
	sort(d, d + k);
	int cur = d[0].t;
	int res = 1;
	int point = 1;
	a[d[0].x] = d[0].t;
	if (d[0].x > 1)q.push(dt(d[0].x - 1, d[0].t + 1, -1));
	if (d[0].x < n)q.push(dt(d[0].x + 1, d[0].t + 1, 1));
	while (res < n) {
		while (point < k && d[point].t == cur) {
			if (d[point].t >= a[d[point].x]) {
				++point;
				continue;
			}
			a[d[point].x] = d[point].t;
			++res;
			if (d[point].x > 1)q.push(dt(d[point].x - 1, d[point].t + 1, -1));
			if (d[point].x < n)q.push(dt(d[point].x + 1, d[point].t + 1, 1));
			++point;
		}
		while (q.front().t == cur) {
			auto p = q.front();
			q.pop();
			if (p.t >= a[p.x])continue;
			a[p.x] = p.t;
			++res;
			int to = p.x + p.d;
			if (to >= 1 && to <= n && p.t + 1 < a[to])q.push(dt(to, p.t + 1, p.d));
		}
		++cur;
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}