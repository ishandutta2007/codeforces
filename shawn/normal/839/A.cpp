#include <bits/stdc++.h>

using namespace std;

int rd() {
	int x = 0; char c = getchar();
	while (c > '9' || c < '0') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x;
}

int a[110], n, k, tot;

int main() {
	n = rd(), k = rd();
	for (int i = 1; i <= n; i ++) a[i] = rd();
	for (int i = 1; i <= n; i ++) {
		if (a[i] >= 8) k -= 8, tot += a[i] - 8;
		else {
			int t = 8 - a[i];
			t = min(t, tot);
			tot -= t;
			k -= a[i] + t;
		}
		if (k <= 0) return printf("%d\n", i), 0;
	}
	puts("-1");
	return 0;
}