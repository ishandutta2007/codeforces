#include <bits/stdc++.h>

using namespace std;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, k; scanf("%d %d", &n, &k);
		if (k % 3 == 0) {
			if (n % (k + 1) == k) printf("Alice\n");
			else printf("%s\n", (n % (k + 1)) % 3 == 0 ? "Bob" : "Alice");
		} else {
			printf("%s\n", n % 3 == 0 ? "Bob" : "Alice");
		}
	}
	return 0;
}