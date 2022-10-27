#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
	cin >> n >> k;
	if (k >= 4 || k == 1) return !printf("-1\n"); 
	if (k == 2) {
		if (n <= 4) return !printf("-1\n");
		printf("%d\n", n - 1);
		for (int i = 1; i < n; i ++) {
			printf("%d %d\n", i, i + 1);
		}
	}
	if (k == 3) {
		if (n <= 3) return !printf("-1\n");
		printf("%d\n", n - 1);
		printf("1 2\n2 3\n");
		for (int i = 4; i <= n; i ++) {
			printf("%d %d\n", 3,i);
		}
	}
	
}