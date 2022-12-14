#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n;
		scanf("%d", &n);
		long long a[n];
		for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
		long long sum = 0, xr = 0;
		for (int i = 0; i < n; ++i) sum += a[i], xr ^= a[i];
		printf("2\n%lld %lld\n", xr, sum + xr);
	}
	return 0;
}