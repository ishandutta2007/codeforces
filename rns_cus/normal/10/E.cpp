#include <bits/stdc++.h>
using namespace std;
#define N 404

int n, a[N];

int greedy(int m) {
	int rlt = 0;
	for (int i = 1; i <= n; i ++) rlt += m / a[i], m -= m / a[i] * a[i];
	return rlt;
}

int main() {
//	freopen("e.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	if (n <= 2) {
		puts("-1"); return 0;
	}
	int ans = 1 << 30;
	for (int i = n - 2; i && a[i] < ans; i --) {
		int m = a[i] - 1, mm = 0, step = 0;
		for (int j = i + 1; j <= n; j ++) {
			int k = m / a[j] + 1;
			mm += k * a[j], step += k;
			m -= (k - 1) * a[j];
			if (greedy(mm) > step) ans = min(ans, mm);
			mm -= a[j], step --;
		}
	}
	printf("%d\n", ans == (1 << 30) ? -1 : ans);
	return 0;
}