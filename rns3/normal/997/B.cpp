#include <bits/stdc++.h>

using namespace std;



int a = 4, b = 9, c = 49;



int n;



bool check(long long x) {

	for (int aa = 0; aa < b; aa ++) for (int bb = 0; bb < c; bb ++) {

		long long y = x - 1ll * aa * a - 1ll * b * bb;

		if (y >= 0 && y % c == 0) {

			if (y / c <= (n - aa - bb)) return 1;

		}

	}

	return 0;

}



int main() {

	//freopen("r.in", "r", stdin);

	scanf("%d", &n);

	long long ans = 0;

	if (n < 20) {

		for (int i = 0; i <= c * n; i ++) ans += check(i);

		printf("%I64d\n", ans);

		return 0;

	}

	for (int i = 0; i <= 23; i ++) ans += check(i);

	ans += 1ll * (n - 17) * c - 23;

	for (long long i = 1ll * (n - 17) * c + 1; i <= 1ll * n * c; i ++) ans += check(i);

	printf("%I64d\n", ans);



	return 0;

}