#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define M 400010

int a[M], n, prev[M];

int main() {
	int n, x;
	scanf("%d", &n);
	int mn = 2 * 1e9;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]); if (mn > a[i]) mn = a[i];
	}
	for (int i = 1; i <= n; i++) a[i+n] = a[i];

	LL ans = 1LL * mn * n;

	int last = 2 * n;
	for (int i = 2 * n; i; i--) {
		if (a[i] != mn) prev[i] = last; else last = i;
	}
	LL mx = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == mn) continue;
		if (mx < prev[i] - i) mx = prev[i] - i;
	}
	printf("%I64d\n", mx + ans);
}