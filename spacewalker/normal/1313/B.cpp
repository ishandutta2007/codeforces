#include <bits/stdc++.h>

using namespace std;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, x, y; scanf("%d %d %d", &n, &x, &y);
		// find minimum
		printf("%d ", n - min(n - 1, max(0, (n - x) + (n - y) - 1)));	
		// i know how to maximize
		printf("%d\n", min(n, x + y - 1));	
	}
	return 0;
}