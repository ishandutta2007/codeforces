#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;

int n, q;

int main() {
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &n);
		long long sum = 0;
		for (int i = 1;i <= n;i++) {
			long long x;
			scanf("%I64d", &x);
			sum += x;
		}
		printf("%I64d\n", (sum + 1ll * n - 1ll) / (long long)n);
	}
	return 0;
}