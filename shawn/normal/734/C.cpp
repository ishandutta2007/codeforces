#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll read() {
	ll x = 0 , f = 1 , c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1 , c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48 , c = getchar();
	return x * f;
}

const ll maxn = 2e5 + 10;

ll n, m, k, x, s, a[maxn], b[maxn], c[maxn], d[maxn];
ll ans;

int main() {
	n = read(), m = read(), k = read();
	x = read(), s = read();
	for (ll i = 1; i <= m; i ++) a[i] = read();
	for (ll i = 1; i <= m; i ++) b[i] = read();
	for (ll i = 1; i <= k; i ++) c[i] = read();
	for (ll i = 1; i <= k; i ++) d[i] = read();
	ll pos = upper_bound(d + 1, d + k + 1, s) - d - 1;
	ans = (n - c[pos]) * x;
	for (ll i = 1; i <= m; i ++) {
		if (b[i] > s) continue;
		ll pos = upper_bound(d + 1, d + k + 1, s - b[i]) - d - 1;
		ans = min(ans, (n - c[pos]) * a[i]);
	}
	printf("%I64d\n", ans);
	return 0;
}