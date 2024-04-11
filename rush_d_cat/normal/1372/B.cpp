#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		int ans = 1e9, A, B;
		for (int i = 1; i * i <= n; i ++) {
			if (n % i == 0) {

				{
					int x = i, y = n - i;
					if (x == 0 || y == 0) continue;
					if (x % y == 0 || y % x == 0) {
						if (max(x, y) < ans) {
							ans = max(x, y);
							A = x, B = y;
						}
					}
				}

				{
					int x = n/i, y = n - x;
					if (x == 0 || y == 0) continue;
					if (x % y == 0 || y % x == 0) {
						if (max(x, y) < ans) {
							ans = max(x, y);
							A = x, B = y;
						}
					}
				}
			}
		}
		printf("%d %d\n", A, B);
	}
}