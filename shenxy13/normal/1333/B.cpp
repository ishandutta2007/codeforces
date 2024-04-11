#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n;
		scanf("%d", &n);
		int a[n], b[n], mn = 0, mx = 0;
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
		for (int i = 0; i < n; ++i) {
			if ((b[i] < a[i] && mn >= 0) || (b[i] > a[i] && mx <= 0)) {
				printf("NO\n");
				goto hell;
			} else mn = min(mn, a[i]), mx = max(mx, a[i]);
		}
		printf("YES\n");
		hell:;
	}
}