#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n, x;
		scanf("%d %d", &n, &x);
		int a[n];
		for (int j = 0; j < n; ++j) scanf("%d", &a[j]);
		sort(a, a + n);
		if (a[n - 1] <= x) printf("%d\n", (x - 1) / a[n - 1] + 1);
		else {
			int ptr = lower_bound(a, a + n, x) - a;
			if (ptr == -1 || a[ptr] != x) printf("2\n");
			else printf("1\n");
		}
	}
	return 0;
}