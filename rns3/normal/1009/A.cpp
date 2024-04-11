#include <bits/stdc++.h>

using namespace std;



#define N 1010



int a[N], b[N], n, m;



int main() {

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);

	for (int i = 1; i <= m; i ++) scanf("%d", &b[i]);

	int cur = 1;

	int ans = 0;

	for (int i = 1; i <= m; i ++) {

		while (cur <= n && a[cur] > b[i]) cur ++;

		if (cur > n) break;

		cur ++;

		ans ++;

	}

	printf("%d\n", ans);



	return 0;

}