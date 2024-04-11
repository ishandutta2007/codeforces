#include <cstdio>

using namespace std;

typedef long long ll;

ll powmod(ll base, int exp, int mod) {
	if (exp == 0) {
		return 1ll;
	}
	ll sq = powmod(base, exp / 2, mod);
	(sq *= sq) %= mod;
	if (exp % 2 == 1) {
		(sq *= base) %= mod;
	}
	return sq;
}

int f(int n, int m) {
	ll sum = powmod(3, n, m);
	((sum -= 1) += m) %= m;
	return int(sum);
}

int N, M;
int main() {
	scanf("%d %d", &N, &M);
	int ans = f(N, M);
	printf("%d\n", ans);
	return 0;
}