#include <bits/stdc++.h>
using namespace std;

int prime[20000010], vis[20000010], tot, f[20000010];

void precalc(int N) {
	for (int i = 2; i <= N; i++) {
		if (!vis[i]) prime[tot++] = i, f[i] = 1;
		for (int j = 0; j < tot && i * prime[j] <= N; j++) {
			vis[i * prime[j]] = 1, f[i * prime[j]] = f[i] + 1;
			if (i % prime[j] == 0) {
				f[i * prime[j]]--;
				break;
			}
		}
	}
}

int main() {
	precalc(20000000);
	int T; cin >> T;
	while (T--) {
		int c, d, x; cin >> c >> d >> x;
		long long ans = 0;
		for (int g = 1; g * g <= x; g++) {
			if (x % g) continue;
			if ((x / g + d) % c == 0) {
				int ab = (x / g + d) / c;
				ans += 1ll << f[ab];
			}
			g = x / g;
			if (g * g != x && (x / g + d) % c == 0) {
				int ab = (x / g + d) / c;
				ans += 1ll << f[ab];
			}
			g = x / g;
		}
		cout << ans << endl;
	}
	return 0;
}