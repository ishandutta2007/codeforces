#include <bits/stdc++.h>
using namespace std;

const int P = 1000000007, N = 1000005;
int n, m, k, a[N], s[N], pw[N], ans;

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = pw[0] = 1; i <= n; i++) pw[i] = pw[i - 1] * 2 % P;
	for (int u, v; m--;) {
		scanf("%d%d", &u, &v);
		if (u + 1 == v) continue;
		if (v - u != k + 1) return puts("0"), 0;
		a[u] = 1;
	}
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	ans = !s[n];
	for (int i = 1; i + k + 1 <= n; i++) {
		if (s[n] - s[i] > 0) continue;
		if (i - k > 1 && s[i - k - 1] > 0) {
			if (a[i]) return puts("0"), 0;
			continue;
		}
		int cnt = i - 1 - s[i - 1];
		if (i - k > 1) cnt -= i - k - 1;
		ans = (ans + pw[cnt]) % P;
	}
	printf("%d\n", ans);
}