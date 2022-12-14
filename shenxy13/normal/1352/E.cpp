#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n, ans = 0;
		scanf("%d", &n);
		int a[n], ps[n + 1];
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		ps[0] = 0;
		for (int i = 1; i <= n; ++i) ps[i] = ps[i - 1] + a[i - 1];
		bool hv[n + 1];
		fill_n(hv, n + 1, false);
		for (int i = 0; i < n; ++i) {
			for (int j = i + 2; j <= n; ++j) {
				if (ps[j] - ps[i] <= n) hv[ps[j] - ps[i]] = true;
			}
		}
		for (int i = 0; i < n; ++i) {
			if (hv[a[i]]) ++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}