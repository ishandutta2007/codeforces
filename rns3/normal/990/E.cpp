#include <bits/stdc++.h>

using namespace std;



const long long INF = 1ll << 60;

#define N 1010101



int n, k, a[N], m;



int q[N], prv[N];

bool bad[N];



long long calc(int k, int gop) {

	int now = 0;

	int rlt = 0;

	int old;

	while (now < n) {

		old = now;

		now = prv[now];

		now += k;

		if (old >= now) return INF;

		rlt ++;

	}

	return 1ll * gop * rlt;

}



int main() {

	//freopen("r.in", "r", stdin);

	scanf("%d %d %d", &n, &m, &k);

	for (int i = 1, x; i <= m; i ++) scanf("%d", &x), bad[x] = 1;

	for (int i = 1; i <= k; i ++) scanf("%d", &a[i]);

	int last = 0;

	for (int i = 0; i < n; i ++) {

		if (!bad[i]) last = i;

		prv[i] = last;

	}

	if (bad[0]) {

		puts("-1");

		return 0;

	}

	long long ans = INF;

	for (int i = 1; i <= k; i ++) ans = min(ans, calc(i, a[i]));

	if (ans < INF) printf("%I64d\n", ans);

	else puts("-1");



	return 0;

}