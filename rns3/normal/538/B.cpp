#include <bits/stdc++.h>
using namespace std;

int main() {
	int m[20], e = 0, n, k, t;
	scanf("%d", &n);
	while (n) {
		m[++e] = 0;
		for (t = 1, k = n; k; k /= 10, t *= 10) if (k % 10) m[e] += t;
		n -= m[e];
	}
	printf("%d\n", e);
	for (int i = 1; i < e; i ++) printf("%d ", m[i]);
	printf("%d\n", m[e]);
	return 0;
}