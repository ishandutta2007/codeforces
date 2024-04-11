#include <bits/stdc++.h>

const int mod = 1e9 + 7;

const int N = 505;

int n, ans, a[N], cnt[N], pwr[N];

int main() {
	scanf("%d", &n); pwr[0] = 1;
	for (int i = 1; i <= n; i++) {
		pwr[i] = 2 * pwr[i - 1] % mod;
		scanf("%d", &a[i]);
		if (a[i] != -1) { cnt[a[i]]++; }
	}
	ans = pwr[n - 1] - 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] == -1) { ans = (ans + mod - pwr[cnt[i]] + 1) % mod; }
	}
	printf("%d\n", ans);
	return 0;
}