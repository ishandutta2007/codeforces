#include <bits/stdc++.h>
using namespace std;

main() {
	int t, w, h, n, res;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &w, &h, &n);
		res = 1;
		while (w % 2 == 0) {
			res *= 2;
			w /= 2;
		}
		while (h % 2 == 0) {
			res *= 2;
			h /= 2;
		}
		if (res >= n)
			puts("YES");
		else
			puts("NO");
	}
}