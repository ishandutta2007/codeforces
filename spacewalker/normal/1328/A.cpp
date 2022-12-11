#include <bits/stdc++.h>

using namespace std;

// YEET

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int a, b; scanf("%d %d", &a, &b);
		int ans = a % b;
		if (ans == 0) printf("0\n");
		else printf("%d\n", b - ans);
	}
	return 0;
}