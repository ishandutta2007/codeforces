#include <bits/stdc++.h>

using namespace std;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int a, b; scanf("%d %d", &a, &b);
		int sqSize = min(max(a, 2*b), min(max(b, 2*a), a + b));
		printf("%d\n", sqSize * sqSize);
	}
	return 0;
}