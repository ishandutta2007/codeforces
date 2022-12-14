#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
typedef long long LL;
int n, m, a[N], b[N], cnt;
vector<pair<int, int>> plan;
LL sa, sb, ans;

struct Pair {
	int i, j;
	LL val;
} p[N * N];

bool operator<(const Pair &x, const Pair &y) {
	return x.val < y.val;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i), sa += a[i];
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
		scanf("%d", b + i), sb += b[i];
	ans = abs(sa - sb);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			LL val = abs((sa - a[i] + b[j]) - (sb + a[i] - b[j]));
			if (val < ans) {
				ans = val;
				plan.clear();
				plan.emplace_back(i, j);
			}
		}
	for (int i = 1; i < m; i++)
		for (int j = i + 1; j <= m; j++)
			p[++cnt] = {i, j, 2ll * (b[i] + b[j])};
	sort(p + 1, p + 1 + cnt);
	if (cnt) {
		for (int i = 1; i < n; i++)
			for (int j = i + 1; j <= n; j++) {
				LL tmp = sa - sb - 2ll * (a[i] + a[j]);
				int pre = upper_bound(p + 1, p + 1 + cnt, (Pair){0, 0, -tmp}) - p - 1;
				int nxt = lower_bound(p + 1, p + 1 + cnt, (Pair){0, 0, -tmp}) - p;
				if (pre) {
					LL val = -tmp - p[pre].val;
					if (val < ans) {
						ans = val;
						plan.clear();
						plan.emplace_back(i, p[pre].i);
						plan.emplace_back(j, p[pre].j);
					}
				}
				if (nxt <= cnt) {
					LL val = tmp + p[nxt].val;
					if (val < ans) {
						ans = val;
						plan.clear();
						plan.emplace_back(i, p[nxt].i);
						plan.emplace_back(j, p[nxt].j);
					}
				}
			}
	}
	printf("%lld\n%d\n", ans, (int)plan.size());
	for (auto x : plan) printf("%d %d\n", x.first, x.second);
	return 0;
}