#include <bits/stdc++.h>
using namespace std;

int n, a[100100], b[100100], sum, ans;

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), sum += a[i];
	sort(a + 1, a + n + 1);
	int x = sum / n, y = sum % n;
	for (int i = 1; i <= n; i ++) b[i] = x + (i <= y ? 1 : 0);
	reverse(b + 1, b + n + 1);
	for (int i = 1; i <= n; i ++) ans += max(0, b[i] - a[i]);
    printf("%d\n", ans);
	return 0;
}