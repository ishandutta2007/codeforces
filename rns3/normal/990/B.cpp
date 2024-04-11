#include <bits/stdc++.h>

using namespace std;



#define N 1010101



int a[N], cnt[N], k, n;



int main() {

	//freopen("r.in", "r", stdin);

	scanf("%d %d", &n, &k);

	for (int i = 1, x; i <= n; i ++) {

		scanf("%d", &x);

		cnt[x] ++;

	}

	int last = N + k;

	for (int i = N - 1; i >= 0; i --) if (cnt[i]) {

		if (last <= i + k) cnt[i] = 0;

		last = i;

	}

	int ans = 0;

	for (int i = 0; i < N; i ++) ans += cnt[i];

	printf("%d\n", ans);



	return 0;

}