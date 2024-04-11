#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n, sum = 0;
		scanf("%d", &n);
		int a[n];
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		for (int i = 0; i < n; ++i) sum += a[i];
		if (sum > 0) {
			sort(a, a + n);
			reverse(a, a + n);
			printf("YES\n%d", a[0]);
			for (int i = 1; i < n; ++i) printf(" %d", a[i]);
			printf("\n");
		} else if (sum < 0) {
			sort(a, a + n);
			printf("YES\n%d", a[0]);
			for (int i = 1; i < n; ++i) printf(" %d", a[i]);
			printf("\n");
		} else printf("NO\n");
	}
	return 0;
}