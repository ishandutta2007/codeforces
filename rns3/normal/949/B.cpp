#include <bits/stdc++.h>
using namespace std;

long long func(long long m, long long n, bool bad) {
	if (bad == 0) {
		if (m % 2 == 1) return (m + 1) / 2;
		long long d = (n + 1) / 2;
		return d + func(m / 2, n - d, (2 * d - 1) == n);
	}
	else {
		if (m % 2 == 0) return m / 2;
		long long d = n / 2;
		return d + func((m + 1) / 2, n - d, (2 * d) == n);
	}
}

int main() {
	long long n, m;
	int q;
	scanf("%I64d %d", &n, &q);
	while (q --) {
		scanf("%I64d", &m);
		printf("%I64d\n", func(m, n, 0));
	}

	return 0;
}