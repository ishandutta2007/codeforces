#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int a[200010];
long long sum[200010], sss[2][200010];
int n;

long long solve(int L, int R, int CC, int PP) {
	long long ans = 0;
	for (int i = L; i <= R; i++) {
		int l = -1, r = n;
		while (l < r) {
			int mid = l + r + 1 >> 1, j = i + mid * 2;
			if (j >= R) {
				r = mid - 1;
				continue;
			}
			long long C = CC + sum[i] - sum[L - 1] + sss[i & 1][j] - sss[i & 1][i];
			long long P = PP + sum[R] - sum[j] + sss[(i & 1) ^ 1][j] - sss[(i & 1) ^ 1][i];
			if (C >= P) r = mid - 1;
			else l = mid;
		}
		ans += l + 1;
	}
	return ans;
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		if (n == 1) {
			printf("1\n");
			continue;
		}
		for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
		for (int i = 1; i <= n; i++) {
			sss[0][i] = sss[0][i - 1], sss[1][i] = sss[1][i - 1];
			sss[i & 1][i] += a[i];
		}
		long long ans = solve(1, n, 0, 0);
		if (n > 2) ans += solve(2, n, 0, a[1]) + solve(1, n - 1, a[n], 0);
		if (n > 3) ans += solve(2, n - 1, a[n], a[1]);
		for (int i = 0; i <= n; i++) {
			if (sum[i] > sum[n] - sum[i]) ans++;
		}
		printf("%I64d\n", ans % mod);
	}
	return 0;
}