#include <bits/stdc++.h>
using namespace std;

#define N 202020

int n, a[N], b[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), b[a[i]] = i;
	long long ans = 0;
	for (int i = 1; i < n; i ++) ans += abs(b[i] - b[i+1]);
	printf("%I64d\n", ans);

	return 0;
}