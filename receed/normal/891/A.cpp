#include <bits/stdc++.h>

using namespace std;

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}

int main() {
	int n, w = 0, g, mn = 1e8;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] == 1)
			w++;
	}
	if (w > 0) {
		printf("%d", n - w);
		return 0;
	}
	for (int i = 0; i < n; i++) {
		g = a[i];
		for (int j = i + 1; j < n; j++) {
			g = gcd(g, a[j]);
			if (g == 1)
				mn = min(mn, j - i);
		}
	}
	if (mn > n)
		printf("-1");
	else
		printf("%d\n", n - 1 + mn);
}