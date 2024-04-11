#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n;
		long long k;
		scanf("%d %lld", &n, &k);
		long long a[n], b[n], c[n];
		for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
		long long x = *max_element(a, a + n);
		for (int i = 0; i < n; ++i) b[i] = x - a[i];
		x = *max_element(b, b + n);
		for (int i = 0; i < n; ++i) c[i] = x - b[i];
		if (k % 2) {
			printf("%lld", b[0]);
			for (int i = 1; i < n; ++i) printf(" %lld", b[i]);
			printf("\n");
		} else {
			printf("%lld", c[0]);
			for (int i = 1; i < n; ++i) printf(" %lld", c[i]);
			printf("\n");
		}
	}
	return 0;
}