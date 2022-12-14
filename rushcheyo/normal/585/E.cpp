#include <bits/stdc++.h>
using namespace std;

const int P = 1000000007;
int pw[500005], p[664580], tot, cnt[10000001];
int8_t mu[10000001];
bitset<10000001> np;

int main() {
	mu[1] = 1;
	for (int i = 2; i <= 10000000; ++i) {
		if (!np[i]) p[++tot] = i, mu[i] = -1;
		for (int j = 1; j <= tot && p[j] * i <= 10000000; ++j) {
			np[p[j] * i] = true;
			if (i % p[j] == 0) break;
			mu[p[j] * i] = -mu[i];
		}
	}
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = pw[0] = 1, x; i <= n; ++i)
		scanf("%d", &x), ans -= x == 1, ++cnt[x], pw[i] = 2 * pw[i - 1] % P;
	for (int i = 1; i <= tot; ++i)
		for (int j = 10000000 / p[i]; j; --j)
			cnt[j] += cnt[j * p[i]];
	for (int d = 1; d <= 10000000; ++d)
		if (mu[d] && cnt[d]) ans = (ans + mu[d] * (1ll * pw[cnt[d]] * cnt[d] - (pw[cnt[d]] - 1ll) * n)) % P;
	printf("%d\n", (ans + P) % P);
	return 0;
}