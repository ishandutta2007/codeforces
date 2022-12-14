#include <bits/stdc++.h>
using namespace std;

#define N 101010

int a[N], b[N];

int n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d %d", &a[i], &b[i]);
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	long long ans = n;
	for (int i = 1; i <= n; i ++) ans += max(a[i], b[i]);
	printf("%I64d\n", ans);

	return 0;
}