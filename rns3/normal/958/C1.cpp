#include <bits/stdc++.h>

using namespace std;



#define N 101010



int n, mod, a[N];



long long s, t;



int main() {

	scanf("%d %d", &n, &mod);

	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), s += a[i];

	int ans = 0, now;

	for (int i = 1; i < n; i ++) {

		s -= a[i], t += a[i];

		now = (s % mod) + (t % mod);

		ans = max(now, ans);

	}

	printf("%d\n", ans);



	return 0;

}