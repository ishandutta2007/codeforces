#include <cstdio>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
typedef long long ll;
int n, a[100009], b[100009], sb[100009], h[100009], p[100009]; ll dp[100009], seg[262156];
void update(int i, ll x) {
	i += 131072; seg[i] = x;
	while (i > 1) {
		i >>= 1;
		seg[i] = max(seg[i * 2], seg[i * 2 + 1]);
	}
}
ll query(int a, int b, int k, int l, int r) {
	if (a <= l && r <= b) return seg[k];
	if (r <= a || b <= l) return 0;
	ll lc = query(a, b, k * 2, l, (l + r) >> 1);
	ll rc = query(a, b, k * 2 + 1, (l + r) >> 1, r);
	return max(lc, rc);
}
bool compare(int i, int j) {
	if (b[i] != b[j]) return b[i] < b[j];
	return a[i] < a[j];
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d %d %d", &a[i], &b[i], &h[i]), p[i] = i, sb[i] = b[i];
	sort(p, p + n, compare);
	sort(sb, sb + n);
	for (int i = 0; i < n; i++) {
		int ptr = lower_bound(sb, sb + n, a[p[i]] + 1) - sb;
		dp[i] = query(ptr, n, 1, 0, 131072) + h[p[i]];
		update(i, dp[i]);
	}
	printf("%lld\n", *max_element(dp, dp + n));
	return 0;
}