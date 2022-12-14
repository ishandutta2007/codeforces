#include <bits/stdc++.h>

using namespace std;



int n, m;



int main() {

	//freopen("r.in", "r", stdin);

	long long tot = 0;

	scanf("%d %d", &n, &m);

	for (int i = 1, d, x; i <= m; i ++) {

		scanf("%d %d", &x, &d);

		tot += 1ll * x * n;

		if (d > 0) tot += 1ll * d * n * (n - 1) / 2;

		else tot += 1ll * d * (long long)(1ll * n * n / 4);

	}

	double ans = (long double)tot / n;

	printf("%.10lf\n", ans);



	return 0;

}