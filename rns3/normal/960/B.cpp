#include <bits/stdc++.h>

using namespace std;



#define N 1010



int a[N], b[N], n;



#define M 2010101



int cnt[M];



int main() {

	//freopen("r.in", "r", stdin);

	int m, mm;

	scanf("%d %d %d", &n, &m, &mm);

	m += mm;

	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);

	for (int i = 1; i <= n; i ++) scanf("%d", &b[i]), cnt[abs(a[i]-b[i])] ++;

	int cur = M - 1;

	for (int step = 0; step < m; step ++) {

		while (cur >= 0 && !cnt[cur]) cur --;

		cnt[cur] --;

		int d = -1;

		if (cur == 0) d = 1;

		cnt[cur+d] ++;

		if (cur == 0) cur = 1;

	}

	long long ans = 0;

	for (int i = 1; i < M; i ++) ans += 1ll * cnt[i] * i * i;

	printf("%I64d\n", ans);



	return 0;

}