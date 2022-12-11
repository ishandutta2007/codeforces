#include <cstdio>
#include <string>
#define min(a, b) (a < b ? a : b)
typedef long long ll;
const ll md = 1e9 + 9;
ll step(ll a, ll st) {
	if (st == 0)
		return 1;
	if (st % 2)
		return (a * step(a, st - 1)) % md;
	ll q = step(a, st / 2);
	return (q * q) % md;
}
ll n, m, k, ans, kol;
int main() {
	// freopen("a.in", "r", stdin);
	// freopen("a.out", "w", stdout);
    scanf("%I64d%I64d%I64d", &n, &m, &k);

    if ((n + 1) / 2 >= m) {
    	printf("%I64d\n", m);
    	return 0;
    }

    kol = min(n - m, min(n / k, m / (k - 1)));
    n -= k * kol;
    m -= (k - 1) * kol;
    ans += (k - 1) * kol;
    if (m < k) {
    	printf("%I64d", ans + m);
    	return 0;
    }
    if (n == m) {
    	kol = n / k;
    	ans += n % k;
    	// printf("%I64d %I64d\n", ans, kol);
    	printf("%I64d\n", (step(2, kol + 1) * k + md + ans - 2 * k) % md);
    	return 0;
    }
    while (true);
    return 1;
}