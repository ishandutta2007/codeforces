#include <vector>
#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int n, m, q, a[22][200009], cl[100009], tp[100009], l[100009], r[100009], v[100009], seg[524299], lazy[524299];
void push(int x) {
	if (lazy[x] != 0) {
		seg[x * 2] = lazy[x * 2] = lazy[x];
		seg[x * 2 + 1] = lazy[x * 2 + 1] = lazy[x];
		lazy[x] = 0;
	}
}
int query(int a, int b, int k, int l, int r) {
	if (a <= l && r <= b) return seg[k];
	if (r <= a || b <= l) return 2012345678;
	push(k);
	int lc = query(a, b, k * 2, l, (l + r) >> 1);
	int rc = query(a, b, k * 2 + 1, (l + r) >> 1, r);
	return min(lc, rc);
}
void update(int a, int b, int x, int k, int l, int r) {
	if (a <= l && r <= b) {
		seg[k] = lazy[k] = x;
		return;
	}
	if (r <= a || b <= l) return;
	push(k);
	update(a, b, x, k * 2, l, (l + r) >> 1);
	update(a, b, x, k * 2 + 1, (l + r) >> 1, r);
	seg[k] = min(seg[k * 2], seg[k * 2 + 1]);
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &a[0][i]), a[0][n + i] = a[0][i];
	int z = *min_element(a[0], a[0] + n);
	for (int i = 0; i < 17; i++) {
		for (int j = 0; j <= 2 * n - (1 << i); j++) {
			a[i + 1][j] = min(a[i][j], a[i][j + (1 << i)]);
		}
	}
	for (int i = 1; i <= n; i++) {
		while (1 << cl[i] <= i) cl[i]++; cl[i]--;
	}
	scanf("%d", &q);
	vector<int> xc;
	for (int i = 0; i < q; i++) {
		scanf("%d %d %d", &tp[i], &l[i], &r[i]); l[i]--;
		if (tp[i] == 1) scanf("%d", &v[i]);
		xc.push_back(l[i]);
		xc.push_back(r[i]);
	}
	sort(xc.begin(), xc.end());
	xc.erase(unique(xc.begin(), xc.end()), xc.end());
	for (int i = 0; i < (int)xc.size() - 1; i++) {
		if (xc[i + 1] - xc[i] >= n) seg[i + 262144] = z;
		else {
			int l = xc[i] % n, r = xc[i + 1] % n;
			if (l > r) r += n;
			seg[i + 262144] = min(a[cl[r - l]][l], a[cl[r - l]][r - (1 << cl[r - l])]);
		}
	}
	for (int i = 262143; i >= 0; i--) seg[i] = min(seg[i * 2], seg[i * 2 + 1]);
	for (int i = 0; i < q; i++) {
		l[i] = lower_bound(xc.begin(), xc.end(), l[i]) - xc.begin();
		r[i] = lower_bound(xc.begin(), xc.end(), r[i]) - xc.begin();
		if (tp[i] == 1) update(l[i], r[i], v[i], 1, 0, 262144);
		else {
			int ret = query(l[i], r[i], 1, 0, 262144);
			printf("%d\n", ret);
		}
	}
	return 0;
}