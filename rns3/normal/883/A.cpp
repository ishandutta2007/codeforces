#include <bits/stdc++.h>
using namespace std;

#define N 101010

int n, m, a;

long long d, b[N];

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d %d %d %I64d", &n, &m, &a, &d);
	for (int i = 1; i <= m; i ++) scanf("%I64d", &b[i]);
	int cnt = 0;
	if (b[m] < 1ll * n * a) b[++m] = 1ll * n * a;
	for (int i = 1; i <= m; i ++) if (i == 1 || b[i] != b[i-1]) b[++cnt] = b[i];
	m = cnt;

	/*long long ans = 0, k, G, r, L;
	G = d / a + 1;
	long long t, MAXT = b[m];
	t = 0;
	int i = 1;
	while (i <= m) {
		while (i <= m && b[i] <= t) i ++;
		if (i > m) break;
		r = a - (t % a);
		L = (b[i] - t + r) % a;
		k = (b[i] - t + r) / a + 1;
		ans += k / G;
		k %= G;
		ans ++;
		if (k == 1) t = b[i];
		else t = b[i] + a - L;
		t += d;
	}*/

	long long t = 0, ans = 0, G = d / a + 1;
	int i = 1, j = 1;
	while (j <= m) {
		i = t / a + 1;
		if (i > n || b[j] <= 1ll * a * i) {
			t = b[j] + d;
			ans ++;
			while (j <= m && b[j] <= t) j ++;
			continue;
		}
		t = 1ll * a * i;
		int ii = b[j] / a;
		if (ii <= n && ii >= i + G) ans += (ii - i) / G, t += 1ll * (int)((ii - i) / G) * G * a;
		t += d;
		ans ++;
		while (j <= m && b[j] <= t) j ++;
	}

	printf("%I64d\n", ans);

	return 0;
}