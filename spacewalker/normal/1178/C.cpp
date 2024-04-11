#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;

ll modexp(ll b, ll e) {
	if (e == 0) return 1;
	else return (e & 1 ? b : 1) * modexp(b * b % MOD, e / 2) % MOD;
}

int main() {
	int w, h; scanf("%d %d", &w, &h);
	printf("%lld\n", 4 * modexp(2, w + h - 2) % MOD);
	return 0;
}