#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int sgn(int x) {
	return (x > 0) - (x < 0);
}

const int N = 100005;
const ll inf = (ll)1e15 + 5;
int n, m, q, fa[50][2 * N], cov[4 * N], jy[2 * N];
ll w[50][2 * N], T[N];
struct arrow {
	int x1, y1, x2, y2, id;
} a[2 * N];

void update(int u, int l, int r, int ql, int qr, int x) {
	if (l >= ql && r <= qr) { cov[u] = x; return; }
	int mid = l + r >> 1;
	if (cov[u]) cov[u << 1] = cov[u << 1 | 1] = cov[u];
	if (ql <= mid) update(u << 1, l, mid, ql, qr, x);
	if (qr > mid) update(u << 1 | 1, mid + 1, r, ql, qr, x);
	cov[u] = cov[u << 1] == cov[u << 1 | 1] ? cov[u << 1] : 0;
}
int query(int u, int l, int r, int pos) {
	if (cov[u] || l == r) return cov[u];
	int mid = l + r >> 1;
	if (pos <= mid) return query(u << 1, l, mid, pos);
	return query(u << 1 | 1, mid + 1, r, pos);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d%d%d%d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2), a[i].id = i;
	scanf("%d", &q);
	for (int i = 1; i <= q; ++i) {
		int x, y;
		char dir[5];
		scanf("%d%d%s%lld", &x, &y, dir, T + i);
		a[n + i].x2 = x;
		a[n + i].y2 = y;
		a[n + i].x1 = x + (dir[0] == 'L' ? 1 : dir[0] == 'R' ? -1 : 0);
		a[n + i].y1 = y + (dir[0] == 'D' ? 1 : dir[0] == 'U' ? -1 : 0);
		a[n + i].id = n + i;
	}
	for (int _ = 0; _ < 4; ++_) {
		sort(a + 1, a + 1 + n + q, [](const arrow &a, const arrow &b) {
			return max(a.x1, a.x2) > max(b.x1, b.x2) || (max(a.x1, a.x2) == max(b.x1, b.x2) && a.id < b.id);
		});
		for (int i = 1; i <= n + q; ++i) jy[a[i].id] = i;
		fill(cov, cov + 4 * (m + 5), 0);
		for (int i = 1; i <= n + q; ++i) {
			if (a[i].x1 < a[i].x2) {
				fa[0][a[i].id] = query(1, -1, m + 1, a[i].y1);
				w[0][a[i].id] = !fa[0][a[i].id] ? inf : abs(a[jy[fa[0][a[i].id]]].x2 - a[i].x2) + abs(a[jy[fa[0][a[i].id]]].y2 - a[i].y2);
			}
			if (a[i].id <= n) update(1, -1, m + 1, min(a[i].y1, a[i].y2), max(a[i].y1, a[i].y2), a[i].id);
		}
		for (int i = 1; i <= n + q; ++i) {
			swap(a[i].x1, a[i].y1), a[i].x1 = m - a[i].x1;
			swap(a[i].x2, a[i].y2), a[i].x2 = m - a[i].x2;
		}
	}
	for (int j = 1; j < 50; ++j)
		for (int i = 1; i <= n + q; ++i) {
			w[j][i] = min(inf, w[j - 1][i] + w[j - 1][fa[j - 1][i]]);
			fa[j][i] = fa[j - 1][fa[j - 1][i]];
		}
	for (int i = 1; i <= n + q; ++i) jy[a[i].id] = i;
	for (int i = 1; i <= q; ++i) {
		int u = n + i;
		ll left = T[i];
		for (int j = 49; j >= 0; --j)
			if (left >= w[j][u]) left -= w[j][u], u = fa[j][u];
		ll x = a[jy[u]].x2, y = a[jy[u]].y2;
		ll dx = sgn(x - a[jy[u]].x1), dy = sgn(y - a[jy[u]].y1), tmp;
		if (!fa[0][u]) tmp = inf;
		else {
			if (dx) tmp = sgn(x - a[jy[fa[0][u]]].x1) * sgn(x - a[jy[fa[0][u]]].x2) <= 0 ? 0 : abs(a[jy[fa[0][u]]].x2 - x);
			else tmp = sgn(y - a[jy[fa[0][u]]].y1) * sgn(y - a[jy[fa[0][u]]].y2) <= 0 ? 0 : abs(a[jy[fa[0][u]]].y2 - y);
		}
		tmp = min(tmp, left), left -= tmp, x += dx * tmp, y += dy * tmp, u = fa[0][u];
		dx = sgn(a[jy[u]].x2 - a[jy[u]].x1), dy = sgn(a[jy[u]].y2 - a[jy[u]].y1);
		x += dx * left, y += dy * left;
		if (x < 0) x = 0;
		if (x > m) x = m;
		if (y < 0) y = 0;
		if (y > m) y = m;
		printf("%d %d\n", (int)x, (int)y);
	}
}