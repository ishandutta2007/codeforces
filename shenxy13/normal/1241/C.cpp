#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
long long gcd(long long a, long long b) {
	if (b > a) return gcd(b, a);
	if (b == 0) return a;
	return gcd(b, a % b);
}
long long lcm(long long a, long long b) {
	return a * b / gcd(a, b);
}
int main() {
	ll q;
	scanf("%lld", &q);
	for (ll i = 0; i < q; ++i) {
		ll n;
		scanf("%lld", &n);
		ll a, b, x, y, k, p[n];
		for (ll j = 0; j < n; ++j) scanf("%lld", &p[j]);
		for (ll j = 0; j < n; ++j) p[j] /= 100;
		sort(p, p + n);
		scanf("%lld %lld %lld %lld %lld", &x, &a, &y, &b, &k);
		if (x > y) {
			swap(x, y);
			swap(a, b);
		}
		ll ptr = n - 1, ans = 0;
		for (ll j = 0; j < n / lcm(a, b); ++j) ans += p[ptr--] * (x + y);
		for (ll j = 0; j < n / b - n / lcm(a, b); ++j) ans += p[ptr--] * y;
		for (ll j = 0; j < n / a - n / lcm(a, b); ++j) ans += p[ptr--] * x;
		if (ans < k) printf("-1\n");
		else {
			ll l = 1, u = n, m = 0;
			while (l != u) {
				m = (l + u) / 2, ptr = n - 1;
				ans = 0;
				for (ll j = 0; j < m / lcm(a, b); ++j) ans += p[ptr--] * (x + y);
				for (ll j = 0; j < m / b - m / lcm(a, b); ++j) ans += p[ptr--] * y;
				for (ll j = 0; j < m / a - m / lcm(a, b); ++j) ans += p[ptr--] * x;
				if (ans < k) l = m + 1;
				else u = m;
			}
			printf("%lld\n", l);
		}
	}
	return 0;
}