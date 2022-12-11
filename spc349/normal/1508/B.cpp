#include <bits/stdc++.h>
using namespace std;

long long GetF(int n) {
	if (n == 0) return 1;
	n--;
	if (n > 60) n = 60;
	return 1ll << n;
}

void solve(int n, long long k, int base) {
	if (n == 0) {
		printf("\n");
		return ;
	}
	for (int i = 1; ; i++) {
		if (GetF(n - i) >= k) {
			for (int j = i; j >= 1; j--) printf("%d ", base + j);
			solve(n - i, k, base + i);
			return ;
		}
		k -= GetF(n - i);
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; long long k; scanf("%d%I64d", &n, &k);
		if (GetF(n) < k) {
			printf("-1\n");
			continue;
		}
		solve(n, k, 0);
	}
	return 0;
}