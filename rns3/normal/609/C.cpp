#include <bits/stdc++.h>
using namespace std;
#define M 100010
int a[M], n;
int main() {
//	freopen("C.in", "r", stdin);
	scanf("%d", &n);
	int sum = 0;
	for (int i = 0; i < n; i++) scanf("%d", a + i), sum += a[i];
	int m = sum / n, t = sum % n;
	sort(a, a + n); reverse(a, a + n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int x = m; if (t) x++, t--;
		if (a[i] <= x) break; ans += (a[i] - x);
	}
	printf("%d\n", ans);
}