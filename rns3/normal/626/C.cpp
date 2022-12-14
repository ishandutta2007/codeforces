#include <bits/stdc++.h>
using namespace std;

int a, b;

int main() {
	scanf("%d %d", &a, &b);
	int ans = max(max(2 * a, 3 * b), 0), rlt;
	while (1) {
		rlt = (ans / 2) + (ans / 3) - (ans / 6);
		if (rlt < a + b) ans ++;
		else break;
	}
	printf("%d\n", ans);
	return 0;
}