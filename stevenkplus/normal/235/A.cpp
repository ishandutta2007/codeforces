#include <cstdio>

using namespace std;

typedef long long ll;

ll comp(ll n) {
	if (n == 1) {
		return 1;
	} else if (n == 2) {
		return 2;
	} else if (n == 3) {
		return 6;
	}
	if (n % 6 == 0) {
		return (n - 1) * (n - 2) * (n - 3);
	} else if (n % 2 == 0) {
		return (n) * (n - 1) * (n - 3);
	} else {
		return (n) * (n - 1) * (n - 2);
	}
}

int main() {
	int N;
	scanf("%d", &N);
	ll ans = comp(ll(N));
	printf("%I64d\n", ans);
	return 0;
}