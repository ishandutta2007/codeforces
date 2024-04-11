#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 7;

int get_score(int n, int m) {
	if (2ll * m > n) return 500;
	else if (4ll * m > n) return 1000;
	else if (8ll * m > n) return 1500;
	else if (16ll * m > n) return 2000;
	else if (32ll * m > n) return 2500;
	else return 3000;
}

int n, a[7], b[7], c[7], cnt[7], score[7];

bool ok(int k) {
	for (int i = 1; i <= 5; i ++) c[i] = cnt[i];
	for (int i = 1; i <= 5; i ++) if (a[i] != -1) {
		if (b[i] != -1 && a[i] >= b[i]) c[i] += k;
	}
	for (int i = 1; i <= 5; i ++) score[i] = get_score(n + k, c[i]);
	int A = 0, B = 0;
	for (int i = 1; i <= 5; i ++) if (a[i] != -1) A += score[i] * (250 - a[i]) / 250;
	for (int i = 1; i <= 5; i ++) if (b[i] != -1) B += score[i] * (250 - b[i]) / 250;
	return A > B;
}

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= 5; i ++) {
		scanf("%d", &a[i]);
		if (a[i] != -1) cnt[i] ++;
	}
	for (int i = 1; i <= 5; i ++) {
		scanf("%d", &b[i]);
		if (b[i] != -1) cnt[i] ++;
	}
	for (int i = 3; i <= n; i ++) {
		for (int j = 1; j <= 5; j ++) {
			int x;
			scanf("%d", &x);
			if (x != -1) cnt[j] ++;
		}
	}
	for (int i = 0; i <= 12000; i ++) if (ok(i)) return printf("%d\n", i), 0;
	puts("-1");
	return 0;
}