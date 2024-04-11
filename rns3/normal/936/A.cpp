#include <bits/stdc++.h>

using namespace std;



long long k, d, t;



int main() {

	//freopen("r.in", "r", stdin);

	scanf("%I64d %I64d %I64d", &k, &d, &t);

	long long h = ((k + d - 1) / d) * d;

	long long ans = 0;

	ans += ((2 * t) / (k + h)) * h;

	t *= 2, t %= (k + h);

	bool bad = 0;

	if (t <= 2 * k) {

		ans += t / 2;

		bad = t % 2;

	}

	else {

		ans += k;

		t -= 2 * k;

		ans += t;

	}

	printf("%I64d.%c", ans, bad ? '5' : '0');



	return 0;

}