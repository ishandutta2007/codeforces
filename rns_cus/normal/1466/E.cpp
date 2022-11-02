#include <bits/stdc++.h>
using namespace std;
#define N 500500

int n, cnt[N];
typedef long long ll;
ll tot[N], x[N];
const int mod = 1e9 + 7;

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
		scanf("%d", &n);
		ll sum = 0;
		for (int i = 1; i <= n; i ++) {
			scanf("%lld", &x[i]);
			for (int j = 0; j < 60; j ++) if (x[i] >> j & 1) cnt[j] ++, (tot[j] += x[i] % mod) >= mod ? tot[j] -= mod : 0;
		}
		ll ans = 0;
		for (int j = 0; j < 60; j ++) ans += (1ll << j) % mod * cnt[j] % mod * tot[j] % mod, sum += (1ll << j) % mod * cnt[j] % mod;
		ans = ans % mod * n % mod; sum %= mod;
		for (int j = 0; j < 60; j ++) ans += (1ll << j) % mod * cnt[j] % mod * cnt[j] % mod * sum % mod, tot[j] = 0;
		for (int j = 0; j < 60; j ++) cnt[j] = (1ll << j) % mod * cnt[j] % mod;
		for (int i = 1; i <= n; i ++) {
			ll s = 0;
			for (int j = 0; j < 60; j ++) if (x[i] >> j & 1) (s += cnt[j]) >= mod ? s -= mod : 0;
			for (int j = 0; j < 60; j ++) if (x[i] >> j & 1) (tot[j] += s) >= mod ? tot[j] -= mod : 0;

		}
		for (int j = 0; j < 60; j ++) ans -= 1ll * cnt[j] * tot[j] % mod, cnt[j] = tot[j] = 0;
		ans %= mod; if (ans < 0) ans += mod;
		printf("%lld\n", ans);
    }

    return 0;
}