#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
int main() {
	int n;
	scanf("%d", &n);
	int a[n + 1], p[n + 1], arr[61], pans[n + 1], sans[n + 1], ans = 0;
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	p[0] = 0;
	for (int i = 1; i <= n; ++i) p[i] = p[i - 1] + a[i];
	fill_n(arr, 61, 0);
	for (int i = 1; i <= n; ++i) {
		pans[i] = 0;
		pans[i] = max(pans[i], p[i - 1] - arr[30 + a[i]]);
		for (int j = 0; j < 30 + a[i]; ++j) arr[j] = p[i];
		for (int j = 30 + a[i]; j <= 60; ++j) arr[j] = min(arr[j], p[i]);
	}
	fill_n(arr, 61, p[n]);
	for (int i = n; i > 0; --i) {
		sans[i] = 0;
		sans[i] = max(sans[i], arr[30 + a[i]] - p[i]);
		for (int j = 0; j < 30 + a[i]; ++j) arr[j] = p[i - 1];
		for (int j = 30 + a[i]; j <= 60; ++j) arr[j] = max(arr[j], p[i - 1]);
	}
	for (int i = 1; i <= n; ++i) ans = max(ans, pans[i] + sans[i]);
	printf("%d", ans);
	return 0;
}