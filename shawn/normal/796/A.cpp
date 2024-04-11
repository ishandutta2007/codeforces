#include <cstdio>
#include <algorithm>

using namespace std;

int rd() {
	int x = 0; char c = getchar();
	while (c > '9' || c < '0') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x;
}

int n, m, k, ans, a[110];

int main() {
	n = rd(), m = rd(), k = rd();
	ans = (n + 1) * 10;
	for (int i = 1; i <= n; i ++) a[i] = rd();
	for (int i = 1; i <= n; i ++) a[i] = !a[i] ? k + 1 : a[i];
	for (int i = 1; i <= n; i ++) if (a[i] <= k) ans = min(ans, abs(i - m) * 10);
	printf("%d", ans);
	return 0;
}