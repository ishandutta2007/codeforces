#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const long long mod = 1000000007;
long long mp(long long b, long long e) {
	if (e == 0) return 1;
	long long a = mp(b, e >> 1);
	a = a * a % mod;
	if (e & 1) a = a * b % mod;
	return a;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string S;
	cin >> S;
	long long ans = 0, fac[200001], inv[200001];
	int x = 0, y = 0;
	fac[0] = inv[0] = 1;
	for (int i = 1; i <= 200000; ++i) fac[i] = i * fac[i - 1] % mod;
	for (int i = 1; i <= 200000; ++i) inv[i] = mp(fac[i], mod - 2);
	for (char c: S) {
		if (c == ')') ++y;
	}
	for (char c: S) {
		if (c == '(' && y > 0) {
			ans = (ans + fac[x + y] * inv[x + 1] % mod * inv[y - 1] % mod) % mod;
			++x;
		} else if (c == ')') --y;
	}
	printf("%lld", ans);
	return 0;
}