#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
int k;
i64 n, m, a[10000];

i64 gcd(i64 a, i64 b) {
	return !b ? a : gcd(b, a % b);
}
void exgcd(i64 a, i64 b, i64 &x, i64 &y) {
	if (!b) x = 1, y = 0;
	else exgcd(b, a % b, y, x), y -= a / b * x;
}
i64 mul(i64 a, i64 b, i64 p) {
	a = (a % p + p) % p;
	return (a * b - (i64)((long double)a * b / p) * p + p) % p;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	i64 lcm = 1, X = 1;
	for (int i = 0; i < k; i++) {
		cin >> a[i];
		if (lcm / gcd(a[i], lcm)> n / a[i] + 1) return puts("NO"), 0;
		i64 x, y, z = ((-X - i) % a[i] + a[i]) % a[i];
		exgcd(lcm, a[i], x, y);
		i64 g = gcd(lcm, a[i]);
		if (z % g) return puts("NO"), 0;
		x = mul(x, z / g, a[i] / g);
		X += x * lcm;
		lcm = lcm / gcd(a[i], lcm) * a[i];
	}
	if (lcm > n || X + k - 1 > m) return puts("NO"), 0;
	for (int i = 0; i < k; i++)
		if (gcd(lcm, X + i) != a[i]) return puts("NO"), 0;
	return puts("YES"), 0;
}