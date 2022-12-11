#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
typedef long long ll;

int main() {
	ll n, m, a, b; scanf("%lld %lld %lld %lld", &n, &m, &a, &b);
	if (n % m == 0) {
		printf("0\n");
		return 0;
	} else {
		ll lm = n/m * m;
		ll gm = (n/m + 1) * m;
		// printf("LM GM %lld %lld\n", lm, gm);
		printf("%lld\n", min((n-lm) * b, (gm - n) * a));
	}
	return 0;
}