#include <cmath>
#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int n, r[100009], h[100009], p[100009]; long long v[100009], seg[262144];
void update(int i, long long x) {
	i += 131072; seg[i] = x;
	while (i > 1) {
		i >>= 1;
		seg[i] = max(seg[i * 2], seg[i * 2 + 1]);
	}
}
long long query(int a, int b, int k, int l, int r) {
	if (a <= l && r <= b) return seg[k];
	if (r <= a || b <= l) return 0;
	long long lc = query(a, b, k * 2, l, (l + r) >> 1);
	long long rc = query(a, b, k * 2 + 1, (l + r) >> 1, r);
	return max(lc, rc);
}
bool compare(int i, int j) {
	if(v[i] != v[j]) return v[i] < v[j];
	return i > j;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d %d", &r[i], &h[i]), v[i] = 1LL * r[i] * r[i] * h[i], p[i] = i;
	sort(p, p + n, compare);
	for (int i = 0; i < n; i++) {
		long long t = query(0, p[i], 1, 0, 131072);
		update(p[i], t + v[p[i]]);
	}
	long long ret = query(0, n, 1, 0, 131072);
	printf("%.12lf\n", ret * acos(-1));
	return 0;
}