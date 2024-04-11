#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

const int N = 100005, M = N * 200;
int n, sz, ls[M], rs[M];
bool cov[M], tag[M];
pair<pair<int, int>, pair<int, int>> p[N], q[N];

void update(int u, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) { cov[u] = tag[u] = true; return; }
	int mid = l + r >> 1;
	if (!ls[u]) ls[u] = ++sz;
	if (!rs[u]) rs[u] = ++sz;
	if (tag[u])
		tag[ls[u]] = tag[rs[u]] = cov[ls[u]] = cov[rs[u]] = true, tag[u] = false;
	if (ql <= mid) update(ls[u], l, mid, ql, qr);
	if (qr > mid) update(rs[u], mid + 1, r, ql, qr);
	cov[u] = cov[ls[u]] || cov[rs[u]];
}
bool query(int u, int l, int r, int ql, int qr) {
	if (!cov[u]) return false;
	if (l >= ql && r <= qr) return true;
	int mid = l + r >> 1;
	if (!ls[u]) ls[u] = ++sz;
	if (!rs[u]) rs[u] = ++sz;
	if (tag[u])
		tag[ls[u]] = tag[rs[u]] = cov[ls[u]] = cov[rs[u]] = true, tag[u] = false;
	bool ans = false;
	if (ql <= mid) ans = query(ls[u], l, mid, ql, qr);
	if (!ans && qr > mid) ans = query(rs[u], mid + 1, r, ql, qr);
	return ans;
}

bool check() {
	sort(p + 1, p + 1 + n);
	fill(ls + 1, ls + 1 + sz, 0);
	fill(rs + 1, rs + 1 + sz, 0);
	fill(cov + 1, cov + 1 + sz, 0);
	fill(tag + 1, tag + 1 + sz, 0);
	sz = 1;
	for (int i = 1; i <= n; ++i) q[i] = p[i], swap(q[i].x.x, q[i].x.y);
	sort(q + 1, q + 1 + n);
	for (int i = 1, j = 0; i <= n; ++i) {
		while (j + 1 <= n && q[j + 1].x.x < p[i].x.x)
			++j, update(1, 1, 1000000000, q[j].y.x, q[j].y.y);
		if (query(1, 1, 1000000000, p[i].y.x, p[i].y.y)) return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> p[i].x.x >> p[i].x.y >> p[i].y.x >> p[i].y.y;
	bool ans = check();
	for (int i = 1; i <= n; ++i)
		swap(p[i].x, p[i].y);
	if (!ans) ans = check();
	cout << (ans ? "NO\n" : "YES\n");
	return 0;
}