#include <bits/stdc++.h>
using namespace std;
int t, n;
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		if (n <= 30) {
			printf("NO\n");
		} else {
			printf("YES\n");
			int x = n - 6 - 10 - 14;
			if (x != 6 && x != 10 && x != 14) {
				printf("%d %d %d %d\n", 6, 10, 14, x);
			} else {
				-- x;
				printf("%d %d %d %d\n", 6, 10, 15, x);
			}
		}
	}
}

/*
2 3 5 7
6,10,14,15
*/