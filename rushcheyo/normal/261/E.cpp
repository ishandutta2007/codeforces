#include <bits/stdc++.h>
using namespace std;

const int N = 3000005;
int l, r, p, n, a[N], pr[100], tot, dp[N];
bool f[N];

int main() {
	scanf("%d%d%d", &l, &r, &p);
	for (int i = 2, j; i < p; i++) {
		for (j = 2; j * j <= i && i % j; j++);
		if (j * j > i) pr[++tot] = i;
	}
	a[++n] = 1;
	for (int i = 1; i <= tot; i++)
		for (int j = 1, tmp = n; j <= tmp; j++)
			for (int x = a[j], up = r / pr[i]; x <= up; ) a[++n] = (x *= pr[i]);
	sort(a + 1, a + 1 + n);
	for (int i = 2; i <= n; i++) dp[i] = 1000;
	for (int i = 1; i < p; i++) {
		for (int j = 1, k = 1; j <= n; j++) {
			int x = a[j];
			if (1ll * x * i > r) break;
			x *= i;
			while (a[k] < x) k++;
			if (a[k] == x && dp[k] > dp[j] + 1) dp[k] = dp[j] + 1;
		}
		for (int j = 1; j <= n; j++) f[j] |= dp[j] + i <= p;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (f[i] && a[i] >= l && a[i] <= r) ans++;
	printf("%d\n", ans);
}