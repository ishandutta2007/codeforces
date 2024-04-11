#include <cstdio>

int main() {
	int n, t, k, d;
	scanf("%d%d%d%d", &n, &t, &k, &d);
	n = (n + k - 1) / k;
	int ans1 = t * n;
	int t1 = t;
	int t2 = d + t;
	int have = n;
	int ans = 0;
	while (have > 0) {
		if (t1 < t2) {
			ans = t1;
			t1 += t;
		} else {
			ans = t2;
			t2 += t;
		}
		--have;
	}
	if (ans < ans1) {
		puts("YES");
	} else {
		puts("NO");
	}
}