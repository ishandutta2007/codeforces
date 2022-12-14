#include <bits/stdc++.h>
using namespace std;

int n, s, x, y;

int main() {
	scanf("%d %d", &n, &s);
	while (n --) {
		scanf("%d", &x);
		y += 2 * s - 2 * x - 1;
	}
	printf("%d\n", max(y, 0));
	return 0;
}