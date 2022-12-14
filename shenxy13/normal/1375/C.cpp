#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n;
		scanf("%d", &n);
		int a[n + 2];
		a[0] = n + 1, a[n + 1] = 0;
		for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
		int pmin[n + 2], smax[n + 2];
		pmin[0] = a[0];
		for (int i = 1; i < n + 2; ++i) pmin[i] = min(pmin[i - 1], a[i]);
		smax[n + 1] = a[n + 1];
		for (int i = n; i >= 0; --i) smax[i] = max(smax[i + 1], a[i]);
		pmin[0] = 0, smax[n + 1] = n + 1;
		for (int i = 1; i < n + 2; ++i) pmin[i] = max(pmin[i - 1], pmin[i]);
		for (int i = n; i >= 0; --i) smax[i] = min(smax[i + 1], smax[i]);
		bool can = false;
		for (int i = 1; i <= n; ++i) {
			if (a[i] > pmin[i - 1] && a[i] < smax[i + 1]) can = true;
		}
		printf(can ? "YES\n" : "NO\n");
	}
	return 0;
}