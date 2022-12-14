#include <bits/stdc++.h>
using namespace std;

int T, n, m, pos[1 << 12], a[2000][12], mx[2000], id[2000], dp[13][1 << 12];

void upd(int &x, int y) {
	if (x < y) x = y;
}

int main() {
	scanf("%d", &T);
	for (int i = 0; i < 12; ++i) pos[1 << i] = i;
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) scanf("%d", a[j] + i);
		for (int i = 0; i < m; ++i)
			mx[i] = *max_element(a[i], a[i] + n), id[i] = i;
		sort(id, id + m, [](int x, int y) { return mx[x] > mx[y]; });
		memset(dp, 0, sizeof dp);
		for (int i = 0; i < min(n, m); ++i)
			for (int j = 0; j < 1 << n; ++j) {
				int val = 0;
				for (int k = 0; k < n; ++k) {
					int sum = 0;
					for (int x = j; x; x &= x - 1)
						sum += a[id[i]][(pos[x & -x] + k) % n];
					val = max(val, sum);
				}
				for (int t = (1 << n) - 1 - j, k = t;; k = k - 1 & t) {
					upd(dp[i + 1][k | j], dp[i][k] + val);
					if (!k) break;
				}
			}
		printf("%d\n", dp[min(n, m)][(1 << n) - 1]);
	}
	return 0;
}