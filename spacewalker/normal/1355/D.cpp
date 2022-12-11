#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, s; scanf("%d %d", &n, &s);
	if (n == 1) {
		if (s == 1) printf("NO\n");
		else printf("YES\n%d\n1\n", s);
		return 0;
	}
	if (s < 2 * n) printf("NO\n");
	else if (s == 2 * n) {
		printf("YES\n");
		for (int i = 0; i < n; ++i) printf("2 ");
		printf("\n1\n");
	}
	else {
		printf("YES\n");
		for (int i = 0; i < n - 1; ++i) printf("1 ");
		printf("%d\n", s - (n - 1));
		printf("%d\n", n);
	}
}