#include <bits/stdc++.h>
using namespace std;

#define N 202020

int n;
int a[N], b[N];

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d %d", &a[i], &b[i]), b[i] += a[i];
	for (int i = 2; i <= n; i ++) b[i] = min(b[i], b[i-1] + 1);
	for (int i = n - 1; i >= 1; i --) b[i] = min(b[i], b[i+1] + 1);
	for (int i = 1; i <= n; i ++) if (b[i] < a[i]) {
		puts("-1");
		return 0;
	}
	long long ans = 0;
	for (int i = 1; i <= n; i ++) ans += b[i] - a[i];
	printf("%I64d\n", ans);
	for (int i = 1; i <= n; i ++) printf("%d ", b[i]);

	return 0;
}