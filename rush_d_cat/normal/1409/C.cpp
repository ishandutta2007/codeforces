#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int t, a[102];

int main() {
	scanf("%d", &t);
	while (t--){
		int n, x, y;
		scanf("%d%d%d", &n, &x, &y);
		if (x > y) swap(x, y);
		for (int d = 1; d <= y - x; d ++) {
			if ((y - x) % d == 0) {
				int c = (y - x) / d + 1;
				if (c <= n) {
					int a0 = x % d;
					if (a0 == 0) a0 += d;
					while ((y - a0) / d + 1 > n) a0 += d;
					for (int i = 0; i < n; i ++) {
						printf("%d ", a0 + i * d);
					}
					printf("\n");
					break; 
				}
			}
		}
	}
}