#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, h;
	scanf("%d %d", &n, &h);
	for (int i = 1; i < n; i ++) {
		double ans = sqrt((1.0 * i) / n) * h;
		printf("%f", ans);
		if (i < n - 1) printf(" ");
	}

	return 0;
}