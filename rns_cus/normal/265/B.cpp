#include <bits/stdc++.h>
using namespace std;
#define N 100100

int n, a[N];

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	int ans = n + (n - 1);
	for (int i = 1; i <= n; i ++) ans += abs(a[i] - a[i-1]);
	printf("%d\n", ans);
	return 0;
}