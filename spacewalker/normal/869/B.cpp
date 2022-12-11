#include <cstdio>

typedef long long ll;

void answer(int i) {
	printf("%d\n", i);
}

int main() {
	ll a, b; scanf("%I64d %I64d", &a, &b);
	if (a == 0) {
		if (b <= 1) {
			answer(1);
		} else if (b == 2) {
			answer(2);
		} else if (b == 3) {
			answer(6);
		} else if (b == 4) {
			answer(4);
		} else {
			answer(0);
		}
		return 0;
	}
	if (b - a >= 5) {
		answer(0);
	} else {
		ll ans = 1;
		for (ll i = a + 1; i <= b; ++i) {
			ans = (ans * i) % 10;
		}
		answer(ans);
	}
	return 0;
}