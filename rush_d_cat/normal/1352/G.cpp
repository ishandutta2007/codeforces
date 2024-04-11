#include <bits/stdc++.h>
using namespace std;
int t, n;
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		if (n <= 3) {
			printf("-1\n");
			continue;
		}
		int rem = n, x = 0;
		while (rem > 0) {
			if (rem == 1) {
				printf("%d", x + 1); break;
			} 
			if (rem == 6) {
				printf("%d %d %d %d %d %d", x + 2, x + 5, x + 1, x + 3, x + 6, x + 4); break;
			}
			if (rem == 7) {
				printf("%d %d %d %d %d %d %d", x + 2, x + 5, x + 1, x + 3, x + 6, x + 4, x + 7); break;
			}
			printf("%d %d %d %d ", x + 2, x + 4, x + 1, x + 3);
			rem -= 4;
			x += 4;
		} 
		printf("\n");
	}
}
/*
1 3 5 2 4

2 4 1 3 5
2 5 1 3 6 4
2 5 1 3 6 4 7
2 4 1 3 6 8 5 7
*/