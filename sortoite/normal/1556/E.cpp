#include <bits/stdc++.h>

using namespace std;
const int NN = 1e5 + 10;
long long mn[NN][20], mx[NN][20], a[NN], b[NN], sum[NN];

long long MIN(int L, int R) {
	int t = 31 - __builtin_clz(R - L + 1);
	return min(mn[L][t], mn[R - (1 << t) + 1][t]);
}

long long MAX(int L, int R) {
	int t = 31 - __builtin_clz(R - L + 1);
	return max(mx[L][t], mx[R - (1 << t) + 1][t]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
#endif
	int n, q; cin >> n >> q;
	for(int i = 1; i <= n; i ++) {
		scanf("%I64d", a + i);
	}
	for(int i = 1; i <= n; i ++) {
		scanf("%I64d", b + i);
		sum[i] = sum[i - 1] + a[i] - b[i];
	}
	for(int j = 0; j < 20; j ++) {
		for(int i = 0; i <= n; i ++) {
			if(j == 0) mn[i][j] = mx[i][j] = sum[i];
			else {
				mn[i][j] = min(mn[i][j - 1], mn[min(i + (1 << j - 1), n)][j - 1]);
				mx[i][j] = max(mx[i][j - 1], mx[min(i + (1 << j - 1), n)][j - 1]);
			}
		}
	}
	for(int L, R; q --; ) {
		scanf("%d %d", &L, &R);
		if(MAX(L, R) > sum[R] || sum[R] != sum[L - 1]) {
			puts("-1");
		}
		else {
			printf("%I64d\n", sum[R] - MIN(L, R));
		}
	}
	return 0;
}