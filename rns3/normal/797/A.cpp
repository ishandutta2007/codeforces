#include <bits/stdc++.h>
using namespace std;

int n, k, u[90], e;

int main() {
	scanf("%d %d", &n, &k);
	int m = n;
	for (int i = 2; i * i <= n;) {
		if (n % i == 0) {
			u[++e] = i;
			n /= i;
		}
		else i ++;
	}
	u[++e] = n;
	if (e < k) puts("-1");
	else {
		for (int i = 1; i < k; i ++) {
			printf("%d ", u[i]);
			m /= u[i];
		}
		printf("%d\n", m);
	}
	return 0;
}