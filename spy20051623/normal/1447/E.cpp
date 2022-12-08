#include <bits/stdc++.h>

using namespace std;

int a[200005];

int dfs(int n, int p, int l, int r) {
	if (r - l <= 1) return r - l;
	int m = lower_bound(a + l, a + r, n + (1 << p)) - a;
	return max(dfs(n, p - 1, l, m) + (r != m), dfs(n + (1 << p), p - 1, m, r) + (m != l));
}

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	printf("%d\n", n - dfs(0, 30, 0, n));
	return 0;
}